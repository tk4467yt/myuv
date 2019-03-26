docker container ls --all | grep tls_client | awk '{print $1 }' | xargs docker container rm
