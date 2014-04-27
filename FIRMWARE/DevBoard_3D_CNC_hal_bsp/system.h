/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu' in SOPC Builder design 'DevBoard_3D_CNC'
 * SOPC Builder design path: Z:/HDS/DimoSoft/DevBoard_3D_CNC/quartus/DevBoard_3D_DE2-70/DevBoard_3D_CNC.sopcinfo
 *
 * Generated: Mon Apr 14 11:03:05 KST 2014
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x6008820
#define ALT_CPU_CPU_FREQ 80000000u
#define ALT_CPU_CPU_ID_SIZE 30
#define ALT_CPU_CPU_ID_VALUE 0x20140001
#define ALT_CPU_CPU_IMPLEMENTATION "fast"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1b
#define ALT_CPU_DCACHE_LINE_SIZE 32
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_DCACHE_SIZE 2048
#define ALT_CPU_EIC_PRESENT
#define ALT_CPU_EXCEPTION_ADDR 0x6004020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 80000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 1
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_EXTRA_EXCEPTION_INFO
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_ILLEGAL_MEMORY_ACCESS_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 32
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 5
#define ALT_CPU_ICACHE_SIZE 4096
#define ALT_CPU_INITDA_SUPPORTED
#define ALT_CPU_INST_ADDR_WIDTH 0x1b
#define ALT_CPU_NAME "cpu"
#define ALT_CPU_NUM_OF_SHADOW_REG_SETS 1
#define ALT_CPU_RESET_ADDR 0x6004000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x6008820
#define NIOS2_CPU_FREQ 80000000u
#define NIOS2_CPU_ID_SIZE 30
#define NIOS2_CPU_ID_VALUE 0x20140001
#define NIOS2_CPU_IMPLEMENTATION "fast"
#define NIOS2_DATA_ADDR_WIDTH 0x1b
#define NIOS2_DCACHE_LINE_SIZE 32
#define NIOS2_DCACHE_LINE_SIZE_LOG2 5
#define NIOS2_DCACHE_SIZE 2048
#define NIOS2_EIC_PRESENT
#define NIOS2_EXCEPTION_ADDR 0x6004020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 1
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_EXTRA_EXCEPTION_INFO
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_ILLEGAL_MEMORY_ACCESS_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 32
#define NIOS2_ICACHE_LINE_SIZE_LOG2 5
#define NIOS2_ICACHE_SIZE 4096
#define NIOS2_INITDA_SUPPORTED
#define NIOS2_INST_ADDR_WIDTH 0x1b
#define NIOS2_NUM_OF_SHADOW_REG_SETS 1
#define NIOS2_RESET_ADDR 0x6004000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_NIOS_CUSTOM_INSTR_BITSWAP_0(A) __builtin_custom_ini(ALT_CI_NIOS_CUSTOM_INSTR_BITSWAP_0_N,(A))
#define ALT_CI_NIOS_CUSTOM_INSTR_BITSWAP_0_N 0x0
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0(n,A,B) __builtin_custom_inii(ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N+(n&ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK),(A),(B))
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N 0xfc
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK ((1<<2)-1)


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_16550_UART
#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_LCD_16207
#define __ALTERA_AVALON_MUTEX
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_AVALON_UART
#define __ALTERA_GENERIC_TRISTATE_CONTROLLER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_NIOS_CUSTOM_INSTR_BITSWAP
#define __ALTERA_NIOS_CUSTOM_INSTR_FLOATING_POINT
#define __ALTERA_VIC
#define __MOTORDRV_WITH_TEMPERATURE_3D_CNC
#define __MTX_AVALON_SDRAM


/*
 * DevCore_3D_CNC configuration
 *
 */

#define ALT_MODULE_CLASS_DevCore_3D_CNC MotorDrv_with_Temperature_3D_CNC
#define DEVCORE_3D_CNC_BASE 0x4000000
#define DEVCORE_3D_CNC_IRQ 6
#define DEVCORE_3D_CNC_IRQ_INTERRUPT_CONTROLLER_ID 0
#define DEVCORE_3D_CNC_NAME "/dev/DevCore_3D_CNC"
#define DEVCORE_3D_CNC_SPAN 512
#define DEVCORE_3D_CNC_TYPE "MotorDrv_with_Temperature_3D_CNC"


/*
 * Gcode_16550 configuration
 *
 */

#define ALT_MODULE_CLASS_Gcode_16550 altera_16550_uart
#define GCODE_16550_BASE 0x4000200
#define GCODE_16550_FREQ 50000000
#define GCODE_16550_IRQ 5
#define GCODE_16550_IRQ_INTERRUPT_CONTROLLER_ID 0
#define GCODE_16550_NAME "/dev/Gcode_16550"
#define GCODE_16550_SPAN 512
#define GCODE_16550_TYPE "altera_16550_uart"


/*
 * LCD_DISPLAY configuration
 *
 */

#define ALT_MODULE_CLASS_LCD_DISPLAY altera_avalon_lcd_16207
#define LCD_DISPLAY_BASE 0x40004b0
#define LCD_DISPLAY_IRQ -1
#define LCD_DISPLAY_IRQ_INTERRUPT_CONTROLLER_ID -1
#define LCD_DISPLAY_NAME "/dev/LCD_DISPLAY"
#define LCD_DISPLAY_SPAN 16
#define LCD_DISPLAY_TYPE "altera_avalon_lcd_16207"


/*
 * SDCARD_sdcard_cmd configuration
 *
 */

#define ALT_MODULE_CLASS_SDCARD_sdcard_cmd altera_avalon_pio
#define SDCARD_SDCARD_CMD_BASE 0x4000410
#define SDCARD_SDCARD_CMD_BIT_CLEARING_EDGE_REGISTER 0
#define SDCARD_SDCARD_CMD_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDCARD_SDCARD_CMD_CAPTURE 0
#define SDCARD_SDCARD_CMD_DATA_WIDTH 1
#define SDCARD_SDCARD_CMD_DO_TEST_BENCH_WIRING 0
#define SDCARD_SDCARD_CMD_DRIVEN_SIM_VALUE 0
#define SDCARD_SDCARD_CMD_EDGE_TYPE "NONE"
#define SDCARD_SDCARD_CMD_FREQ 50000000
#define SDCARD_SDCARD_CMD_HAS_IN 0
#define SDCARD_SDCARD_CMD_HAS_OUT 0
#define SDCARD_SDCARD_CMD_HAS_TRI 1
#define SDCARD_SDCARD_CMD_IRQ -1
#define SDCARD_SDCARD_CMD_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDCARD_SDCARD_CMD_IRQ_TYPE "NONE"
#define SDCARD_SDCARD_CMD_NAME "/dev/SDCARD_sdcard_cmd"
#define SDCARD_SDCARD_CMD_RESET_VALUE 0
#define SDCARD_SDCARD_CMD_SPAN 16
#define SDCARD_SDCARD_CMD_TYPE "altera_avalon_pio"


/*
 * SDCARD_sdcard_dat configuration
 *
 */

#define ALT_MODULE_CLASS_SDCARD_sdcard_dat altera_avalon_pio
#define SDCARD_SDCARD_DAT_BASE 0x4000420
#define SDCARD_SDCARD_DAT_BIT_CLEARING_EDGE_REGISTER 0
#define SDCARD_SDCARD_DAT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDCARD_SDCARD_DAT_CAPTURE 0
#define SDCARD_SDCARD_DAT_DATA_WIDTH 1
#define SDCARD_SDCARD_DAT_DO_TEST_BENCH_WIRING 0
#define SDCARD_SDCARD_DAT_DRIVEN_SIM_VALUE 0
#define SDCARD_SDCARD_DAT_EDGE_TYPE "NONE"
#define SDCARD_SDCARD_DAT_FREQ 50000000
#define SDCARD_SDCARD_DAT_HAS_IN 0
#define SDCARD_SDCARD_DAT_HAS_OUT 0
#define SDCARD_SDCARD_DAT_HAS_TRI 1
#define SDCARD_SDCARD_DAT_IRQ -1
#define SDCARD_SDCARD_DAT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDCARD_SDCARD_DAT_IRQ_TYPE "NONE"
#define SDCARD_SDCARD_DAT_NAME "/dev/SDCARD_sdcard_dat"
#define SDCARD_SDCARD_DAT_RESET_VALUE 0
#define SDCARD_SDCARD_DAT_SPAN 16
#define SDCARD_SDCARD_DAT_TYPE "altera_avalon_pio"


/*
 * SDCARD_sdcard_dat3 configuration
 *
 */

#define ALT_MODULE_CLASS_SDCARD_sdcard_dat3 altera_avalon_pio
#define SDCARD_SDCARD_DAT3_BASE 0x4000430
#define SDCARD_SDCARD_DAT3_BIT_CLEARING_EDGE_REGISTER 0
#define SDCARD_SDCARD_DAT3_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDCARD_SDCARD_DAT3_CAPTURE 0
#define SDCARD_SDCARD_DAT3_DATA_WIDTH 1
#define SDCARD_SDCARD_DAT3_DO_TEST_BENCH_WIRING 0
#define SDCARD_SDCARD_DAT3_DRIVEN_SIM_VALUE 0
#define SDCARD_SDCARD_DAT3_EDGE_TYPE "NONE"
#define SDCARD_SDCARD_DAT3_FREQ 50000000
#define SDCARD_SDCARD_DAT3_HAS_IN 0
#define SDCARD_SDCARD_DAT3_HAS_OUT 0
#define SDCARD_SDCARD_DAT3_HAS_TRI 1
#define SDCARD_SDCARD_DAT3_IRQ -1
#define SDCARD_SDCARD_DAT3_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDCARD_SDCARD_DAT3_IRQ_TYPE "NONE"
#define SDCARD_SDCARD_DAT3_NAME "/dev/SDCARD_sdcard_dat3"
#define SDCARD_SDCARD_DAT3_RESET_VALUE 0
#define SDCARD_SDCARD_DAT3_SPAN 16
#define SDCARD_SDCARD_DAT3_TYPE "altera_avalon_pio"


/*
 * SDCARD_sdcard_sclk configuration
 *
 */

#define ALT_MODULE_CLASS_SDCARD_sdcard_sclk altera_avalon_pio
#define SDCARD_SDCARD_SCLK_BASE 0x4000400
#define SDCARD_SDCARD_SCLK_BIT_CLEARING_EDGE_REGISTER 0
#define SDCARD_SDCARD_SCLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define SDCARD_SDCARD_SCLK_CAPTURE 0
#define SDCARD_SDCARD_SCLK_DATA_WIDTH 1
#define SDCARD_SDCARD_SCLK_DO_TEST_BENCH_WIRING 0
#define SDCARD_SDCARD_SCLK_DRIVEN_SIM_VALUE 0
#define SDCARD_SDCARD_SCLK_EDGE_TYPE "NONE"
#define SDCARD_SDCARD_SCLK_FREQ 50000000
#define SDCARD_SDCARD_SCLK_HAS_IN 0
#define SDCARD_SDCARD_SCLK_HAS_OUT 1
#define SDCARD_SDCARD_SCLK_HAS_TRI 0
#define SDCARD_SDCARD_SCLK_IRQ -1
#define SDCARD_SDCARD_SCLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDCARD_SDCARD_SCLK_IRQ_TYPE "NONE"
#define SDCARD_SDCARD_SCLK_NAME "/dev/SDCARD_sdcard_sclk"
#define SDCARD_SDCARD_SCLK_RESET_VALUE 0
#define SDCARD_SDCARD_SCLK_SPAN 16
#define SDCARD_SDCARD_SCLK_TYPE "altera_avalon_pio"


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone II"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x6009868
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x6009868
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x6009868
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "DevBoard_3D_CNC"


/*
 * altera_vic_driver configuration
 *
 */

#define ALTERA_VIC_DRIVER_ENABLE_PREEMPTION_RS_1 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ0_RIL 15
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ0_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ0_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ10_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ10_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ10_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ11_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ11_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ11_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ12_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ12_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ12_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ13_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ13_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ13_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ14_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ14_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ14_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ15_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ15_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ15_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ16_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ16_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ16_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ17_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ17_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ17_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ18_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ18_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ18_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ19_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ19_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ19_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ1_RIL 14
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ1_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ1_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ20_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ20_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ20_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ21_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ21_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ21_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ22_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ22_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ22_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ23_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ23_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ23_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ24_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ24_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ24_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ25_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ25_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ25_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ26_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ26_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ26_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ27_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ27_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ27_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ28_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ28_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ28_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ29_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ29_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ29_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ2_RIL 13
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ2_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ2_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ30_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ30_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ30_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ31_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ31_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ31_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ3_RIL 12
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ3_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ3_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ4_RIL 11
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ4_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ4_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ5_RIL 10
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ5_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ5_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ6_RIL 9
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ6_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ6_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ7_RIL 8
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ7_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ7_RRS 1
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ8_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ8_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ8_RRS 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ9_RIL 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ9_RNMI 0
#define ALTERA_VIC_DRIVER_INTERRUPT_IRQ9_RRS 0
#define ALTERA_VIC_DRIVER_ISR_PREEMPTION_ENABLED
#define ALTERA_VIC_DRIVER_LINKER_SECTION .text
#define INTERRUPT_VEC_SIZE 16
#define INTERRUPT_VEC_TBL_BASE INTERRUPT_VECTOR_TABLE


/*
 * buffer_control configuration
 *
 */

#define ALT_MODULE_CLASS_buffer_control altera_avalon_mutex
#define BUFFER_CONTROL_BASE 0x6009860
#define BUFFER_CONTROL_IRQ -1
#define BUFFER_CONTROL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define BUFFER_CONTROL_NAME "/dev/buffer_control"
#define BUFFER_CONTROL_OWNER_INIT 0
#define BUFFER_CONTROL_OWNER_WIDTH 16
#define BUFFER_CONTROL_SPAN 8
#define BUFFER_CONTROL_TYPE "altera_avalon_mutex"
#define BUFFER_CONTROL_VALUE_INIT 0
#define BUFFER_CONTROL_VALUE_WIDTH 16


/*
 * cfi_flash configuration
 *
 */

#define ALT_MODULE_CLASS_cfi_flash altera_generic_tristate_controller
#define CFI_FLASH_BASE 0x5800000
#define CFI_FLASH_HOLD_VALUE 0
#define CFI_FLASH_IRQ -1
#define CFI_FLASH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define CFI_FLASH_NAME "/dev/cfi_flash"
#define CFI_FLASH_SETUP_VALUE 0
#define CFI_FLASH_SIZE 8388608u
#define CFI_FLASH_SPAN 8388608
#define CFI_FLASH_TIMING_UNITS "ns"
#define CFI_FLASH_TYPE "altera_generic_tristate_controller"
#define CFI_FLASH_WAIT_VALUE 100


/*
 * gcode_uart configuration
 *
 */

#define ALT_MODULE_CLASS_gcode_uart altera_avalon_uart
#define GCODE_UART_BASE 0x6009800
#define GCODE_UART_BAUD 115200
#define GCODE_UART_DATA_BITS 8
#define GCODE_UART_FIXED_BAUD 1
#define GCODE_UART_FREQ 80000000
#define GCODE_UART_IRQ 1
#define GCODE_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define GCODE_UART_NAME "/dev/gcode_uart"
#define GCODE_UART_PARITY 'N'
#define GCODE_UART_SIM_CHAR_STREAM ""
#define GCODE_UART_SIM_TRUE_BAUD 0
#define GCODE_UART_SPAN 32
#define GCODE_UART_STOP_BITS 1
#define GCODE_UART_SYNC_REG_DEPTH 2
#define GCODE_UART_TYPE "altera_avalon_uart"
#define GCODE_UART_USE_CTS_RTS 0
#define GCODE_UART_USE_EOP_REGISTER 0


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK TIMER
#define ALT_TIMESTAMP_CLK TIMER_STAMP


/*
 * i2c_sclk configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_sclk altera_avalon_pio
#define I2C_SCLK_BASE 0x40004c0
#define I2C_SCLK_BIT_CLEARING_EDGE_REGISTER 0
#define I2C_SCLK_BIT_MODIFYING_OUTPUT_REGISTER 0
#define I2C_SCLK_CAPTURE 0
#define I2C_SCLK_DATA_WIDTH 1
#define I2C_SCLK_DO_TEST_BENCH_WIRING 0
#define I2C_SCLK_DRIVEN_SIM_VALUE 0
#define I2C_SCLK_EDGE_TYPE "NONE"
#define I2C_SCLK_FREQ 50000000
#define I2C_SCLK_HAS_IN 0
#define I2C_SCLK_HAS_OUT 1
#define I2C_SCLK_HAS_TRI 0
#define I2C_SCLK_IRQ -1
#define I2C_SCLK_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_SCLK_IRQ_TYPE "NONE"
#define I2C_SCLK_NAME "/dev/i2c_sclk"
#define I2C_SCLK_RESET_VALUE 0
#define I2C_SCLK_SPAN 16
#define I2C_SCLK_TYPE "altera_avalon_pio"


/*
 * i2c_sdat configuration
 *
 */

#define ALT_MODULE_CLASS_i2c_sdat altera_avalon_pio
#define I2C_SDAT_BASE 0x40004d0
#define I2C_SDAT_BIT_CLEARING_EDGE_REGISTER 0
#define I2C_SDAT_BIT_MODIFYING_OUTPUT_REGISTER 0
#define I2C_SDAT_CAPTURE 0
#define I2C_SDAT_DATA_WIDTH 1
#define I2C_SDAT_DO_TEST_BENCH_WIRING 0
#define I2C_SDAT_DRIVEN_SIM_VALUE 0
#define I2C_SDAT_EDGE_TYPE "NONE"
#define I2C_SDAT_FREQ 50000000
#define I2C_SDAT_HAS_IN 0
#define I2C_SDAT_HAS_OUT 0
#define I2C_SDAT_HAS_TRI 1
#define I2C_SDAT_IRQ -1
#define I2C_SDAT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define I2C_SDAT_IRQ_TYPE "NONE"
#define I2C_SDAT_NAME "/dev/i2c_sdat"
#define I2C_SDAT_RESET_VALUE 0
#define I2C_SDAT_SPAN 16
#define I2C_SDAT_TYPE "altera_avalon_pio"


/*
 * interrupt configuration
 *
 */

#define ALT_MODULE_CLASS_interrupt altera_vic
#define INTERRUPT_BASE 0x6009400
#define INTERRUPT_DAISY_CHAIN_ENABLE 0
#define INTERRUPT_INTERRUPT_CONTROLLER_ID 0
#define INTERRUPT_IRQ -1
#define INTERRUPT_IRQ_INTERRUPT_CONTROLLER_ID -1
#define INTERRUPT_NAME "/dev/interrupt"
#define INTERRUPT_NUMBER_OF_INT_PORTS 8
#define INTERRUPT_RIL_WIDTH 4
#define INTERRUPT_SPAN 1024
#define INTERRUPT_TYPE "altera_vic"


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x6009868
#define JTAG_UART_IRQ 0
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * onchip_mem configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_mem altera_avalon_onchip_memory2
#define ONCHIP_MEM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_MEM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_MEM_BASE 0x6004000
#define ONCHIP_MEM_CONTENTS_INFO ""
#define ONCHIP_MEM_DUAL_PORT 0
#define ONCHIP_MEM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_INIT_CONTENTS_FILE "DevBoard_3D_CNC_onchip_mem"
#define ONCHIP_MEM_INIT_MEM_CONTENT 1
#define ONCHIP_MEM_INSTANCE_ID "NONE"
#define ONCHIP_MEM_IRQ -1
#define ONCHIP_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_MEM_NAME "/dev/onchip_mem"
#define ONCHIP_MEM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_MEM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_MEM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_MEM_SINGLE_CLOCK_OP 0
#define ONCHIP_MEM_SIZE_MULTIPLE 1
#define ONCHIP_MEM_SIZE_VALUE 16384
#define ONCHIP_MEM_SPAN 16384
#define ONCHIP_MEM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_MEM_WRITABLE 1


/*
 * pio_button configuration
 *
 */

#define ALT_MODULE_CLASS_pio_button altera_avalon_pio
#define PIO_BUTTON_BASE 0x40004e0
#define PIO_BUTTON_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_BUTTON_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_BUTTON_CAPTURE 1
#define PIO_BUTTON_DATA_WIDTH 4
#define PIO_BUTTON_DO_TEST_BENCH_WIRING 0
#define PIO_BUTTON_DRIVEN_SIM_VALUE 0
#define PIO_BUTTON_EDGE_TYPE "RISING"
#define PIO_BUTTON_FREQ 50000000
#define PIO_BUTTON_HAS_IN 1
#define PIO_BUTTON_HAS_OUT 0
#define PIO_BUTTON_HAS_TRI 0
#define PIO_BUTTON_IRQ 4
#define PIO_BUTTON_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_BUTTON_IRQ_TYPE "EDGE"
#define PIO_BUTTON_NAME "/dev/pio_button"
#define PIO_BUTTON_RESET_VALUE 0
#define PIO_BUTTON_SPAN 16
#define PIO_BUTTON_TYPE "altera_avalon_pio"


/*
 * pio_green_led configuration
 *
 */

#define ALT_MODULE_CLASS_pio_green_led altera_avalon_pio
#define PIO_GREEN_LED_BASE 0x4000480
#define PIO_GREEN_LED_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_GREEN_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_GREEN_LED_CAPTURE 0
#define PIO_GREEN_LED_DATA_WIDTH 9
#define PIO_GREEN_LED_DO_TEST_BENCH_WIRING 0
#define PIO_GREEN_LED_DRIVEN_SIM_VALUE 0
#define PIO_GREEN_LED_EDGE_TYPE "NONE"
#define PIO_GREEN_LED_FREQ 50000000
#define PIO_GREEN_LED_HAS_IN 0
#define PIO_GREEN_LED_HAS_OUT 1
#define PIO_GREEN_LED_HAS_TRI 0
#define PIO_GREEN_LED_IRQ -1
#define PIO_GREEN_LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_GREEN_LED_IRQ_TYPE "NONE"
#define PIO_GREEN_LED_NAME "/dev/pio_green_led"
#define PIO_GREEN_LED_RESET_VALUE 0
#define PIO_GREEN_LED_SPAN 16
#define PIO_GREEN_LED_TYPE "altera_avalon_pio"


/*
 * pio_red_led configuration
 *
 */

#define ALT_MODULE_CLASS_pio_red_led altera_avalon_pio
#define PIO_RED_LED_BASE 0x4000490
#define PIO_RED_LED_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_RED_LED_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_RED_LED_CAPTURE 0
#define PIO_RED_LED_DATA_WIDTH 18
#define PIO_RED_LED_DO_TEST_BENCH_WIRING 0
#define PIO_RED_LED_DRIVEN_SIM_VALUE 0
#define PIO_RED_LED_EDGE_TYPE "NONE"
#define PIO_RED_LED_FREQ 50000000
#define PIO_RED_LED_HAS_IN 0
#define PIO_RED_LED_HAS_OUT 1
#define PIO_RED_LED_HAS_TRI 0
#define PIO_RED_LED_IRQ -1
#define PIO_RED_LED_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_RED_LED_IRQ_TYPE "NONE"
#define PIO_RED_LED_NAME "/dev/pio_red_led"
#define PIO_RED_LED_RESET_VALUE 0
#define PIO_RED_LED_SPAN 16
#define PIO_RED_LED_TYPE "altera_avalon_pio"


/*
 * pio_switch configuration
 *
 */

#define ALT_MODULE_CLASS_pio_switch altera_avalon_pio
#define PIO_SWITCH_BASE 0x40004a0
#define PIO_SWITCH_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_SWITCH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_SWITCH_CAPTURE 0
#define PIO_SWITCH_DATA_WIDTH 18
#define PIO_SWITCH_DO_TEST_BENCH_WIRING 0
#define PIO_SWITCH_DRIVEN_SIM_VALUE 0
#define PIO_SWITCH_EDGE_TYPE "NONE"
#define PIO_SWITCH_FREQ 50000000
#define PIO_SWITCH_HAS_IN 1
#define PIO_SWITCH_HAS_OUT 0
#define PIO_SWITCH_HAS_TRI 0
#define PIO_SWITCH_IRQ -1
#define PIO_SWITCH_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_SWITCH_IRQ_TYPE "NONE"
#define PIO_SWITCH_NAME "/dev/pio_switch"
#define PIO_SWITCH_RESET_VALUE 0
#define PIO_SWITCH_SPAN 16
#define PIO_SWITCH_TYPE "altera_avalon_pio"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram mtx_avalon_sdram
#define SDRAM_BASE 0x0
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_SPAN 33554432
#define SDRAM_TYPE "mtx_avalon_sdram"


/*
 * sysid configuration
 *
 */

#define ALT_MODULE_CLASS_sysid altera_avalon_sysid_qsys
#define SYSID_BASE 0x6009870
#define SYSID_ID 538181633
#define SYSID_IRQ -1
#define SYSID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYSID_NAME "/dev/sysid"
#define SYSID_SPAN 8
#define SYSID_TIMESTAMP 1397440941
#define SYSID_TYPE "altera_avalon_sysid_qsys"


/*
 * timer configuration
 *
 */

#define ALT_MODULE_CLASS_timer altera_avalon_timer
#define TIMER_ALWAYS_RUN 0
#define TIMER_BASE 0x6009840
#define TIMER_COUNTER_SIZE 32
#define TIMER_FIXED_PERIOD 0
#define TIMER_FREQ 80000000
#define TIMER_IRQ 2
#define TIMER_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_LOAD_VALUE 79999
#define TIMER_MULT 0.0010
#define TIMER_NAME "/dev/timer"
#define TIMER_PERIOD 1.0
#define TIMER_PERIOD_UNITS "ms"
#define TIMER_RESET_OUTPUT 0
#define TIMER_SNAPSHOT 1
#define TIMER_SPAN 32
#define TIMER_TICKS_PER_SEC 1000.0
#define TIMER_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_TYPE "altera_avalon_timer"


/*
 * timer_stamp configuration
 *
 */

#define ALT_MODULE_CLASS_timer_stamp altera_avalon_timer
#define TIMER_STAMP_ALWAYS_RUN 0
#define TIMER_STAMP_BASE 0x6009820
#define TIMER_STAMP_COUNTER_SIZE 32
#define TIMER_STAMP_FIXED_PERIOD 0
#define TIMER_STAMP_FREQ 80000000
#define TIMER_STAMP_IRQ 3
#define TIMER_STAMP_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_STAMP_LOAD_VALUE 79999
#define TIMER_STAMP_MULT 0.0010
#define TIMER_STAMP_NAME "/dev/timer_stamp"
#define TIMER_STAMP_PERIOD 1.0
#define TIMER_STAMP_PERIOD_UNITS "ms"
#define TIMER_STAMP_RESET_OUTPUT 0
#define TIMER_STAMP_SNAPSHOT 1
#define TIMER_STAMP_SPAN 32
#define TIMER_STAMP_TICKS_PER_SEC 1000.0
#define TIMER_STAMP_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_STAMP_TYPE "altera_avalon_timer"


/*
 * video_mem configuration
 *
 */

#define ALT_MODULE_CLASS_video_mem altera_avalon_new_sdram_controller
#define VIDEO_MEM_BASE 0x2000000
#define VIDEO_MEM_CAS_LATENCY 3
#define VIDEO_MEM_CONTENTS_INFO
#define VIDEO_MEM_INIT_NOP_DELAY 0.0
#define VIDEO_MEM_INIT_REFRESH_COMMANDS 2
#define VIDEO_MEM_IRQ -1
#define VIDEO_MEM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define VIDEO_MEM_IS_INITIALIZED 1
#define VIDEO_MEM_NAME "/dev/video_mem"
#define VIDEO_MEM_POWERUP_DELAY 200.0
#define VIDEO_MEM_REFRESH_PERIOD 7.8125
#define VIDEO_MEM_REGISTER_DATA_IN 1
#define VIDEO_MEM_SDRAM_ADDR_WIDTH 0x18
#define VIDEO_MEM_SDRAM_BANK_WIDTH 2
#define VIDEO_MEM_SDRAM_COL_WIDTH 9
#define VIDEO_MEM_SDRAM_DATA_WIDTH 16
#define VIDEO_MEM_SDRAM_NUM_BANKS 4
#define VIDEO_MEM_SDRAM_NUM_CHIPSELECTS 1
#define VIDEO_MEM_SDRAM_ROW_WIDTH 13
#define VIDEO_MEM_SHARED_DATA 0
#define VIDEO_MEM_SIM_MODEL_BASE 1
#define VIDEO_MEM_SPAN 33554432
#define VIDEO_MEM_STARVATION_INDICATOR 0
#define VIDEO_MEM_TRISTATE_BRIDGE_SLAVE ""
#define VIDEO_MEM_TYPE "altera_avalon_new_sdram_controller"
#define VIDEO_MEM_T_AC 5.5
#define VIDEO_MEM_T_MRD 3
#define VIDEO_MEM_T_RCD 20.0
#define VIDEO_MEM_T_RFC 70.0
#define VIDEO_MEM_T_RP 20.0
#define VIDEO_MEM_T_WR 14.0

#endif /* __SYSTEM_H_ */
