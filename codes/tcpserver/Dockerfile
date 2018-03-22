FROM xuqin:uvbase
COPY /src/ /src/
RUN cd /src && make && make install

FROM alpine:3.7
COPY --from=0 /usr/local/bin/uvtcpserver /usr/local/bin/uvtcpserver
CMD ["uvtcpserver"]
