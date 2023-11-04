#include <stdio.h>
#include <stdlib.h>
#include "planilla.h"
#include <string.h>
// Struct que sera utilizado para almacenar los valores principales de la tabla,
// almacenando los valores de las celdas asi como sus coordenadas en enteros,
//
struct celda {
	int valor;
	int Xposic;
	int Yposic;
};
//Un vector de struct tipo celda para guardar el valor y la posicion de los numeros
struct celda numeros[100];
int aux = 0;
// Funcion que imprime la hoja, utiliza los define X e Y como limites de la matriz y
// se les resta y suma 65 para convertir el valor char a valor real.
void imprimirHoja() {
	for (int i = 1; i <= X; i++) {
		printf(" \t%d", i);
	}
	printf("\n");
	printf(
			"¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯\n");

	for (int i = 65; i < (Y + 65); i++) {
		printf(" %c |", i);
		for (int j = 0; j < X; j++) {
			if (hoja[i - 65][j][0] == '=') {
				printf(" %s ", hoja[i - 65][j]);
			} else {
				printf("  %s\t", hoja[i - 65][j]);
			}
		}
		printf("\n");
	}

}
/*
 Funcion que recorre la matriz una vez, se almacena en el struct celda numeros
 sus coordenadas  y los valores enteros, y si el valor referenciado es una coordenada,
 verifica si esta en el rango y convierte en valor entero.
 Se determina que la posicion no es una operacion, ya que esa ese caso es resuelto mas adelante
 Se usa la funcion atoi para determinar si fue posible la conversion directa del valor
 Si la conversion no fue exitosa se determina si la coordenada referenciada quiere convertir el numero a negativo
 Si lo fue, se convierte la coordenada a numero
 Se convierte la coordenada a numero y se multiplica por menos 1 si es que se referencia al negativo de una celda
 * */
void rellenarStruct(){
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (hoja[i][j][0] != '=') {
				if (!atoi(hoja[i][j])) {
					if (hoja[i][j][0] != '-') {
						if (hoja[i][j][0] <= 'A' + X && hoja[i][j][0] >= 'A') {
							int posicionreferenciadaX = hoja[i][j][0] - 65;
							if (hoja[i][j][1] <= '1' + X
									&& hoja[i][j][1] >= '1') {
								int posicionreferenciadaY = hoja[i][j][1] - 49;
								numeros[aux].Xposic = i;
								numeros[aux].Yposic = j;
								numeros[aux].valor =
										atoi(
												hoja[posicionreferenciadaX][posicionreferenciadaY]);
							} else {
								printf("Elemento columna fuera de rango");
							}
						} else {
							printf("Elemento fila fuera de rango\n");
						}
					} else {
						if (hoja[i][j][1] <= 'A' + X && hoja[i][j][1] >= 'A') {
							int posicionreferenciadaX = hoja[i][j][1] - 65;
							if (hoja[i][j][2] <= '1' + X
									&& hoja[i][j][2] >= '1') {
								int posicionreferenciadaY = hoja[i][j][2] - 49;
								numeros[aux].Xposic = i;
								numeros[aux].Yposic = j;
								numeros[aux].valor =
										-1
												* atoi(
														hoja[posicionreferenciadaX][posicionreferenciadaY]);
							} else {
								printf("Elemento columna fuera de rango");
							}
						} else {
							printf("Elemento fila fuera de rango\n");
						}
					}
				} else {
					numeros[aux].valor = atoi(hoja[i][j]);
					numeros[aux].Xposic = i;
					numeros[aux].Yposic = j;
				}
				aux++;
			}
		}
	}
}
void resolverCeldas(){
	// Aqui se vuelve a recorrer la matriz pero solo se busca las operaciones para asi resolverlas
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (hoja[i][j][0] == '=') { // Al encontrarse una operacion, se establecen variables temporales
				int num = 0; 				// indice para NumEntreOperaciones
				char NumEntreOperaciones[20];//Guarda cualquier numero que esté entre un signo y otro
				int suma = 0; //La suma/resta/multiplicacion/division hasta el ultimo signo leido
				char ultimosigno[] = { '0', '\0' }; //Se almacena el ultimo signo encontrado, el el inicio es 0 ya que no hay ultimo signo
				int banderaLaOperacionApuntaOperacion=0;
				for (int k = 1; hoja[i][j][k] != '\0'; k++) {
					//Si este valor es 1, la celda apunta a una celda sin resolver y no se guardara en la matriz
					if (hoja[i][j][k] >= '0' && hoja[i][j][k] <= '9') {
						//Si el char caracter apuntado entre 0 y 9 se agrega al NumEntreOperaciones
						NumEntreOperaciones[num] = hoja[i][j][k];
						num++;
					} else if (hoja[i][j][k] == '+' || hoja[i][j][k] == '-'
							|| hoja[i][j][k] == '/' || hoja[i][j][k] == '*') {
						//cuando se encuentra con un signo de operacion, se evalua el signo anterior con el actual
						switch (ultimosigno[0]) {
						//De acuerdo al resultado se suma/resta/multiplica/divide el numero actual con la suma total hasta ahora
						case '+':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma += atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							NumEntreOperaciones[num] = '\0';
							break;
						case '-':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma += -1 * atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							NumEntreOperaciones[num] = '\0';
							break;
						case '*':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma *= atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							NumEntreOperaciones[num] = '\0';
							break;
						case '/':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							if (!atoi(NumEntreOperaciones)) {
								printf(
										"No se puede dividir el elemento entre cero");
								char null[] = "NULL";
								int temp = strlen(null);
								for (int w = 0; hoja[i][j][w] != '\0'; w++) {
									for (int p = 0; p < temp; ++p, w++) {
										hoja[i][j][w] = null[p];
									}
								}
								break;
							}
							suma /= atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							NumEntreOperaciones[num] = '\0';
							break;
						default:
							//Si es el primer signo encontrado, se agrega a suma el numero encontrado y se asigna
							//el signo encontrado a ultimo signo para fututa comparacion
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma += atoi(NumEntreOperaciones);
							ultimosigno[0] = hoja[i][j][k];
							NumEntreOperaciones[num] = '\0';
							break;
						}
					} else { // si se encuentra una coordenada
						if (hoja[i][j][k] <= 'A' + X && hoja[i][j][k] >= 'A') {
							int posicX = hoja[i][j][k] - 65; //posicion X actual en coordenadas reales
							k++;
							if (hoja[i][j][k] <= '1' + X
									&& hoja[i][j][k] >= '1') {
								int temporal = 0;
								int posicY = hoja[i][j][k] - 49; //posicion Y actual en coordenadas reales

								for (int veri = 0; veri < aux; veri++) { //se recorrera el vector struc en busca de las coordenadas
									if (numeros[veri].Xposic == posicX
											&& numeros[veri].Yposic == posicY) {
										//yo se que esta seccion puede ser una funcion pero no me da la cabeza
										temporal = numeros[veri].valor;
										switch (ultimosigno[0]) {
										case '+':
											NumEntreOperaciones[num] = '\0';
											num = 0;
											suma += temporal;
											ultimosigno[0] = 0;
											NumEntreOperaciones[num] = '\0';
											break;
										case '-':
											NumEntreOperaciones[num] = '\0';
											num = 0;
											suma += -1 * temporal;
											ultimosigno[0] = 0;
											NumEntreOperaciones[num] = '\0';
											break;
										case '*':
											NumEntreOperaciones[num] = '\0';
											num = 0;
											suma *= temporal;
											ultimosigno[0] = 0;
											NumEntreOperaciones[num] = '\0';
											break;
										case '/':
											NumEntreOperaciones[num] = '\0';
											num = 0;
											if (!temporal) {
												printf(
														"No se puede dividir el elemento entre cero");
												char null[] = "NULL";
												int temp = strlen(null);
												for (int w = 0;
														hoja[i][j][w] != '\0';
														w++) {
													for (int p = 0; p < temp;
															++p, w++) {
														hoja[i][j][w] = null[p];
													}
												}
												break;
											}
											suma /= temporal;
											ultimosigno[0] = 0;
											NumEntreOperaciones[num] = '\0';
											break;
										default:
											NumEntreOperaciones[num] = '\0';
											num = 0;
											suma += temporal;
											ultimosigno[0] = hoja[i][j][k];
											NumEntreOperaciones[num] = '\0';
											break;
										}
									}else if(veri+1==aux&&temporal==0){
										banderaLaOperacionApuntaOperacion=1;
									}

								}
							} else {
								printf("Elemento columna fuera de rango");
							}
						} else {
							printf("Elemento fila fuera de rango\n");
						}
					}

				} if(!banderaLaOperacionApuntaOperacion){//Se agrega el numero calculado a la matriz original
				char num1[20];
				sprintf(num1, "%d", suma);
				int len = strlen(num1);
				for (int w = 0; w < len; w++) {
					hoja[i][j][w] = num1[w];
				}
				hoja[i][j][len] = '\0';
				}
				banderaLaOperacionApuntaOperacion=0;
			}
		}
	}
}
int main(void) {

	printf("Matriz actual\n");

	imprimirHoja();

	rellenarStruct();

	// En esta secion del codigo se reemplaza los valores coordenadas por sus
	// equivalentes en char en la "hoja"
	for (int i = 0; i < aux; i++) {
		int posicX = numeros[i].Xposic;
		int posicY = numeros[i].Yposic;
		char num[20];
		sprintf(num, "%d", numeros[i].valor);
		int len = strlen(num);
		for (int k = 0; k < len; k++) {
			hoja[posicX][posicY][k] = num[k];
		}
		hoja[posicX][posicY][len] = '\0';
	}
	resolverCeldas();

	aux = 0;

	rellenarStruct();

	resolverCeldas();

	printf("\nMatriz actualizada\n");
	imprimirHoja();
	return EXIT_SUCCESS;
}
