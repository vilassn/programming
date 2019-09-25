#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int main (int argc, char *argv[])
{
    int fd, rc = 0, nbytes, pagesize;
    void *buffer;

    pagesize = getpagesize ();
    nbytes = pagesize;


    rc = posix_memalign (&buffer, pagesize, nbytes);
    /*    buffer = (char *)memalign (pagesize, nbytes);  */

    printf ("rc=%d, buffer=%p, mod pagesize = %ld\n", rc, buffer,(unsigned long)buffer % pagesize);

    fd = open ("/dev/veda_cdrv", O_RDONLY);
    printf ("opened file  with file descriptor = %d\n", fd);
    rc = read (fd, buffer, nbytes);
    printf ("read %d bytes which were:\n%s\n", rc, (char *)buffer);
    close (fd);
    exit (EXIT_SUCCESS);
}
