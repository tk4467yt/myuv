FROM nginx
COPY /ssl/ /etc/nginx/ssl/
COPY ssl.conf /etc/nginx/conf.d/
COPY ssl_index.html /usr/share/nginx/html/

CMD ["nginx", "-g", "daemon off;"]
