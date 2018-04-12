.PHONY: all install clean

all:
	g++ tcpserver.cpp -o uvtcpserver -luv -ljemalloc -lpthread -lssl -ldl

install:
	cp uvtcpserver /usr/local/bin/

clean:
	rm -f /usr/local/bin/uvtcpserver
