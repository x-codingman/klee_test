#include "klee_help.h"
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <klee/klee.h>
#include <list.h>
#include <stream_buffer.h>
#include <timers.h>
#include <event_groups.h>
#define STACK_SIZE 200
#define MPU_ENABLE_ADDRESS_START 0xefff2000
#define MPU_ENABLE_ADDRESS_END 0xefff4000
#define ATTACK_CAPABILITY_REGION_START 0x80000000
#define ATTACK_CAPABILITY_REGION_END 0x8fffffff
void vTaskFunction1( void *pvParameters );
int main()
{
xTaskCreate(vTaskFunction1, "Task1", STACK_SIZE, NULL, 1, NULL);
QueueHandle_t KLEE_xQueue;
void * const KLEE_pvBuffer;
TickType_t KLEE_xTicksToWait;
klee_make_symbolic_controllable(&KLEE_xQueue, sizeof(KLEE_xQueue), "KLEE_xQueue", true);
klee_make_symbolic_controllable(&KLEE_pvBuffer, sizeof(KLEE_pvBuffer), "KLEE_pvBuffer", true);
klee_make_symbolic_controllable(&KLEE_xTicksToWait, sizeof(KLEE_xTicksToWait), "KLEE_xTicksToWait", true);
if (KLEE_xQueue < KERNEL_REGION_START || KLEE_xQueue > KERNEL_REGION_END) { return 0; }
if (KLEE_pvBuffer < ATTACK_CAPABILITY_REGION_START || KLEE_pvBuffer > ATTACK_CAPABILITY_REGION_END) { return 0; }
xQueueReceive(KLEE_xQueue,KLEE_pvBuffer,KLEE_xTicksToWait);
return 0;
}
void vTaskFunction1( void *pvParameters )
{
assert(0);
}