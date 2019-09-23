#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<fcntl.h>
main()
{
int sd,new_sd,fd,portno;
struct sockaddr_in client_info,server_info;
char rdbuf[128], wrbuf[128];

sd = socket(PF_INET,SOCK_STREAM,0);

printf("sd  %d\n",sd);
printf("Enter the port no. for server: ");
scanf("%d",&portno);
server_info.sin_family = PF_INET;
server_info.sin_port = htons(portno);
server_info.sin_addr.s_addr = inet_addr("0.0.0.0");

if(bind(sd,(struct sockaddr_in*)&server_info,sizeof(server_info))<0)
{
perror("bind");
return;
}
printf("bind successful\n");
listen(sd,3);
//creats an incomming request
socklen_t len= sizeof(client_info);
printf("waiting for client request\n");
new_sd=accept(sd,(struct sockaddr_in*)&client_info,&len);
//accept.makes the process untill a client request reached
if(new_sd==-1)
{
perror("accept..:");
return;
}
printf("client connection request is accepted..\n");
printf("nowserver can communicate to client:");
printf("\nwith socket descriptor %d\n",new_sd);
bzero(rdbuf,128);
read(new_sd,rdbuf,127);
fd=open(rdbuf, O_RDONLY);
while(read(fd,wrbuf,127))
{
 send(new_sd, wrbuf, strlen(wrbuf),0);
 bzero(wrbuf, 128);
}
close(fd);
send(new_sd, "END_DATA", 8, 0);
close(new_sd);
close(sd);
}

