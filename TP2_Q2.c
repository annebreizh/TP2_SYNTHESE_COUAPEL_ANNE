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
	
	else{
		host = argv[1];
		file = argv[2];	
	}
	
	//recuperation de l'adresse du serveur avec getaddrinfo
    struct addrinfo hints;
    struct addrinfo *result;
    int s;
  

    if (argc != 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* IPv4*/
    hints.ai_socktype = SOCK_STREAM; /* stream socket */
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_UDP; /* config prtocol */

    
    s = getaddrinfo(NULL, argv[1], &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

	host =host;
	file = file;
	
	return 0;
}


