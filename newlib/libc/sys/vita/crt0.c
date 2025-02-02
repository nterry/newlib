extern char _newlib_fd_mutex[32];

int main(int argc, const char* argv[]);

void _init_vita_newlib(void) {
	_init_vita_heap();
	_init_vita_reent();
	_init_vita_malloc();
	sceKernelCreateLwMutex(_newlib_fd_mutex, "fd conversion table mutex", 0, 0, 0);
}

void _free_vita_newlib(void) {
	_free_vita_malloc();
	_free_vita_reent();
	_free_vita_heap();
	sceKernelDeleteLwMutex(_newlib_fd_mutex);
}

void _start() {
	_init_vita_newlib();
	__libc_init_array();
	exit(main(1, (const char*[]){"", 0}));
}
