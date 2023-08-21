TARGET = posixutils.efi

include .config

include api/Makefile
include main/Makefile
include coreutils/Makefile

CFLAGS = -Iinclude -I.
SRCS = $(SRCS-y)

include uefi/Makefile