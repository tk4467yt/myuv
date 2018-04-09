.PHONY: all install clean

all:
	g++ tcpserver.cpp -o uvtcpserver /usr/lib/libuv.a /usr/lib/libamqpcpp.a -lpthread -lssl -ldl

install:
	cp uvtcpserver /usr/local/bin/

clean:
	rm -f /usr/local/bin/uvtcpserver
