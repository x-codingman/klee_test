import shlex
import subprocess
import concurrent.futures
import os
import json


output_dir = "/home/klee/tizenrt/symbolic_execution/output/"
test_files_dir = "/home/klee/tizenrt/symbolic_execution/build/test_files/test_files/"
test_info_dir = "/home/klee/tizenrt/symbolic_execution/test-info-output/"


func_names = []

for dirpath, dirnames, filenames in os.walk(test_files_dir):
    for file in filenames:
        new_name = file.replace(".test.bc", "")
        func_names.append(new_name)


# for func in funcs_delete:

#     command_clean = [
#         "rm", 
#         "/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/"+shlex.quote(func)+".c"
#     ]
#     print("Executing command: " + " ".join(command_clean))
#     subprocess.run(command_clean, check=True)
def run_command(func_name):

    command_clean_dir = [
        "rm", 
        "-rf", 
        output_dir+shlex.quote(func_name)
    ]
    print("Executing command: " + " ".join(command_clean_dir))
    subprocess.run(command_clean_dir, check=True)


    temp_output_path = output_dir+shlex.quote(func_name)+"_temp_output.txt"
    os.makedirs(output_dir, exist_ok=True)
    with open(temp_output_path, "w") as temp_file:
        command = [
            "/home/klee/klee_test/build/bin/klee", 
            "--search=dfs", 
            "-debug-print-instructions=all:stderr",
            "--test-info-output-dir="+test_info_dir+shlex.quote(func_name),
            "--output-dir="+output_dir+shlex.quote(func_name),
            "--test-target-name="+shlex.quote(func_name),
            test_files_dir+shlex.quote(func_name)+".test.bc"
        ]
        print("Executing command: " + " ".join(command))
        subprocess.run(command, stdout=temp_file, stderr=temp_file)

    output_path = output_dir+shlex.quote(func_name)+"_output.txt"

    with open(output_path, "w") as output_file:
        # run the tail command and redirect the output to your target file
        subprocess.run(["tail", "-n", "40", temp_output_path], stdout=output_file)
    
    # Delete the temp file
    # os.remove(temp_output_path)


# func = funcs[0]
# run_command(func)


print(func_names)

with concurrent.futures.ProcessPoolExecutor(max_workers=1) as executor:
    executor.map(run_command, func_names)