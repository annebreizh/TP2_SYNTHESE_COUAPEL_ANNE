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
    struct addrinfo *res;
    int s;
  

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* IPv4 */
    hints.ai_socktype = SOCK_DGRAM; /* stream socket */
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_UDP; /* config prtocol */

    
    s = getaddrinfo(argv[1], "69", &hints, &res);//utiliser l'adresse internet
    if (s) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

	//création d'un socket de connexion vers le serveur
	
	int sfd = socket(res->ai_family,res->ai_socktype,res->ai_protocol);
	
	if (sfd==-1) {
		fprintf(stderr, "Error : %s n'a pas reussi à se connecter vers le secteur %s\n", argv[0], argv[1]);
		exit(EXIT_FAILURE);
	}
	

	host =host;
	file = file;
	
	return 0;
}

