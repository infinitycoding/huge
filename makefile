OS=$(shell uname -s)
ifeq ($(OS), Linux)
include makefile.linux
endif

