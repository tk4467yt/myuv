#run with docker
#docker run --rm --network dnet1 xuqin:rabbitmq_producer_python

import pika
import sys

connection = pika.BlockingConnection(pika.ConnectionParameters(host='myrabbitd'))
channel = connection.channel()

channel.exchange_declare(exchange='direct_logs',
                         exchange_type='direct')

severity = 'info'
message = 'Hello World info!'
channel.basic_publish(exchange='direct_logs',
                      routing_key=severity,
                      body=message)
print(" [x] Sent %r:%r" % (severity, message))
connection.close()