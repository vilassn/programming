import requests

def download_file(url, local_path):
    try:
        response = requests.get(url)
        if response.status_code == 200:
            with open(local_path, 'wb') as file:
                file.write(response.content)
            print(f"File downloaded successfully and saved at: {local_path}")
        else:
            print(f"Failed to download file. Status code: {response.status_code}")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    url_to_download = "http://google.com/favicon.ico"  # Replace with the actual URL
    local_file_path = "C:\\favicon.ico"  # Replace with the desired local file path

    download_file(url_to_download, local_file_path)
    print(local_file_path.title())
