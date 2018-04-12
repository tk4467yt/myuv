FROM golang:alpine
COPY /helloworld/ /gosrcs/
RUN cd /gosrcs && go build helloworld.go

FROM alpine:3.7
COPY --from=0 /gosrcs/helloworld /usr/local/bin/helloworld
CMD ["helloworld"]
