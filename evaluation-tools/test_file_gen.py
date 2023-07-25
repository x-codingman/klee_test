import os








funcs = [
    {
        "name": "vTaskDelay",
        "arg_nums": 1,
        "arguments": "xTicksToDelay",
        "type": "TickType_t ",
        "control_flags" : "true"
    },
    {
        "name": "xTaskDelayUntil",
        "arg_nums": 2,
        "arguments": "pxPreviousWakeTime, xTimeIncrement",
        "type": "TickType_t *, TickType_t",
        "control_flags" : "restricted, true"
    },
    {
        "name": "xTaskAbortDelay",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "uxTaskPriorityGet",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "eTaskGetState",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "vTaskGetInfo",
        "arg_nums": 4,
        "arguments": "xTask, pxTaskStatus, xGetFreeStackSpace, eState",
        "type": "TaskHandle_t, TaskStatus_t *, BaseType_t, eTaskState",
        "control_flags" : "false, true, true, true"
    },
    {
        "name": "vTaskSuspend",
        "arg_nums": 1,
        "arguments": "xTaskToResume",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "vTaskResume",
        "arg_nums": 1,
        "arguments": "xTaskToResume",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "pcTaskGetName",
        "arg_nums": 1,
        "arguments": "xTaskToQuery",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "uxTaskGetStackHighWaterMark",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "uxTaskGetStackHighWaterMark2",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "vTaskSetApplicationTaskTag",
        "arg_nums": 2,
        "arguments": "xTask, pxHookFunction",
        "type": "TaskHandle_t, TaskHookFunction_t",
        "control_flags" : "false, true"
    },
    {
        "name": "xTaskGetApplicationTaskTag",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "vTaskSetThreadLocalStoragePointer",
        "arg_nums": 3,
        "arguments": "xTaskToQuery, xIndex, pvValue",
        "type": "TaskHandle_t, BaseType_t, void *",
        "control_flags" : "false, true, true"
    },
    {
        "name": "pvTaskGetThreadLocalStoragePointer",
        "arg_nums": 2,
        "arguments": "xTaskToQuery, xIndex",
        "type": "TaskHandle_t, BaseType_t",
        "control_flags" : "false,true"
    },
    {
        "name": "uxTaskGetSystemState",
        "arg_nums": 2,
        "arguments": "pxTaskStatusArray,uxArraySize,pulTotalRunTime",
        "type": "TaskStatus_t *,UBaseType_t,configRUN_TIME_COUNTER_TYPE *",
        "control_flags" : "true,false,false"
    },
    {
        "name": "ulTaskGetRunTimeCounter",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "ulTaskGetRunTimePercent",
        "arg_nums": 1,
        "arguments": "xTask",
        "type": "TaskHandle_t",
        "control_flags" : "false"
    },
    {
        "name": "xTaskGenericNotify",
        "arg_nums": 5,
        "arguments": "xTaskToNotify,uxIndexToNotify,ulValue,eAction,pulPreviousNotificationValue",
        "type": "TaskHandle_t,UBaseType_t,uint32_t,eNotifyAction,uint32_t *",
        "control_flags" : "false, true, true, true, true"
    },
    {
        "name": "xTaskGenericNotifyWait",
        "arg_nums": 5,
        "arguments": "uxIndexToWaitOn, ulBitsToClearOnEntry, ulBitsToClearOnExit, pulNotificationValue, xTicksToWait",
        "type": "UBaseType_t, uint32_t, uint32_t,uint32_t *,TickType_t",
        "control_flags" : "true, true, true, true, true"
    },
    {
        "name": "ulTaskGenericNotifyTake",
        "arg_nums": 3,
        "arguments": "uxIndexToWaitOn, xClearCountOnExit, xTicksToWait",
        "type": "UBaseType_t, BaseType_t, TickType_t",
        "control_flags" : "true, true, true"
    },
    {
        "name": "xTaskGenericNotifyStateClear",
        "arg_nums": 2,
        "arguments": "xTask, uxIndexToClear",
        "type": "TaskHandle_t, UBaseType_t",
        "control_flags" : "true, true"
    },
    {
        "name": "ulTaskGenericNotifyValueClear",
        "arg_nums": 3,
        "arguments": "xTask, uxIndexToClear, ulBitsToClear",
        "type": "TaskHandle_t, UBaseType_t, uint32_t",
        "control_flags" : "true, true, true"
    },
    {
        "name": "vTaskSetTimeOutState",
        "arg_nums": 1,
        "arguments": "pxTimeOut",
        "type": "TimeOut_t *",
        "control_flags" : "true"
    },
    {
        "name": "xTaskCheckForTimeOut",
        "arg_nums": 2,
        "arguments": "pxTimeOut, pxTicksToWait",
        "type": "TimeOut_t *, TickType_t *",
        "control_flags" : "true, true"
    }
    # you can add more function definitions here
]

for func in funcs:
    arg_names = func["arguments"].split(',')
    arg_types = func["type"].split(',')
    control_flags = func["control_flags"].split(',')
    declarations = []
    klee_calls = []
    conditions = []
    for arg_name, arg_type, control_flag in zip(arg_names, arg_types, control_flags):
        declarations.append(f'{arg_type.strip()} {arg_name.strip()};\n')
        if control_flag == "restricted":
            conditions.append( f'if ({arg_name.strip()} < MPU_ENABLE_ADDRESS_START || {arg_name.strip()} > MPU_ENABLE_ADDRESS_END) {{ return; }}\n')
        klee_calls.append(f'klee_make_symbolic_controllable(&{arg_name.strip()}, sizeof({arg_name.strip()}), "{arg_name.strip()}", "{control_flag.strip()}");\n')
    declaration_code = ''.join(declarations)
    klee_call_code = ''.join(klee_calls)
    condition_code = ''.join(conditions)
    function_call = f'{func["name"]}({func["arguments"]});\n'
    # Rest of the script
    func_name = func['name']
    file_path = f"{func_name}.c"
    print(f"Generating file {file_path}...")

    with open(file_path, 'w') as file:
        file.write('#include "klee_help.h"\n')
        file.write('#include <FreeRTOS.h>\n')
        file.write('#include <task.h>\n')
        file.write('#include <queue.h>\n')
        file.write('#include <klee/klee.h>\n')
        file.write('#include <list.h>\n')
        file.write('#define STACK_SIZE 200\n')
        file.write('#define MPU_ENABLE_ADDRESS_START 0xefff2000\n')
        file.write('#define MPU_ENABLE_ADDRESS_END 0xefff4000\n')
        file.write('#define ATTACK_CAPABILITY_REGION_START 0x80000000\n')
        file.write('#define ATTACK_CAPABILITY_REGION_END 0x8fffffff\n')
        file.write('void vTaskFunction1( void *pvParameters );\n')
        file.write('int main()\n')
        file.write('{\n')
        file.write('xTaskCreate(vTaskFunction1, "Task1", STACK_SIZE, NULL, 1, NULL);\n')
        file.write(declaration_code)
        file.write(klee_call_code)
        file.write(condition_code)
        file.write(function_call)
        file.write('}\n')
        file.write('void vTaskFunction1( void *pvParameters )\n')
        file.write('{\n')
        file.write('assert(0);\n')
        file.write('}\n')
        file.close()

    print(f"File {file_path} generated.")