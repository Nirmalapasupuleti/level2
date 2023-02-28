//program to demonstrate client program

//Hedar file decleration
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
//It contain a typedef symbols and structures
#include<sys/types.h>
//It contains definations for the internet protpocol family
#include<netinet/in.h>
//It contain definitions for internet operations
#include<arpa/inet.h>
//Port number decleration 
#define PORT 9898

int main(){
//Initializing a variable
	int clientsocket,ret;
	struct sockaddr_in cliAddr,serverAddr;
	//DEclearing the buffer
	char buffer[1024];
// This call results in a stream socket with the tcp protocol
	clientsocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientsocket < 0){
		printf("error in connection..\n");
		exit(1);
	}
	printf("client socket is created..\n");
        //Initializing socket struct with NULL
	//memset(&cliAddr, '\0', sizeof(cliAddr));
	//INitializing buffer array with NULL
	//memset() is used to fill a block of memory with a particular value
	memset(&cliAddr, '\0', sizeof(buffer));
	//ip address from internet family IPV4
	serverAddr.sin_family = AF_INET;
        //Initilizing the port
	serverAddr.sin_port = htons(PORT);
	//Assigning the local ip address
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
        //Connecting a client socket with server
	ret = connect(clientsocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	if(ret < 0){
		printf("error in connection...\n");
		exit(1);
	}
	printf("connect to server..\n");

	while(1)
	{
	        bzero(buffer, sizeof(buffer));
		printf("To server:\t");
		//scanf("%s", &buffer[0]);
		int n=0;
		while((buffer[n++]=getchar())!= '\n');
		//Writing a client data
		write(clientsocket,buffer,sizeof(buffer));
		 //send(clientsocket, buffer, strlen(buffer),0);
		 //Reading a data 
	         read(clientsocket, buffer,sizeof(buffer));
                 printf("server: \t%s\n",buffer);
	}


	return 0;
}


