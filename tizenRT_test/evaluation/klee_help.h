#ifndef KLEE_HELP_H
    #define KLEE_HELP_H
 
    #include "stdbool.h"
    #include <stdint.h>
    #include <stdlib.h>
    #include "tinyara/sched.h"
    #include "tinyara/mm/mm.h"
    #include "macro_all.h"

#define portTOTAL_NUM_REGIONS 8
#define portIS_PRIVILEGED()      xIsPrivileged() 

#define portRAISE_PRIVILEGE()


uint32_t g_idle_topstack = 0x20000000;
bool abort_mode = false;
char assert_info_str[CONFIG_STDIO_BUFFER_SIZE] = {'\0', };
current_regs = 0;
g_itm_rxbuffer = 0;
user_assert_location = 0;
struct mm_heap_s __attribute__((weak))  g_kmmheap[] ;
void* __attribute__((weak))  kregionx_start[] ;
size_t __attribute__((weak)) kregionx_size[] ;
_sdata = 0x30000000;
_edata = 0x40000000;
_stext_flash = 0x80000000;
_etext_flash = 0x90000000;
_sbss = 0xa00000000;
_ebss = 0xb00000000;
mtd_procfsoperations = 0;
part_procfsoperations = 0;
power_procfsoperations = 0;
FAR struct tcb_s klee_tcb;


#define portRESET_PRIVILEGE() vResetPrivilege()
    typedef struct MPURegionSettings
    {
        uint32_t ulRBAR; /**< RBAR for the region. */
        uint32_t ulRLAR; /**< RLAR for the region. */
    } MPURegionSettings_t;

typedef struct MPU_SETTINGS
    {
        uint32_t ulMAIR0;                                              /**< MAIR0 for the task containing attributes for all the 4 per task regions. */
        MPURegionSettings_t xRegionsSettings[ portTOTAL_NUM_REGIONS ]; /**< Settings for 4 per task regions. */
    } xMPU_SETTINGS;




 
    




#endif