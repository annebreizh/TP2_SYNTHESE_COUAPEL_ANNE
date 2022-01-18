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

#define CMD_SIZE 1500

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
	host =host;
	file = file;
	
	
	//recuperation de l'adresse du serveur avec getaddrinfo
    struct addrinfo hints;
    struct addrinfo *res;
    int s;
  

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;    /* IPv4 */
    hints.ai_socktype = SOCK_DGRAM; /* diagram socket */
    hints.ai_flags = 0;
    hints.ai_protocol = IPPROTO_UDP; /* config protocol */

    
    s = getaddrinfo(argv[1], "69", &hints, &res);//utiliser l'adresse internet, port 69
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
	
	//construction requete en lecture
	char* cmd = malloc(CMD_SIZE);

	cmd[0] = 0;
	cmd[1] = 1;
	char *filename = argv[2];
	strcpy(&cmd[2], filename);
	strcpy(&cmd[2 + strlen(filename) + 1], "octet");

	int size = (int) (2 + strlen(filename) + 1 + strlen("octet") + 1);// on compte deux /0

	//envoie de la demande de fichier au serveur
	int sendSize;
	sendSize = sendto(sfd, cmd, size, res->ai_flags, res->ai_addr, res->ai_addrlen);
	printf("SendTo= %d\n", sendSize);// test avec ensea.png : SendTo =18, ok
	
	if (sendSize == -1) {
		printf("error while sendto: %d\n", sendSize);// question a : recoit bien dans Wireshark 
	}


	//reception d'un fichier 
	struct sockaddr sock_addr;
	int recvSize;
	char espace[CMD_SIZE];
	socklen_t addrsize = sizeof(sock_addr);
	recvSize= recvfrom(sfd, espace, CMD_SIZE, 0,&sock_addr, &addrsize);
	printf("recvffrom=%d\n",recvSize);
	
	if (recvSize==-1){
		printf("error while recvfrom : %d\n",recvSize);
	}
	
	return 0;
}



