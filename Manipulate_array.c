#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void obtenerExpresion(char expresion[51]){
	int indice=0;
	int subindice=0;
	int permitidos[11]={48,49,50,51,52,53,54,55,56,57};
	char temporal[2];
	while((temporal[0]=getchar())!='\n'&&indice<=50){
		for(subindice=0;subindice<10;subindice++){
			if (temporal[0]==permitidos[subindice])
			{expresion[indice]=temporal[0];
			indice++;}
		}
	}
    expresion[indice]='\0';
}
int esPar(int numerocomparar,int *primo){
	if (numerocomparar <= 1){
		printf(" no es primo\n");
		(*primo)++;
		return 1;
	}
	for (int i = 2; i*i <=numerocomparar;i++){
		if(numerocomparar%i==0){
			printf(" no es primo\n");
			(*primo)++;
			return 1;
		}
	}
	printf(" es primo\n");
	return 0;
}


void determinarArrayEspecial(char expresion[51]) {
    int subindice = strlen(expresion) - 1;
    int indice = 0;
    int numerocomparar = 0;
    int primo=0;

    while (indice <= subindice) {
        numerocomparar = (expresion[indice] - '0') * 10 + (expresion[subindice] - '0');
        if (indice==subindice)
        	numerocomparar=expresion[indice] - '0';
        printf("Número a comparar en el índice %d es %d:", indice, numerocomparar);
        esPar(numerocomparar,&primo);
        indice++;
        subindice--;
    }
    if (primo==0){
    	printf("\nEl array es especial ");
    }
    else {
    	printf("\nEl array no es especial");
    }
}

int main(void) {
	char expresion[51];
	printf("Inserte numeros para la expresion\n");
	obtenerExpresion(expresion);
	printf("La expresion es %s\n",expresion);
	determinarArrayEspecial(expresion);
	return EXIT_SUCCESS;
}
