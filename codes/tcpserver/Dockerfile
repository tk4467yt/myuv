FROM xuqin:uvbase
COPY /src/ /src/
RUN cd /src && make && make install

FROM alpine:3.7
COPY repositories /etc/apk/repositories
RUN apk update
RUN apk add openssl libuv jemalloc
COPY --from=0 /usr/local/bin/uvtcpserver /usr/local/bin/uvtcpserver
CMD ["uvtcpserver"]
