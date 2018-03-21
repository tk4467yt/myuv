FROM alpine:3.7
RUN apk update
RUN apk add build-base gcc make automake libtool openssl m4
RUN apk add autoconf
COPY libuv-v1.19.2/ /libuv/
RUN cd /libuv && ./autogen.sh && ./configure && make && make install
