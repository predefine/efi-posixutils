TARGET = posixutils.efi

include .config

include api/Makefile
include main/Makefile
include coreutils/Makefile

CFLAGS = -Iinclude -I.
SRCS = $(SRCS-y)

all: config.h $(TARGET)
config.h: .config
	scripts/config_to_header.sh .config config.h

include uefi/Makefile