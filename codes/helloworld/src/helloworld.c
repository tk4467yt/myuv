#include <stdio.h>
#include <stdlib.h>
#include <uv.h>

uint64_t counter = 0;
void wait_for_a_while(uv_idle_t *idler)
{
	++counter;

	if (counter >= 10e6) {
		printf("idler stop\n");
		uv_idle_stop(idler);
	}
}
int main()
{
	uv_idle_t idler;

	uv_idle_init(uv_default_loop(), &idler);
	uv_idle_start(&idler, wait_for_a_while);

	printf("Idling\n");
	uv_run(uv_default_loop(), UV_RUN_DEFAULT);

	uv_loop_close(uv_default_loop());
	return 0;

	// uv_loop_t *loop = malloc(sizeof(uv_loop_t));
	// uv_loop_init(loop);

	// printf("Now quitting.\n");
	// uv_run(loop, UV_RUN_DEFAULT);

	// uv_loop_close(loop);
	// free(loop);

	// return 0;
}