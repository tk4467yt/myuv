FROM golang:1.10-alpine3.7
COPY /tls_server/ /go/tls_server/
RUN cd /go/tls_server && go build 

FROM alpine:3.7
COPY --from=0 /go/tls_server/tls_server /usr/local/bin/tls_server
COPY /tls_server/server.key /certs/server.key
COPY /tls_server/server.crt /certs/server.crt

CMD ["tls_server"]
