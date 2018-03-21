FROM ubuntu:16.04
RUN apt-get update -y && apt-get upgrade -y 
RUN apt-get install -y  automake  libtool make openssl
COPY libuv-v1.19.2/ /libuv/
RUN cd /libuv && ./autogen.sh && ./configure && make && make install
