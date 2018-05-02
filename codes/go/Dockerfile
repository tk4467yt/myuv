FROM golang:1.10-alpine3.7
COPY /tls_server/ /gosrcs/
RUN cd /gosrcs && go build tls_server.go

FROM alpine:3.7
COPY --from=0 /gosrcs/tls_server /usr/local/bin/tls_server
COPY /tls_server/server.key /certs/server.key
COPY /tls_server/server.crt /certs/server.crt

CMD ["tls_server"]
