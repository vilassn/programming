import xml.etree.ElementTree as ET
import os
import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QFileDialog, QTextEdit


class App(QtWidgets.QWidget):
    def __init__(self):
        super().__init__()
        self.title = 'XML Comparison'
        self.left = 100
        self.top = 100
        self.width = 800
        self.height = 600
        self.file1 = None
        self.file2 = None
        self.initUI()

    def initUI(self):
        self.setWindowTitle(self.title)
        self.setGeometry(self.left, self.top, self.width, self.height)

        # Calculate the center position
        screen = QtWidgets.QDesktopWidget().screenGeometry()
        self.left = (screen.width() - self.width) // 2
        self.top = (screen.height() - self.height) // 2
        self.move(self.left, self.top)

        button1 = QtWidgets.QPushButton('Select XML File 1', self)
        button1.setToolTip('Select the first XML file for comparison')
        button1.move(50, 50)
        button1.clicked.connect(lambda: self.openFileNameDialog(1))

        self.label1 = QtWidgets.QLabel(self)
        self.label1.move(50, 80)
        self.label1.setText("No file selected")

        button2 = QtWidgets.QPushButton('Select XML File 2', self)
        button2.setToolTip('Select the second XML file for comparison')
        button2.move(300, 50)
        button2.clicked.connect(lambda: self.openFileNameDialog(2))

        self.label2 = QtWidgets.QLabel(self)
        self.label2.move(300, 80)
        self.label2.setText("No file selected")

        compare_button = QtWidgets.QPushButton('Compare Files', self)
        compare_button.move(250, 120)
        compare_button.clicked.connect(self.compare_files)

        self.textview = QTextEdit(self)
        self.textview.move(50, 160)
        self.textview.resize(500, 200)

        self.show()

    def openFileNameDialog(self, file_num):
        options = QFileDialog.Options()
        options |= QFileDialog.ReadOnly
        file, _ = QFileDialog.getOpenFileName(self, "Select XML File", "",
                                              "XML Files (*.xml)", options=options)
        if file:
            if file_num == 1:
                self.file1 = file
                self.label1.setText(os.path.basename(file))
            else:
                self.file2 = file
                self.label2.setText(os.path.basename(file))

    def compare_files(self):
        if self.file1 and self.file2:
            files = [self.file1, self.file2]
            result = main(files)
            self.textview.setText(result)
        else:
            self.textview.setText("Both files must be selected for comparison.")


def main(files):
    output = ""
    tag_name = "volume"
    file_list = get_files_from_args(files)
    map_list = []

    for file in file_list:
        message = f"Checking duplicate package in file ===> {os.path.abspath(file)}"
        output += message + "\n"
        pkg_map = check_duplicate_pkg_and_get_map(file, tag_name)
        map_list.append(pkg_map)

    if len(map_list) == 2:
        message = "Comparing both files ===>"
        output += message + "\n"
        result = print_differences(map_list[0], map_list[1])
        output += result
    else:
        output += "For comparison, two XML file paths should be given"

    return output

def get_files_from_args(args):
    file_list = []
    for arg in args:
        if os.path.exists(arg) and os.path.isfile(arg) and arg.lower().endswith(".xml"):
            file_list.append(arg)

    return file_list


def check_duplicate_pkg_and_get_map(xml_file, tag_name):
    duplicate_found = False
    packages = {}
    output = ""

    elements = extract_elements(xml_file, tag_name)
    for i in range(0, len(elements), 2):
        ele = elements[i]
        node_name = ele.tag
        pkg_name = ele.text.strip()

        ele1 = elements[i + 1]
        node_attribute = ele1.tag
        pkg_attribute = ele1.text.strip()

        if node_name == "name" and node_attribute == "attribute":
            if pkg_name in packages:
                duplicate_found = True
                output += f"Found duplicate... {pkg_name} : {packages[pkg_name]}\n"
            packages[pkg_name] = pkg_attribute

    if not duplicate_found:
        output += "No duplicate package found...\n"

    return packages, output


def extract_elements(xml_file, tag_name):
    elements = []
    try:
        # Parse XML file
        tree = ET.parse(xml_file)
        root = tree.getroot()

        # Get elements with the specified tag
        for element in root.iter(tag_name):
            for child_element in element:
                elements.append(child_element)

    except Exception as e:
        print("Error while parsing XML:", e)

    return elements


def print_differences(map1, map2):
    difference_found = False

    for pkg_name, attribute in map1.items():
        if pkg_name not in map2:
            difference_found = True
            print(f"Exists only in file 1... {pkg_name} : {attribute}")

    print()

    for pkg_name, attribute in map2.items():
        if pkg_name not in map1:
            difference_found = True
            print(f"Exists only in file 2... {pkg_name} : {attribute}")

    print()

    for pkg_name in map1.keys():
        if pkg_name in map2:
            attribute1 = map1[pkg_name]
            attribute2 = map2[pkg_name]
            if attribute1 != attribute2:
                difference_found = True
                print(f"Difference found for key: {pkg_name}")
                print(f"Attribute in file 1: {attribute1}")
                print(f"Attribute in file 2: {attribute2}")
                print()

    if not difference_found:
        print("No difference found...")



if __name__ == '__main__':
    app = QtWidgets.QApplication(sys.argv)
    ex = App()
    sys.exit(app.exec_())
