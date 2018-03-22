#GCC := gcc

.PHONY: all install clean

all:
	gcc tcpserver.c -o uvtcpserver /usr/local/lib/libuv.a -lpthread

install:
	cp uvtcpserver /usr/local/bin/

clean:
	rm -f /usr/local/bin/uvtcpserver
