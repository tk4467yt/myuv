#!/bin/bash

#create bridge net
docker network create dnet1
#run rabbitmq
docker run -d --rm --hostname myrabbit --name myrabbitd --network dnet1 -p 5672:5672 -p 5671:5671 rabbitmq

#run rabbitmq consumer
docker run -itd --rm --network dnet1 --name a1  alpine

#run tcpserver
docker run -itd --rm --network dnet1 --name tcpserver -p 7000:7000  xuqin:uvtcpserver
