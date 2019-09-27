#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>

int main() {

	int sd, new_sd;
	char rdbuf[128];
	struct sockaddr_in client_info, server_info;

	sd = socket(PF_INET, SOCK_STREAM, 0);

	printf("sd  %d\n", sd);

	server_info.sin_family = PF_INET;
	server_info.sin_port = htons(3000);
	server_info.sin_addr.s_addr = inet_addr("0.0.0.0");

	if (bind(sd, (struct sockaddr_in*) &server_info, sizeof(server_info)) < 0) {
		perror("bind");
		return;
	}

	printf("bind successful\n");

	while (1) {

		listen(sd, 3);

		//creats an incomming request
		socklen_t len = sizeof(client_info);

		printf("waiting for client request\n");
		new_sd = accept(sd, (struct sockaddr_in*) &client_info, &len);

		//accept makes the process until a client request reached
		if (new_sd == -1) {
			perror("accept...");
			return;
		}

		if (fork() == 0) {
			printf("client = %s conne  request is accepted..\n",
					inet_ntoa(client_info.sin_addr.s_addr));
			printf("nowserver can communicate to client:");
			printf("with socket descriptor %d\n", new_sd);
			bzero(rdbuf, 128);
			read(new_sd, rdbuf, 127);
			printf("\n\ndata recieved=%s\n\n", rdbuf);
			close(new_sd);
		}
	} //while

	close(sd);

	return 0;
}

