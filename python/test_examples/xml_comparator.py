import xml.etree.ElementTree as ET
import os
import sys


def main():
    tag_name = "volume"  # Replace with the actual tag name you want to compare

    if len(sys.argv) < 2:
        print("Usage:\npython volume_list_check.py <xml_file1_path> <xml_file2_path>")
        return

    file_list = get_files_from_args(sys.argv[1:])

    # Check duplicate package entries in volume list
    map_list = []
    for file in file_list:
        print("Checking duplicate package in file ===> " + os.path.abspath(file))
        pkg_map = check_duplicate_pkg_and_get_map(file, tag_name)
        map_list.append(pkg_map)

    # Compare maps and find the difference
    if len(map_list) == 2:
        print("Comparing both files ===> ")
        print_differences(map_list[0], map_list[1])
    else:
        print("For comparison, two xml file paths should be given")


def get_files_from_args(args):
    file_list = []
    for arg in args:
        if os.path.exists(arg):
            if os.path.isfile(arg) and arg.lower().endswith(".xml"):
                file_list.append(arg)
            else:
                print("Not an XML file..." + os.path.abspath(arg))
        else:
            print("File does not exist..." + os.path.abspath(arg))

    return file_list


def check_duplicate_pkg_and_get_map(xml_file, tag_name):
    duplicate_found = False
    packages = {}

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
                print(f"Found duplicate... {pkg_name} : {packages[pkg_name]}")
            packages[pkg_name] = pkg_attribute

    if not duplicate_found:
        print("No duplicate package found...")

    print()
    return packages


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


if __name__ == "__main__":
    main()
