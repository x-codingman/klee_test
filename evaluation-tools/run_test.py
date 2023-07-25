import shlex
import subprocess



funcs = [
    "vTaskGetInfo",
    "vTaskSuspend",
    "vTaskResume",
    "pcTaskGetName",
    "uxTaskGetStackHighWaterMark",
    "uxTaskGetStackHighWaterMark2",
    "vTaskSetApplicationTaskTag",
    "xTaskGetApplicationTaskTag",
    "vTaskSetThreadLocalStoragePointer",
    "pvTaskGetThreadLocalStoragePointer",
    "uxTaskGetSystemState",
    "ulTaskGetRunTimeCounter",
    "ulTaskGetRunTimePercent",
    "xTaskGenericNotify",
    "xTaskGenericNotifyWait",
    "ulTaskGenericNotifyTake",
    "xTaskGenericNotifyStateClear",
    "ulTaskGenericNotifyValueClear",
    "vTaskSetTimeOutState",
    "xTaskCheckForTimeOut"


]


funcs_delete = [
        "uxTaskGetSystemState",
    "ulTaskGetRunTimeCounter",
    "ulTaskGetRunTimePercent",
    "xTaskGenericNotify",
    "xTaskGenericNotifyWait",
    "ulTaskGenericNotifyTake",
    "xTaskGenericNotifyStateClear",
    "ulTaskGenericNotifyValueClear",
    "vTaskSetTimeOutState",
    "xTaskCheckForTimeOut"
]

# for func in funcs_delete:

#     command_clean = [
#         "rm", 
#         "/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/"+shlex.quote(func)+".c"
#     ]
#     print("Executing command: " + " ".join(command_clean))
#     subprocess.run(command_clean, check=True)

for func in funcs:
    command_clean_dir = [
        "rm", 
        "-rf", 
        "/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/"+shlex.quote(func)
    ]
    print("Executing command: " + " ".join(command_clean_dir))
    subprocess.run(command_clean_dir, check=True)
    command = [
        "/home/klee/klee_test/build/bin/klee", 
        "--search=dfs", 
        "-debug-print-instructions=all:stderr", 
        "--output-dir=/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/"+shlex.quote(func), 
        "/home/klee/FreeRTOS-Kernel-10.6.0/symbolic_execution/"+shlex.quote(func)+".test.bc"
    ]
    print("Executing command: " + " ".join(command))
    subprocess.run(command, check=True)