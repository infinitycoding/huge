all: huge demo

huge:
	$(MAKE) -C src

demo: huge
	$(MAKE) -C demo

clean:
	$(MAKE) -C src clean
	$(MAKE) -C demo clean

