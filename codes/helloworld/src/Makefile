#GCC := gcc

.PHONY: all install clean

all:
	gcc helloworld.c -o uvhello /usr/local/lib/libuv.a -lpthread

install:
	cp uvhello /usr/local/bin/

clean:
	rm -f /usr/local/bin/uvhello
