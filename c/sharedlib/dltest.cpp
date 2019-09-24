#include <stdio.h>
#include <dlfcn.h>

typedef int (*foo)(void);
void* mHandle;

class Temp {
public:
	Temp() {
		printf("In Temp()\n");

		foo func;
		mHandle = dlopen("libfoo.so", RTLD_LAZY);
		func = (foo) dlsym(mHandle, "foo");

		printf("dlerror: %s\n", dlerror());

		printf("Temp(), RetVal = %d\n", func());
	}

	~Temp() {
		printf("In ~Temp()\n");
		dlclose(mHandle);
	}
};

int main() {
	Temp p;
	return 0;
}
