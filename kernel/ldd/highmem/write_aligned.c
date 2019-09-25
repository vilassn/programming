#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <sys/stat.h>

#define STRING "TESTING DRIVER WITH A WRITE"

int main (int argc, char *argv[])
{
    int fd, rc = 0, size, pagesize;
    void *buffer;
    size = strlen (STRING) + 1; /* leave room for \0 */
    pagesize = getpagesize ();
    rc = posix_memalign (&buffer, pagesize, size);
    /*    buffer = (char *)memalign (pagesize, size); */
    printf ("rc=%d, buffer=%p, mod pagesize = %ld\n", rc, buffer,(unsigned long)buffer % pagesize);
    strcpy (buffer, STRING);
    fd = open ("/dev/veda_cdrv", O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
    printf ("opened file with file descriptor = %d\n", fd);
    rc = write (fd, buffer, strlen (buffer)+ 1);
    printf ("wrote %d bytes which were:\n%s\n", rc, (char *)buffer);
    close (fd);
    exit (EXIT_SUCCESS);
}
