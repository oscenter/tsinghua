# we will generate libcommon.so, and set its attribute to RTLD_LAZY|RTLD_GLOBAL) when use dlopen to load it.
common_breakpoint = breakpoint/breakpoint.c
common_misc = misc/support.c
common_module = module/skyeye_module.c
common_ctrl = ctrl/thread_ctrl.c ctrl/sim_ctrl.c ctrl/step.c
common_conf_parser = conf_parser/skyeye_options.c conf_parser/skyeye_config.c conf_parser/misc_options.c
common_log = log/skyeye_log.c
common_loader = loader/loader_elf.c loader/loader_file.c
common_mm = mm/skyeye_mm.c
common_cli = cli/skyeye_command.c cli/skyeye_cli.c cli/default_command.c
common_portable = portable/mman.c portable/usleep.c portable/gettimeofday.c
common_preference = preference/skyeye_pref.c
common_memory = bus/bank_ops.c  bus/io.c  bus/ram.c bus/flash.c bus/skyeye_bus.c
common_core = core/skyeye_arch.c
common_device = device/skyeye_device.c device/pen_buffer.c device/skyeye_uart_ops.c
common_mach = mach/skyeye_mach.c
common_callback = callback/callback.c

pkglib_LTLIBRARIES = libcommon.la

nobase_include_HEADERS = ./include/sim_control.h ./include/skyeye_callback.h \
./include/skyeye_types.h ./include/skyeye_module.h ./include/int_register.h \
./include/skyeye_log.h ./include/skyeye_arch.h ./include/skyeye_loader.h \
./include/skyeye_uart_ops.h  ./include/memory_space.h ./include/skyeye_uart.h \
./include/breakpoint.h ./include/skyeye_api.h ./include/skyeye_misc.h \
./include/arch_regdefs.h ./include/skyeye_config.h ./include/skyeye_device.h \
./include/skyeye.h ./include/io_memory.h ./include/memory.h ./include/skyeye_mm.h \
./include/skyeye_options.h ./include/skyeye_mach.h ./include/skyeye_pref.h \
./include/portable/mman.h ./include/portable/usleep.h ./include/skyeye_ram.h

libcommon_la_SOURCES = $(common_module) $(common_misc) $(common_breakpoint) $(common_ctrl) $(common_portable) $(common_preference) $(common_core) $(common_conf_parser) $(common_log) $(common_cli) $(common_mm) $(common_mach) $(common_device) $(common_memory) $(common_loader) $(common_callback)

libcommon_la_LIBADD = -L$(top_srcdir)/third-party/bfd/.libs/ -lbfd -L$(top_srcdir)/third-party/libiberty/pic -liberty -lreadline @LIBLTDL@ @LIBADD_DL@

if WIN32
else
libcommon_la_LIBADD += -L$(top_srcdir)/third-party/readline/ 
endif
# we will link the common module with main
#libcommon_la_LDFLAGS = -module

DEFS = -g -O2 -D_FILE_OFFSET_BITS=64 -DSTANDALONE -DDEFAULT_INLINE=0 

INCLUDES =  @COMMON_INCLUDES@ -I$(top_srcdir)/third-party/include/ -I$(top_srcdir)/third-party/bfd/ -I$(top_srcdir)/third-party @INCLTDL@

if LCD
INCLUDES += @LCD_CFLAGS@
endif 
