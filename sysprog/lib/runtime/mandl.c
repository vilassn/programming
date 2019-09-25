
/* Shows how to dynamically load shared objects
Version : 1.0
Author : Team -C
*/

# include <stdio.h>
# include <dlfcn.h>

main(){
	char *ptr;
	void *handle;
	int i;
	int (*fnptr)(int,int);
/*	ptr = (char *)getenv("SO_LIB");
	if(ptr == NULL){
		printf(" Define SO_LIB environment var before invoking\n");
		exit(1);
	}*/
	getchar();
	handle = dlopen("./libxyz.so",RTLD_NOW);
	if(handle == NULL){
		printf(" Failed to load library \n");
		exit(2);
	}
	// get the address of the function somefunc
	fnptr = dlsym(handle,"somefunc");
	getchar();
	// let us call the function now.
	i= (fnptr) (10,20);
	printf(" result of function = %d\n",i);
	dlclose(handle);
	getchar();
}	
