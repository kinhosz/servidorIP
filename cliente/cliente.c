#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"

#define two 2
#define one 1
#define dif !=
#define asp ""
#define SERVER_IP "192.168.0.20"

enum conn_ret_t ans;

void game_start(){

	fprintf(stderr,"Hello world\n");

	int tsize,size;
	char *msg;

	msg = (char *) malloc(sizeof(char) * 50);

	int option = DONT_WAIT;
	int ok = one;
	while(ok){
		size = recvMsgFromServer(msg,option);
		if(size == SERVER_DISCONNECTED){
			ok = 0;
		}
	}

	free(msg);
}

int main(){

	int try = 1;
	while(try){
		system("clear");
		ans = connectToServer(NULL);
		if(ans == SERVER_UP){
			fprintf(stderr,"conexao estabelecida!\n");
			game_start();
		}
		else if(ans == SERVER_DOWN){
			fprintf(stderr,"Servidor nao encontrado\n");
		}
		else if(ans == SERVER_FULL){
			fprintf(stderr,"Capacidade maxima do servidor atingida\n");
		}
		else if(ans == SERVER_CLOSED){
			fprintf(stderr,"Servidor fechado para novas conexoes\n");
		}
		else if(ans == SERVER_TIMEOUT){
			fprintf(stderr,"Tempo esgotado - o servidor nao respondeu\n");
		}
		fprintf(stderr,"tente novamente ? y/n\n");
		char r;
		fscanf(stdin,"%c",&r);
		if(r == 'n' || r == 'N') try = 0;
	}

	fprintf(stderr,"Desconectado\n");

	return 0;
}