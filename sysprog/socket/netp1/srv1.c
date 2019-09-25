#include<stdio.h>
#include<sys/socket.h>
#include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <netinet/in.h>

#include<sys/types.h>


int main()
{
 int sockfd,lisfd,retval;
 struct sockaddr_in servaddr,cliaddr;
 socklen_t clilen;
/*step 1 */
 sockfd=socket(AF_INET,SOCK_STREAM,0);
 if(sockfd<0)
 {
  	perror("socket");
        exit(1);
}
/* step 2 */
bzero((struct sockaddr*)&servaddr,sizeof(servaddr));
servaddr.sin_family=AF_INET;
servaddr.sin_port=htons(8000);
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));


lisfd=listen(sockfd,4);

while(1)
{
 clilen=sizeof(cliaddr);
 retval=accept(sockfd,(struct sockaddr*)&cliaddr,&clilen);
 if(retval<0)
 {
    perror("accept");
    exit(1);
}
	printf("client connected with the portnum is %d\n",cliaddr.sin_port);
}
}
