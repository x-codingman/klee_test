import os
import json








with open('funcs_info.json', 'r') as f:
    funcs = json.load(f)

for func in funcs:
    arg_names = func["arguments"].split(',')
    arg_types = func["type"].split(',')
    control_flags = func["control_flags"].split(',')
    declarations = []
    klee_calls = []
    conditions = []
    for arg_name, arg_type, control_flag in zip(arg_names, arg_types, control_flags):
        declarations.append(f'{arg_type.strip()} {arg_name.strip()};\n')
        if control_flag.strip() == "restricted":
            conditions.append( f'if ({arg_name.strip()} < ATTACK_CAPABILITY_REGION_START || {arg_name.strip()} > ATTACK_CAPABILITY_REGION_END) {{ return 0; }}\n')
            klee_calls.append(f'klee_make_symbolic_controllable(&{arg_name.strip()}, sizeof({arg_name.strip()}), "{arg_name.strip()}", true);\n')
        else:    
            klee_calls.append(f'klee_make_symbolic_controllable(&{arg_name.strip()}, sizeof({arg_name.strip()}), "{arg_name.strip()}", {control_flag.strip()});\n')
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
        file.write('return 0;\n')
        file.write('}\n')
        file.write('void vTaskFunction1( void *pvParameters )\n')
        file.write('{\n')
        file.write('assert(0);\n')
        file.write('}\n')
        file.close()

    print(f"File {file_path} generated.")