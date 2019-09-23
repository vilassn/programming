#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<strings.h>
main()
{
int sd,new_sd;
struct sockaddr_in client_info,server_info;
char rdbuf[128],wrbuf[128];

sd = socket(PF_INET,SOCK_STREAM,0);

printf("sd  %d\n",sd);

server_info.sin_family = PF_INET;
server_info.sin_port = htons(3010);
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
printf("nowserver can communicate to client:\n");
printf("with socket descriptor %d\n",new_sd);
while(1)
{
 bzero(rdbuf,128);
 //bzero(wrbuf,128);
 read(new_sd,rdbuf,127);// strlen(rdbuf));
 printf("\nClient: %s",rdbuf);
 if(strcmp(rdbuf, "bye")==0)
    break;
 printf("\nServer: ");
 gets(wrbuf);
 write(new_sd, wrbuf, strlen(wrbuf));
 if(strcmp(wrbuf,"bye")==0)
    break;
}
printf("\nChating is over...!");
close(new_sd);
close(sd);
}

