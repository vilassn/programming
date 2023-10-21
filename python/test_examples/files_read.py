import os
import csv
import time

# Specify the root folder path
root_folder_path = r"C:\Users\Admin\wave\appdata\datafeed\historical"


# Function to read and print content of CSV files recursively
def read_csv_files_recursively(folder_path):
    start_time = time.time()
    total_files = 0
    for root, _, filenames in os.walk(folder_path):
        for filename in filenames:
            if filename.endswith(".csv"):
                file_path = os.path.join(root, filename)
                # print(f"Reading contents of {file_path}:")
                print(filename)
                total_files += 1

                with open(file_path, "r", newline="") as csvfile:
                    csv_reader = csv.reader(csvfile)
                    for row in csv_reader:
                        a = 5 #+ len(row)

                # print("\n")

    end_time = time.time()
    total_time = end_time - start_time
    print(f"Total time required: {total_time:.6f} seconds")
    print(total_files)


# Call the function to read CSV files recursively in the specified root folder
read_csv_files_recursively(root_folder_path)
