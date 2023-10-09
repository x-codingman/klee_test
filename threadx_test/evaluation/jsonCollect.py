import os
import re
directory = "/home/klee/threadx/symbolic_execution/test-info-output"

def list_json_files(directory):
    json_files = []

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".json"):
                json_files.append(os.path.join(root, file))

    return json_files

def extract_api_info(file_path):
    pattern = r"/description_(.+?)_(\d+)_(\w+)\.json$"
    match = re.search(pattern, file_path)
    if match:
        return match.group(1), match.group(3)
    else:
        return None, None

def main():
    
    json_files = list_json_files(directory)

    with open("jsonFilesPath.txt", "w") as f:
        for file_path in json_files:
            api_name, mo_name = extract_api_info(file_path)
            f.write(file_path + '\n')
            f.write(api_name + '\n')
            f.write(mo_name + '\n')

    print(f"All .json files have been recorded to jsonFilesPath.txt.")

if __name__ == "__main__":
    main()
