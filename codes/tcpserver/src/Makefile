.PHONY: all install clean

all:
	g++ tcpserver.c -o uvtcpserver /usr/lib/libuv.a /usr/lib/libamqpcpp.a -lpthread -ldl

install:
	cp uvtcpserver /usr/local/bin/

clean:
	rm -f /usr/local/bin/uvtcpserver
