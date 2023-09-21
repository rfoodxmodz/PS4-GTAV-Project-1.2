#include "types.h"
#include "imports.h"


//notifications
int (*sceSysUtilSendSystemNotificationWithText)(int messageType, const char *message);
#define resolve(module, name) orbis_syscall(591, module, #name, &name);

//libc
void *(*mmap)(void *addr, size_t len, int prot, int	flags, int fd, off_t offset);
//int(*access)(const char *path, int mode);
int(*open)(const char *path, int flags, ...);
int(*islower)(int c);
int(*toupper)(int c);
int(*tolower)(int c);

int getpid() {
	return orbis_syscall(20);
}

void *sys_mmap(void *addr, size_t len, int prot, int flags, int fd, off_t offset) {
	return (void *)orbis_syscall(477, addr, len, prot, flags, fd, offset);
}

void *sys_munmap(void *addr, size_t len) {
	return (void *)orbis_syscall(479, addr, len);
}



void initImports() {
	int h = 0;
	//libc
	sys_dynlib_load_prx("libSceLibcInternal.sprx", &h);
	sys_dynlib_dlsym(h, "isspace", &isspace);
	sys_dynlib_dlsym(h, "isupper", &isupper);
	sys_dynlib_dlsym(h, "islower", &islower);
	sys_dynlib_dlsym(h, "toupper", &toupper);

	//notify
	int sysUtilHandle = sceKernelLoadStartModule("libSceSysUtil.sprx", 0, NULL, 0, 0, 0);
	sys_dynlib_dlsym(sysUtilHandle, "sceSysUtilSendSystemNotificationWithText", &sceSysUtilSendSystemNotificationWithText);
	
	//libc
	int sysLibc = sceKernelLoadStartModule("libSceLibcInternal.sprx", 0, NULL, 0, 0, 0);
	sys_dynlib_dlsym(sysLibc, "tolower", &tolower);
}
