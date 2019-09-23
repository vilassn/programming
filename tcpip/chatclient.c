#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<string.h>
main(int argc, char **argv)
{
 int sd;
 struct sockaddr_in server_info;
 char wrbuf[128], rdbuf[128];
if(argc!=3)
{
 return;
}
sd=socket(PF_INET, SOCK_STREAM,0);
printf("sd=%d\n",sd);
server_info.sin_family=PF_INET;
server_info.sin_port=htons(atoi(argv[1]));
server_info.sin_addr.s_addr=inet_addr(argv[2]);
if(connect(sd,(struct sockaddr_in*)&server_info,sizeof(server_info))<0)
{
 printf("connect failed\n");
 perror("connect:");
 return;
}
 printf("connection to server...done!\n");
 while(1)
 {
  //bzero(wrbuf,128);
  //bzero(rdbuf,128);
  printf("\nClient: ");
  gets(wrbuf);
  write(sd, wrbuf, strlen(wrbuf));
  if(strcmp(wrbuf, "bye")==0)
    break;
  read(sd, rdbuf,127);// strlen(rdbuf));
  printf("\nServer: %s",rdbuf); 
  if(strcmp(rdbuf,"bye")==0)
     break;
 }
 printf("\n chating is over ... my friend ");
 close(sd);
}
