SRCS = $(shell find -name '*.cpp')
HDRS = $(shell find -name '*.h')
STYLEFLAGS = --style=allman --indent-classes --indent-switches

all: huge demo

huge:
	$(MAKE) -C src

demo: huge
	$(MAKE) -C demo

style: $(SRCS) $(HDRS)
	astyle $(STYLEFLAGS) $^

clean:
	$(MAKE) -C src clean
	$(MAKE) -C demo clean

