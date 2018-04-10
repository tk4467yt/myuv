#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <uv.h>

#define DEFAULT_PORT 7000
#define DEFAULT_BACKLOG 64

uv_loop_t *loop_server;
struct sockaddr_in addr_server;

typedef struct {
    uv_write_t req;
    uv_buf_t buf;
} write_req_t;

void free_write_req(uv_write_t *req) {
    write_req_t *wr = (write_req_t*) req;
    free(wr->buf.base);
    free(wr);
}

void alloc_buffer(uv_handle_t *handle, size_t suggested_size, uv_buf_t *buf) {
    buf->base = (char*) malloc(suggested_size);
    buf->len = suggested_size;
}

void echo_write(uv_write_t *req, int status) {
    if (status) {
        fprintf(stderr, "Write error %s\n", uv_strerror(status));
    }
    free_write_req(req);
}

void echo_read(uv_stream_t *client, ssize_t nread, const uv_buf_t *buf) {
    if (nread > 0) {
        printf("received and write back: %s\n",buf->base);
        write_req_t *req = (write_req_t*) malloc(sizeof(write_req_t));
        req->buf = uv_buf_init(buf->base, nread);
        uv_write((uv_write_t*) req, client, &req->buf, 1, echo_write);
        return;
    }
    if (nread < 0) {
        if (nread != UV_EOF)
            fprintf(stderr, "Read error %s\n", uv_err_name(nread));
        uv_close((uv_handle_t*) client, NULL);
        free(client);
    }

    free(buf->base);
}

void on_new_connection(uv_stream_t *server, int status) {
    if (status < 0) {
        fprintf(stderr, "New connection error %s\n", uv_strerror(status));
        // error!
        return;
    }

    uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
    uv_tcp_init(loop_server, client);
    if (uv_accept(server, (uv_stream_t*) client) == 0) {
        uv_read_start((uv_stream_t*) client, alloc_buffer, echo_read);
    } else {
        uv_close((uv_handle_t*) client, NULL);
        free(client);
    }
}

void signal_handler(uv_signal_t *req, int signum)
{
    if (SIGINT == signum) {
        printf("SIGINT received!\n");
        uv_loop_close(loop_server);
        exit(0);
    }
}

int main() {
    loop_server = uv_default_loop();

    //setup signal handler
    uv_signal_t sig;
    uv_signal_init(loop_server, &sig);
    uv_signal_start(&sig, signal_handler, SIGINT);

    //setup tcp server
    uv_tcp_t server;
    uv_tcp_init(loop_server, &server);

    uv_ip4_addr("0.0.0.0", DEFAULT_PORT, &addr_server);

    int bindRet=uv_tcp_bind(&server, (const struct sockaddr*)&addr_server, 0);
    if (bindRet < 0) {
        printf("bind error\n");
        return 1;
    }
    int r = uv_listen((uv_stream_t*) &server, DEFAULT_BACKLOG, on_new_connection);
    if (r) {
        fprintf(stderr, "Listen error %s\n", uv_strerror(r));
        return 1;
    }

    //run loop
    int run_ret = uv_run(loop_server, UV_RUN_DEFAULT);

    uv_loop_close(loop_server);
    return run_ret;
}
