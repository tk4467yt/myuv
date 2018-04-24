FROM nginx
COPY /ssl/ /etc/nginx/ssl/
COPY ssl.conf /etc/nginx/conf.d/

CMD ["nginx", "-g", "daemon off;"]
