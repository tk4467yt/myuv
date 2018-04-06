import pika

#run with docker
#docker run --rm --network dnet1 xuqin:rabbitmq_producer_python

connection = pika.BlockingConnection(pika.ConnectionParameters('myrabbitd'))
channel = connection.channel()

channel.queue_declare(queue='hello')

channel.basic_publish(exchange='',
                      routing_key='hello',
                      body='Hello World!')
print(" [x] Sent 'Hello World!'")

connection.close()