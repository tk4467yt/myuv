FROM alpine:3.7
COPY repositories /etc/apk/repositories
RUN apk update
RUN apk upgrade
RUN apk add build-base gcc make automake autoconf libtool openssl-dev m4 libuv-dev 

COPY AMQP-CPP-master/ /AMQP-CPP-master/
RUN cd /AMQP-CPP-master && make && make install

#COPY libuv-v1.19.2/ /libuv/
#RUN cd /libuv && ./autogen.sh && ./configure && make && make install
