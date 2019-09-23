/*

 Check core dump enabled:

 ulimit -a

 One of the lines should be :

 core file size          (blocks, -c) unlimited

 If not :

 gedit ~/.bashrc and add ulimit -c unlimited to end of file and save, re-run terminal.

 Build your application with debug information :

 In Makefile -O0  -g

 Run application that create core dump (core dump file with name ‘core’ should be created near application_name file):

 ./application_name

 Run under gdb:

 gdb application_name core

 */

#include <stdio.h>

int main() {

	printf("core dump example\n");

	int a = 10;
	int *p = &a;
	*p = 0;
	*p = 1;

	return 0;
}

