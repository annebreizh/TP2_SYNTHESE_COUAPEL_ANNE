#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
	
	char *host, *file;
	
	if(argc < 3){
		printf("Usage : %s host file \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	
	else{//recuperation de host et file
		host = argv[1];
		file = argv[2];	
	}
	
	host =host;
	file = file;
	
	return 0;
}
