/*

 */

#include <stdio.h>
#include <stdlib.h>
#include "planilla.h"
#include <string.h>
struct celda {
	int valor;
	int Xposic;
	int Yposic;
};
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

int main(void) {

	printf("Matriz actual\n");

	imprimirHoja();
	struct celda numeros[100];
	int aux = 0;
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
	for (int i = 0; i < Y; i++) {
		for (int j = 0; j < X; j++) {
			if (hoja[i][j][0] == '=') {
				int num = 0;
				char NumEntreOperaciones[20];
				int suma = 0;
				int temporal = 0;
				char ultimosigno[] = { '0', '\0' };
				for (int k = 1; hoja[i][j][k] != '\0'; k++) {
					if (hoja[i][j][k] > '0' && hoja[i][j][k] <= '9') {
						NumEntreOperaciones[num] = hoja[i][j][k];
						num++;
					} else if (hoja[i][j][k] == '+' || hoja[i][j][k] == '-'
							|| hoja[i][j][k] == '/' || hoja[i][j][k] == '*') {
						switch (ultimosigno[0]) {
						case '+':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma += atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							break;
						case '-':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma -= atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
							break;
						case '*':
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma *= atoi(NumEntreOperaciones);
							ultimosigno[0] = 0;
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
							break;
						default:
							NumEntreOperaciones[num] = '\0';
							num = 0;
							suma += atoi(NumEntreOperaciones);
							ultimosigno[0] = hoja[i][j][k];
							break;
						}
					} else {
						if (hoja[i][j][k] == '=') {
							//agregar cuando se referencia una vez de una operacion a otra
						} else if (hoja[i][j][k] <= 'A' + X
								&& hoja[i][j][k] >= 'A') {
							int posicionreferenciadaX = hoja[i][j][k] - 65;
							if (hoja[i][j][k + 1] <= '1' + X
									&& hoja[i][j][k + 1] >= '1') {
								int posicionreferenciadaY = hoja[i][j][k + 1]
										- 49;
								temporal =
										atoi(
												hoja[posicionreferenciadaX][posicionreferenciadaY]);
								switch (ultimosigno[0]) {
								case '+':
									NumEntreOperaciones[num] = '\0';
									num = 0;
									suma += temporal;
									ultimosigno[0] = 0;
									break;
								case '-':
									NumEntreOperaciones[num] = '\0';
									num = 0;
									suma += -1 * temporal;
									ultimosigno[0] = 0;
									break;
								case '*':
									NumEntreOperaciones[num] = '\0';
									num = 0;
									suma *= temporal;
									ultimosigno[0] = 0;
									break;
								case '/':
									NumEntreOperaciones[num] = '\0';
									num = 0;
									if (!temporal) {
										printf(
												"No se puede dividir el elemento entre cero");
										char null[] = "NULL";
										int temp = strlen(null);
										for (int w = 0; hoja[i][j][w] != '\0';
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
									break;
								default:
									NumEntreOperaciones[num] = '\0';
									num = 0;
									suma += temporal;
									ultimosigno[0] = hoja[i][j][k];
									break;
								}
							} else {
								printf("Elemento columna fuera de rango");
							}
						} else {
							printf("Elemento fila fuera de rango\n");
						}
					}

				}
				char num1[20];
				sprintf(num1, "%d", suma);
				int len = strlen(num1);
				for (int w = 0; w < len; w++) {
					hoja[i][j][w] = num1[w];
				}
				hoja[i][j][len] = '\0';
			}
		}
	}
	printf("\nMatriz actualizada\n");
	imprimirHoja();
	return EXIT_SUCCESS;
}
