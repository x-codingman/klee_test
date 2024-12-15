import os
import re

def find_under_lines(root_folder):
    for dirpath, dirnames, filenames in os.walk(root_folder):
        if 'test_info.txt' in filenames:
            file_path = os.path.join(dirpath, 'test_info.txt')
            try:
                with open(file_path, 'r', encoding='utf-8') as file:
                    for line in file:
                            print(f'Found in {file_path}:\n{line.strip()}\n')
            except Exception as e:
                print(f'Error reading {file_path}: {e}')

# Replace 'your_folder_path' with the path to your main folder
root_folder = '/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/test-info-output'
find_under_lines(root_folder)