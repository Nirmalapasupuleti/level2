/*program to demonstrate server socket program*/
//Header file decleration
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>

//defining a port number
#define PORT 9898
int count=0;
int client;
int num,cnt,n;
int main(){

	int sockfd, ret,buffer1[1025];
	//It deal with internet address
	struct sockaddr_in serverAddr;
        //length and size values used by socket related parameters
	socklen_t addr_size;
        //initializing a variable
	int newsocket;
	struct sockaddr_in newAddr;

	char buffer[1024];
	pid_t childpid;
        //providing the underlying communication
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	//The socket file fd is less than zero it will directly go to the error in connection
	if(sockfd < 0){
		printf("error in connection..\n");
		exit(1);
	}
	printf("server socket is created..\n");

        //It is used to fill a block of memory with a particular value 
	memset(&serverAddr, '\0', sizeof(serverAddr));
	//match the socket()call
	serverAddr.sin_family = AF_INET;
	//specify any port to listen
	serverAddr.sin_port = htons(PORT);
	//bind to any local address
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //This is for binding
	ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("error in binding.\n");
		exit(1);
	}
	printf("bind to port %d\n",PORT);
	//As a socket that will be used to accept incoming connection requests
        if(listen(sockfd, 10)==0){
		printf("listening..\n");
	}
	else
	{
		printf("error in binding..\n");
	}
	//int cnt;


	while(1){
		//accepting a connection
		newsocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
		if(newsocket < 0){
			exit(1);
		}
		
/*		int buf;

		for( int i=0;buf[i]!='\0';i++)

			if(buf[i] >= 'a' && buf[i] <= 'z')
			{
				buf[i] = buf[i] -32;
			}*/
		printf("connection accepted from %s:%d\n",inet_ntoa(newAddr.sin_addr),ntohs(newAddr.sin_port));

		printf("client : %d\n",count++);
		{
			//int num,var;
			//switching the message which client want to connect
			//printf("which client we want to communicate..\n");
                 	//scanf("%d",&num);
			/*int num=10;
			switch(num)		
			{
				//printf("which client we want to select..\n");
				//scanf("%d\n",&num);
				case 1 : printf("writing on client 1\n");
                                         //while((buffer[n++]=getchar())!='\n')

					 write(newsocket, buffer, sizeof(buffer));
					 printf("1 newsocket %d", newsocket);
					 cnt--;
                                      
				        break;
				     

				case 2 : printf("writing on client 2");
					 //while((buffer[n++]=getchar())!='\n')

					write(newsocket, buffer, sizeof(buffer));
					printf("3 newsocket %d\n",newsocket);
					cnt--;

				      
				        break;
				case 3: printf("writing on client 3");
					//while((buffer[n++]=getchar())!='\n')
					write(newsocket, buffer, sizeof(buffer));
					printf("newsocket %d\n",newsocket);

				        break;

				default: printf("invalid ..\n");

				       
			}*/
		}	
	//printf("which client we want to communicate\n");
//scanf("%d\n",&num);	
               //using forking for multiple clients
		if((childpid = fork()) ==0){
                       //It is for printing the pid and ppid
			printf("pid =%d\n",getpid());
			close(sockfd);

			while(1){

			


				bzero(buffer,sizeof(buffer));


				//recv(newsocket, buffer,1024,0);
			        read(newsocket,buffer,sizeof(buffer));	
					for(int i=0; buffer[i]!='\0'; i++)
{                                       //converting lower case
					if(buffer[i] >='a' && buffer[i] <='z')
					{
						buffer[i] = buffer[i] -32;
					}
					//converting upper case
					else if(buffer[i]>='A' && buffer[i]<='Z')
					{
						buffer[i] = buffer[i]+32;
					}
                               
}
				printf(" from client %d: %s \t to client:",count,buffer);
				


		
			 
				bzero(buffer,sizeof(buffer));
				int n=0;
				while((buffer[n++]=getchar())!='\n');
                                write(newsocket,buffer,sizeof(buffer));

			}
		}
	}
	close(newsocket);
	 
	return 0;
}
