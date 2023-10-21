import re

# Input string
input_string = "macd(1,2,3)"

# Define a regular expression pattern to match any keyword and values inside parentheses
pattern = r"(\w+)\((\d+),(\d+),(\d+)\)"

# Find the keyword and values using the pattern
matches = re.search(pattern, input_string)

if matches:
    keyword = matches.group(1)
    values = matches.groups()[1:]  # Extract values from the second group onward

    value1 = int(values[0])
    value2 = int(values[1])
    value3 = int(values[2])

    # Print the extracted keyword and values
    print("Keyword:", keyword)
    print("Value 1:", value1)
    print("Value 2:", value2)
    print("Value 3:", value3)
else:
    print("No match found")
