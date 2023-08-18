CC                    := clang

BUILD_DIR             := ./build
BUILD_EXTRA_DIR       := ./build_extra


KERNEL_DIR            := /home/klee/threadx/threadx/




#TARGET_DIR            := /home/klee/FreeRTOS-kernel-revision/portable/GCC/ARM_CM33_NTZ/non_secure


KLEE_INCLUDE_DIR      := /home/klee/klee_test/include/


INCLUDE_DIRS          := -I.
# INCLUDE_DIRS          += -I/usr/lib/gcc/arm-none-eabi/6.3.1/include
# INCLUDE_DIRS          += -I/usr/lib/gcc/arm-none-eabi/6.3.1/include-fixed
#INCLUDE_DIRS          += -I/home/klee/threadx/threadx/ports_module/cortex_m33/gnu/inc
INCLUDE_DIRS          += -I/home/klee/threadx/threadx/ports/cortex_m33/gnu/inc
INCLUDE_DIRS          += -I${KLEE_INCLUDE_DIR}
INCLUDE_DIRS          += -I/home/klee/threadx/threadx/common/inc
#INCLUDE_DIRS          += -I/home/klee/threadx/threadx/common_modules/inc

#INCLUDE_DIRS          += -I/home/klee/threadx/threadx/ports_module/cortex_m33/gnu/module_manager/inc

#SOURCE_FILES          := $(wildcard *.c)
#SOURCE_FILES          := $(wildcard /home/klee/threadx/threadx/common_modules/module_lib/src/*.c)
SOURCE_FILES          += $(wildcard /home/klee/threadx/threadx/common/src/*.c)
#SOURCE_FILES          += $(wildcard /home/klee/threadx/threadx/common/src/tx_thread_initialize.c)
#SOURCE_FILES          += $(wildcard /home/klee/threadx/threadx/ports_module/cortex_m33/gnu/module_lib/src/*.c)

# Memory manager (use malloc() / free() )




BC_FILES              := $(SOURCE_FILES:%.c=$(BUILD_DIR)/%.bc)
TEST_SOURCE_FILES     := $(wildcard *.c)
TEST_BC_FILES         := $(TEST_SOURCE_FILES:.c=.test.bc)
# BC_FILES              += $(wildcard /home/klee/klee_build/runtime/POSIX/fd64_Release+Debug+Asserts.bc)
# BC_FILES              += $(wildcard /home/klee/klee_build/runtime/POSIX/fd_init64_Release+Debug+Asserts.bc)
# BC_FILES              += $(wildcard /home/klee/klee_build/runtime/POSIX/illegal64_Release+Debug+Asserts.bc)
# BC_FILES              += $(wildcard /home/klee/klee_build/runtime/POSIX/klee_init_env64_Release+Debug+Asserts.bc)
# BC_FILES              += $(wildcard /home/klee/klee_build/runtime/POSIX/stubs64_Release+Debug+Asserts.bc)

CFLAGS                :=  -emit-llvm -c -g -fno-asm
# CFLAGS                += --sysroot=/usr/lib/gcc/arm-none-eabi/6.3.1


all: $(TEST_BC_FILES) 



$(BUILD_DIR)/%.bc : %.c 
	-mkdir -p $(@D)
	$(CC) $(INCLUDE_DIRS) $(CFLAGS) $< -o $@

# result.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@

# vTaskDelay.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@

# vTaskDelayUntil.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@

# xTaskAbortDelay.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@

# uxTaskPriorityGet.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@

# eTaskGetState.bc : $(BC_FILES)
# 	-mkdir -p ${@D}
# 	llvm-link $^ -o $@
%.bc : %.c 
	-mkdir -p $(@D)
	$(CC) $(INCLUDE_DIRS) $(CFLAGS) $< -o $@

%.test.bc : $(BC_FILES) %.bc
	-mkdir -p ${@D}
	llvm-link $^ -o $@


clean:
	rm -rf $(BUILD_DIR) $(TEST_BC_FILES) *.bc