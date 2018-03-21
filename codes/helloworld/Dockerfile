FROM xuqin:uvbase
COPY /src/ /src/
RUN cd /src && make && make install

FROM ubuntu:16.04
COPY --from=0 /usr/local/bin/uvhello /usr/local/bin/uvhello
CMD ["uvhello"]
