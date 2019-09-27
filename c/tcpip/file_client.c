#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
#include<fcntl.h>
main(int argc, char **argv) {
	int sd, fd;
	struct sockaddr_in server_info;
	char wrbuf[128], rdbuf[128];
	if (argc != 3) {
		return;
	}
	sd = socket(PF_INET, SOCK_STREAM, 0);
	printf("sd=%d\n", sd);
	server_info.sin_family = PF_INET;
	server_info.sin_port = htons(atoi(argv[1]));
	server_info.sin_addr.s_addr = inet_addr(argv[2]);
	if (connect(sd, (struct sockaddr_in*) &server_info, sizeof(server_info))
			< 0) {
		printf("connect failed\n");
		perror("connect:");
		return;
	}
	printf("connection to server...done...\n");
	printf("Enter the filename to download : ");
	gets(wrbuf);
	send(sd, wrbuf, strlen(wrbuf), 0);
	fd = open(wrbuf, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	while (1) {
		bzero(rdbuf, 128);
		recv(sd, rdbuf, 128, 0);
		if (strcmp(rdbuf, "END_DATA") == 0)
			break;
		write(fd, rdbuf, strlen(rdbuf));
	}
	printf("\nDownload is completed...");
	close(fd);
	close(sd);
}
