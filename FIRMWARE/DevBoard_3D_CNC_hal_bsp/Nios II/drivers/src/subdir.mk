################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../drivers/src/altera_avalon_cfi_flash.c \
../drivers/src/altera_avalon_cfi_flash_amd.c \
../drivers/src/altera_avalon_cfi_flash_intel.c \
../drivers/src/altera_avalon_cfi_flash_table.c \
../drivers/src/altera_avalon_jtag_uart_fd.c \
../drivers/src/altera_avalon_jtag_uart_init.c \
../drivers/src/altera_avalon_jtag_uart_ioctl.c \
../drivers/src/altera_avalon_jtag_uart_read.c \
../drivers/src/altera_avalon_jtag_uart_write.c \
../drivers/src/altera_avalon_lcd_16207.c \
../drivers/src/altera_avalon_lcd_16207_fd.c \
../drivers/src/altera_avalon_mutex.c \
../drivers/src/altera_avalon_sysid_qsys.c \
../drivers/src/altera_avalon_timer_sc.c \
../drivers/src/altera_avalon_timer_ts.c \
../drivers/src/altera_avalon_timer_vars.c \
../drivers/src/altera_avalon_uart_fd.c \
../drivers/src/altera_avalon_uart_init.c \
../drivers/src/altera_avalon_uart_ioctl.c \
../drivers/src/altera_avalon_uart_read.c \
../drivers/src/altera_avalon_uart_write.c \
../drivers/src/altera_vic.c \
../drivers/src/altera_vic_irq_init.c \
../drivers/src/altera_vic_isr_register.c \
../drivers/src/altera_vic_set_level.c \
../drivers/src/altera_vic_sw_intr.c 

S_UPPER_SRCS += \
../drivers/src/altera_interrupt_vector_tbl.S \
../drivers/src/altera_vic_funnel_non_preemptive.S \
../drivers/src/altera_vic_funnel_non_preemptive_nmi.S \
../drivers/src/altera_vic_funnel_preemptive.S 

OBJS += \
./drivers/src/altera_avalon_cfi_flash.o \
./drivers/src/altera_avalon_cfi_flash_amd.o \
./drivers/src/altera_avalon_cfi_flash_intel.o \
./drivers/src/altera_avalon_cfi_flash_table.o \
./drivers/src/altera_avalon_jtag_uart_fd.o \
./drivers/src/altera_avalon_jtag_uart_init.o \
./drivers/src/altera_avalon_jtag_uart_ioctl.o \
./drivers/src/altera_avalon_jtag_uart_read.o \
./drivers/src/altera_avalon_jtag_uart_write.o \
./drivers/src/altera_avalon_lcd_16207.o \
./drivers/src/altera_avalon_lcd_16207_fd.o \
./drivers/src/altera_avalon_mutex.o \
./drivers/src/altera_avalon_sysid_qsys.o \
./drivers/src/altera_avalon_timer_sc.o \
./drivers/src/altera_avalon_timer_ts.o \
./drivers/src/altera_avalon_timer_vars.o \
./drivers/src/altera_avalon_uart_fd.o \
./drivers/src/altera_avalon_uart_init.o \
./drivers/src/altera_avalon_uart_ioctl.o \
./drivers/src/altera_avalon_uart_read.o \
./drivers/src/altera_avalon_uart_write.o \
./drivers/src/altera_interrupt_vector_tbl.o \
./drivers/src/altera_vic.o \
./drivers/src/altera_vic_funnel_non_preemptive.o \
./drivers/src/altera_vic_funnel_non_preemptive_nmi.o \
./drivers/src/altera_vic_funnel_preemptive.o \
./drivers/src/altera_vic_irq_init.o \
./drivers/src/altera_vic_isr_register.o \
./drivers/src/altera_vic_set_level.o \
./drivers/src/altera_vic_sw_intr.o 

C_DEPS += \
./drivers/src/altera_avalon_cfi_flash.d \
./drivers/src/altera_avalon_cfi_flash_amd.d \
./drivers/src/altera_avalon_cfi_flash_intel.d \
./drivers/src/altera_avalon_cfi_flash_table.d \
./drivers/src/altera_avalon_jtag_uart_fd.d \
./drivers/src/altera_avalon_jtag_uart_init.d \
./drivers/src/altera_avalon_jtag_uart_ioctl.d \
./drivers/src/altera_avalon_jtag_uart_read.d \
./drivers/src/altera_avalon_jtag_uart_write.d \
./drivers/src/altera_avalon_lcd_16207.d \
./drivers/src/altera_avalon_lcd_16207_fd.d \
./drivers/src/altera_avalon_mutex.d \
./drivers/src/altera_avalon_sysid_qsys.d \
./drivers/src/altera_avalon_timer_sc.d \
./drivers/src/altera_avalon_timer_ts.d \
./drivers/src/altera_avalon_timer_vars.d \
./drivers/src/altera_avalon_uart_fd.d \
./drivers/src/altera_avalon_uart_init.d \
./drivers/src/altera_avalon_uart_ioctl.d \
./drivers/src/altera_avalon_uart_read.d \
./drivers/src/altera_avalon_uart_write.d \
./drivers/src/altera_vic.d \
./drivers/src/altera_vic_irq_init.d \
./drivers/src/altera_vic_isr_register.d \
./drivers/src/altera_vic_set_level.d \
./drivers/src/altera_vic_sw_intr.d 


# Each subdirectory must supply rules for building sources it contributes
drivers/src/%.o: ../drivers/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C Compiler'
	gcc -U__INT_FAST32_MAX__ -U__SIG_ATOMIC_MAX__ -U__FLT_EPSILON__ -U__DEC64_MANT_DIG__ -U__DBL_MIN__ -U__INT_LEAST64_TYPE__ -U__SCHAR_MAX__ -U__DEC128_MANT_DIG__ -U__UINTPTR_TYPE__ -U__DBL_MIN_10_EXP__ -U__unix__ -U__DBL_DENORM_MIN__ -U_stdcall -U__SHRT_MAX__ -U__DBL_HAS_DENORM__ -U__SIZEOF_WCHAR_T__ -U__SIZEOF_PTRDIFF_T__ -U__GXX_TYPEINFO_EQUALITY_INLINE -U__DEC32_MAX__ -U__SIZEOF_DOUBLE__ -U__FLT_MIN_EXP__ -U__LDBL_MANT_DIG__ -U__DEC32_EPSILON__ -U__INTPTR_MAX__ -U__LDBL_DIG__ -U__INT_LEAST8_MAX__ -U__LDBL_DENORM_MIN__ -U__DEC32_MIN_EXP__ -U__DEC128_MAX__ -U__INT_FAST8_MAX__ -U__UINT_LEAST8_MAX__ -U__cdecl -U__GNUC_PATCHLEVEL__ -U__DEC32_SUBNORMAL_MIN__ -U__SIZEOF_POINTER__ -U__WINT_MAX__ -U__LDBL_HAS_INFINITY__ -U__FLT_MAX_10_EXP__ -U__DEC64_MIN_EXP__ -U__CYGWIN32__ -U__DEC32_MIN__ -U__LDBL_MIN_10_EXP__ -U__i386 -U__SIZEOF_LONG_LONG__ -U__UINT_FAST8_MAX__ -U__DEC64_MAX_EXP__ -U__GXX_MERGED_TYPEINFO_NAMES -U__INT16_MAX__ -U__UINT16_C(c) -U__LDBL_MAX_EXP__ -U__UINT_LEAST64_MAX__ -U__FLT_MANT_DIG__ -U__FLT_RADIX__ -U__INTMAX_C(c) -U__FLT_DIG__ -U__UINT8_MAX__ -U__INTMAX_TYPE__ -U__LDBL_MIN_EXP__ -U__INT_LEAST32_TYPE__ -U__pentiumpro__ -U__UINT32_MAX__ -U__i686 -U__LONG_LONG_MAX__ -U__DBL_HAS_INFINITY__ -U__UINT32_C(c) -U__DBL_MAX_10_EXP__ -U__FLT_HAS_QUIET_NAN__ -U__SIG_ATOMIC_TYPE__ -U__FLT_HAS_DENORM__ -U__NO_INLINE__ -U__INT_LEAST16_MAX__ -U__DEC128_EPSILON__ -U__GNUC__ -U__INT_LEAST8_TYPE__ -U__unix -U__DEC128_MIN_EXP__ -U__fastcall -U__UINT_FAST64_TYPE__ -U__INTPTR_TYPE__ -U__INT64_TYPE__ -U__DBL_MAX_EXP__ -U__WINT_TYPE__ -U__DEC64_SUBNORMAL_MIN__ -U__INT_FAST32_TYPE__ -U__UINT_FAST8_TYPE__ -U__PTRDIFF_MAX__ -U__INT_LEAST16_TYPE__ -U__SIZE_TYPE__ -U__DEC32_MANT_DIG__ -U__DBL_MAX__ -U__i686__ -U__INT_FAST16_MAX__ -U__UINT16_MAX__ -U__UINT_LEAST8_TYPE__ -U__UINT_FAST32_TYPE__ -Uunix -U__stdcall -U__FLT_EVAL_METHOD__ -U_X86_ -U__UINT16_TYPE__ -U__UINT32_TYPE__ -U__PRAGMA_REDEFINE_EXTNAME -U__FLT_MAX_EXP__ -U__UINT_FAST16_MAX__ -U__LDBL_EPSILON__ -U__DEC64_MIN__ -U__UINT64_C(c) -U__REGISTER_PREFIX__ -U__INT_FAST8_TYPE__ -U__LDBL_HAS_QUIET_NAN__ -U__INT8_MAX__ -U__FLT_DENORM_MIN__ -U__CHAR32_TYPE__ -U__WCHAR_MIN__ -U__CYGWIN__ -U__UINTMAX_MAX__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 -Ui386 -U__FLT_MIN_10_EXP__ -U__UINTPTR_MAX__ -U__UINT64_MAX__ -U__WCHAR_MAX__ -U__INT_FAST16_TYPE__ -U__LDBL_HAS_DENORM__ -U__GXX_ABI_VERSION -U__UINTMAX_C(c) -U__INT_LEAST64_MAX__ -U__DBL_MIN_EXP__ -U__UINT_LEAST32_TYPE__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 -U__SIZEOF_LONG_DOUBLE__ -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 -U__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 -U__SIZE_MAX__ -U__UINT_FAST32_MAX__ -U__INT_FAST64_MAX__ -U_cdecl -U__SIG_ATOMIC_MIN__ -U__FLT_MIN__ -U__DBL_EPSILON__ -U__UINT_FAST64_MAX__ -U__DEC128_MAX_EXP__ -U__SIZEOF_SIZE_T__ -U__DBL_DIG__ -U__UINT_LEAST16_MAX__ -U__GNUC_MINOR__ -U__DEC64_MAX__ -U__BIGGEST_ALIGNMENT__ -U__UINT_LEAST16_TYPE__ -U__WINT_MIN__ -U__INT16_C(c) -U__INT64_MAX__ -U__INT_MAX__ -U__DEC64_EPSILON__ -U__INT32_C(c) -U__INT32_TYPE__ -U__INT_LEAST32_MAX__ -U__STDC__ -U__LDBL_MIN__ -U__INT8_TYPE__ -U__SIZEOF_FLOAT__ -U__INTMAX_MAX__ -U__INT_FAST64_TYPE__ -U__UINT64_TYPE__ -U__DEC32_MAX_EXP__ -U__VERSION__ -U__INT32_MAX__ -U__INT64_C(c) -U__SIZEOF_WINT_T__ -U__SIZEOF_INT__ -U__USER_LABEL_PREFIX__ -U__LONG_MAX__ -U__pentiumpro -U__INT8_C(c) -U__INT16_TYPE__ -U__UINT_LEAST32_MAX__ -U__PTRDIFF_TYPE__ -U__UINT8_C(c) -U__i386__ -U__CHAR_BIT__ -U__DEC128_SUBNORMAL_MIN__ -U__DBL_HAS_QUIET_NAN__ -U__SIZEOF_SHORT__ -U__DEC_EVAL_METHOD__ -U__FLT_MAX__ -U__DBL_MANT_DIG__ -U__UINT_FAST16_TYPE__ -U__UINT_LEAST64_TYPE__ -U__DEC128_MIN__ -U__GNUC_GNU_INLINE__ -U_fastcall -U__declspec(x) -U__FLT_HAS_INFINITY__ -U__UINT8_TYPE__ -U__STDC_HOSTED__ -U__DECIMAL_DIG__ -U__LDBL_MAX_10_EXP__ -U__SIZEOF_LONG__ -U__UINTMAX_TYPE__ -U__LDBL_MAX__ -U__FINITE_MATH_ONLY__ -U__WCHAR_TYPE__ -U__CHAR16_TYPE__ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

drivers/src/%.o: ../drivers/src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


