import os
directory = "/home/klee/threadx/symbolic_execution/test-info-output"

def list_json_files(directory):
    json_files = []

    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.endswith(".json"):
                json_files.append(os.path.join(root, file))

    return json_files

def main():
    
    json_files = list_json_files(directory)

    with open("jsonFilesPath.txt", "w") as f:
        for file_path in json_files:
            f.write(file_path + '\n')

    print(f"All .json files have been recorded to jsonFilesPath.txt.")

if __name__ == "__main__":
    main()
