#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
int indice=0;
int subindice=0;
int correcto=1;
char expresion[20],validar[2],elementos[2];
int permitidos[15]={42,43,45,47,48,49,50,51,52,53,54,55,56,57};
float almacenadorNumero=0;
int numeroSiguiente2=0;
int numeroSiguiente=0;
void reinicio(){
	//funcion que restablece el for que se utiliza para recorrer permitidos y 
	//lee el siguiente elemento del buffer para ser evaluado
	validar[0]=getchar();
	subindice=0;
	correcto=0;
}
int main(void)
{
printf("Ingrese elementos del 0 al 9,+,-,*,/. Solo se aceptaran 19 elementos y se toma como maximo el numero 99 \n");
printf("Cada operador es binario, lo que implica que debe expresarse con 2 valores numéricos:\n ");
printf("23+4 es válido \n +23 no es válido\n 4**3 no es válido\n No se aceptan números negativos\n");
// si la expresion es muy larga, hay que apretar 2 veces enter para que funcione correctamente
while((elementos[0]=getchar())!='\n'&& indice<20){
	//se obtiene el elemento y se verifica si la expresion no esta llena
	subindice=0;
	for(validar[0]=elementos[0];subindice<15;subindice++){
		//se asigna el elemento a una variable temporal
		if(validar[0]==permitidos[subindice]){
			//se recorre permitidos y se compara uno por uno
			correcto=1; // si correcto es 1, se agregara el elemento a la expresion
			//se haran una serie de verificaciones
			if(!indice && (validar[0]==42 || validar[0]==43 || validar[0]==45 || validar[0]==47)){
				//primero si es que el primer elemento valido leido es un operador
				printf("El primer elemento valido es un signo,este sera ignorado\n");
				reinicio();
				}
			else if (indice!=0 && (validar[0]==42 || validar[0]==43 || validar[0]==45 || validar[0]==47)){
				//se verificara si hay un signo luego de otro
				switch(expresion[indice-1]){
						case '+':case '-':case '*':case '/':
						reinicio();
						break;
				default:
						break;
					}
				}
			else if (indice>=2)
			{ //se verifican los numeros anteriores, si hay 2 numeros, el 3ro no sera contado, asi para que solo se realicen operaciones binarias
				switch (expresion[indice-1])
				{
				case '0':case '1':case '2':case '3':case '4':
				case '5':case '6':case '7':case '8':case '9':
					switch (expresion[indice-2])
                    {
                    case '0':case '1':case '2':case '3':case '4':
				    case '5':case '6':case '7':case '8':case '9':
                        reinicio();
                        break;
                    
                    default:
                        break;
                    }
					break;
				
				default:
					break;
				}
			}
			
			if (correcto==1){
				expresion[indice]=validar[0];
				indice++;
				}
			
		}
	}
}
expresion[indice+1]='\0';
printf("La expresion completa es: %s\n",expresion);
correcto=1;
for (indice=0; expresion[indice]!='\0'; indice++)
{
	if(expresion[indice]=='/' && expresion[indice+1]==0 ){
		printf("La exprecion tiene un numero dividido entre cero, no se puede realizar la operacion");
		correcto=0;
	}
	
}

if (correcto == 1)

{//guardamos el primer digito en almacenador numero para que sea mas facil la operacion
	if (isdigit(expresion[1]))
	{
		numeroSiguiente = expresion[0] - '0';
		numeroSiguiente2 = expresion[1] - '0';
		almacenadorNumero += (numeroSiguiente2 + numeroSiguiente * 10);
	}
	else
	{
		numeroSiguiente = expresion[0] - '0';
		almacenadorNumero += numeroSiguiente;
	}
	for (indice = 0, subindice = 0; expresion[indice] != '\0'; indice++)
	{
		switch (expresion[indice])
		{//aqui se busca los operadores, se ve si luego del operador hay 1 o 2 numeros
		case '+':
				numeroSiguiente = expresion[indice + 1] - '0';// si hay un solo numero y luego otro operador se realiza la operacion a almacenador numero
				if (isdigit(expresion[indice + 2]))
				{
				numeroSiguiente2 = expresion[indice + 2] - '0';
				almacenadorNumero = almacenadorNumero + (numeroSiguiente2 + numeroSiguiente * 10);
				indice++;
				}
				else
				almacenadorNumero = almacenadorNumero + numeroSiguiente;
				break;
		case '-':
				numeroSiguiente = expresion[indice + 1] - '0';
				if (isdigit(expresion[indice + 2]))
				{
				numeroSiguiente2 = expresion[indice + 2] - '0';
				almacenadorNumero = almacenadorNumero - (numeroSiguiente2 + numeroSiguiente * 10);
				indice++;
				}
				else
				almacenadorNumero = almacenadorNumero - numeroSiguiente;
				break;
		case '*':
				numeroSiguiente = expresion[indice + 1] - '0';
				if (isdigit(expresion[indice + 2]))
				{
				numeroSiguiente2 = expresion[indice + 2] - '0';
				almacenadorNumero = almacenadorNumero * (numeroSiguiente2 + numeroSiguiente * 10);
				indice++;
				}
				else
				almacenadorNumero = almacenadorNumero * numeroSiguiente;
				break;
		case '/':
				numeroSiguiente = expresion[indice + 1] - '0';
				if (isdigit(expresion[indice + 2]))
				{
				numeroSiguiente2 = expresion[indice + 2] - '0';
				almacenadorNumero = almacenadorNumero / (numeroSiguiente2 + numeroSiguiente * 10);
				indice++;
				}
				else
				almacenadorNumero = almacenadorNumero / numeroSiguiente;
				break;

		default:
				break;
		}
	}
	printf("La operacion en orden de aparicion es: %f \n", almacenadorNumero);
}

return EXIT_SUCCESS;
}
 
