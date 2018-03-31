FROM alpine:3.7
COPY repositories /etc/apk/repositories
RUN apk update
RUN apk upgrade
RUN apk add build-base gcc make automake autoconf libtool openssl m4 libuv libuv-dev librdkafka-dev


#COPY libuv-v1.19.2/ /libuv/
#RUN cd /libuv && ./autogen.sh && ./configure && make && make install
