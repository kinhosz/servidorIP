#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "server.h"

typedef long long int ll;

#define two 2
#define one 1
#define dif !=
#define asp ""
#define MAX_CLIENT 2

void contagemRegressiva(ll sec){

	int v = -9;
	ll aux = sec*100000000;
	for(int i=0;i<aux;i++){
		if(i/100000000 dif v){
			v = i/100000000;
			fprintf(stderr,"contagem->%d\n",sec-v);
		}
	}
}

int main(){

	system("clear");
	fprintf(stderr,"oi\n");

	serverInit(MAX_CLIENT);
	int players = 0;
	int ret;

	while(players < MAX_CLIENT){
		ret = acceptConnection();
		if(ret dif NO_CONNECTION){
			fprintf(stderr,"Usuario %d conectado ao servidor\n",ret);
			players++;
		}
	}
	rejectConnection();
	
	contagemRegressiva(10);

	for(int i=0;i<MAX_CLIENT;i++){
		disconnectClient(i);
		fprintf(stderr,"Usuario %d desconectado\n",i);
	}

	serverReset();

	return 0;
}