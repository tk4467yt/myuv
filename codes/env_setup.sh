#!/bin/bash

#run zookeeper

#run kafka
docker run -itd --rm --network dnet1 --name a1  alpine

#run kafka consumer

#run tcpserver
docker run -itd --rm --network dnet1 --name tcpserver -p 7000:7000  xuqin:uvtcpserver
