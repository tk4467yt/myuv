#!/bin/bash

#run rabbitmq
docker run -d --hostname myrabbit --name myrabbit rabbitmq

#run rabbitmq consumer
docker run -itd --rm --network dnet1 --name a1  alpine

#run tcpserver
docker run -itd --rm --network dnet1 --name tcpserver -p 7000:7000  xuqin:uvtcpserver
