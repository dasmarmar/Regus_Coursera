#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This Makefile describes a build system that supports two targets, the HOST system
# and an MSP432 ARM microcontroller. Compiles and links user files and MSP432 system 
# files into a final executable c1m2.out.
#
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      	
#      	%.asm - Assembly File
#	%.i   - Preprocessor output
#	%.d   - Include header dependency file
#	%.o   - Object File
#	
#	
#	compile-all - Compile all target files but do not link
#	
#	build       - Compile all files and link into final executable c1m2.out
#		      Also outputs c1m2.asm, all .d dependency files, and provides
#		      build report using the SIZE tool
#
#	clean       - Deletes all target files 		
#
# Platform Overrides:
#      
#      Supports two platforms:
#      PLATFORM=HOST 	- The host platform compiler = gcc
#      PLATFORM=MSP432  - MSP432 ARM microcontroller compiler = arm-none-eabi-gcc
#
#------------------------------------------------------------------------------
include sources.mk

TARGET = c1m2

# Platform Overrides

ifeq ($(PLATFORM), HOST)

PLATFORM = HOST

CC = gcc
LD = gcc
SIZE = size
ASMDUMP = objdump
LDFLAGS = -Wl,-Map=$(TARGET).map 
CFLAGS = -std=c99 -g -Wall -Werror -O0 -MD
CPPFLAGS = -D$(PLATFORM)


OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d) 


%.asm: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDES) -S -o $@ $<


%.i: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDES) -E -o $@ $<


%.d: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -I$(INCLUDES) -MD -E -o $@ $<

%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I$(INCLUDES) -o $@ $<


endif

ifeq ($(PLATFORM), MSP432)

PLATFORM = MSP432

# Architectures Specific Flags

LINKER_FILE = msp432p401r.lds

CPU = cortex-m4
ARCH = armv7e-m
FPU = fpv4-sp-d16
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE = arm-none-eabi-size
ASMDUMP = arm-none-eabi-objdump
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -std=c99 -Wall -Werror -mthumb -mcpu=$(CPU) -mfpu=$(FPU) -march=$(ARCH) --specs=$(SPECS) -O0 -MD
CPPFLAGS = -D$(PLATFORM)

OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)

%.asm: %.c
	$(CC) $< $(CFLAGS) -I$(INCLUDE1) -I$(INCLUDE2) -I$(INCLUDE3) $(CPPFLAGS) -S -o $@


%.i: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE1) -I$(INCLUDE2) -I$(INCLUDE3) $(CPPFLAGS) -E -o $@ $<


%.d: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE1) -I$(INCLUDE2) -I$(INCLUDE3) $(CPPFLAGS) -MD -E -o $@ $<


%.o: %.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -I$(INCLUDE1) -I$(INCLUDE2) -I$(INCLUDE3) -o $@ $<



endif


.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) -c $(OBJS) $(CFLAGS) $(CPPLAGS) -o $@


.PHONY:
build: $(TARGET).out
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $(TARGET).out
	$(SIZE) $(TARGET).out > $(TARGET).txt
	$(ASMDUMP) -D $(TARGET).out > $(TARGET).asm	

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(TARGET).map $(TARGET).out $(TARGET).asm $(TARGET).txt


