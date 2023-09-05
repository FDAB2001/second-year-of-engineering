#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define NPALABRAS 100 //aca ponemos la longitud del array que nos dió el profe
//Definimos atajos para hacer el cambio de colores mas sencillo
#define RED printf("\e[0;31m")
#define GRN printf("\e[0;32m")
#define AMA printf("\e[0;33m")
#define BLA printf("\033[0m")
#define MAX_LENGTH 100

int letraCantidad,u,i,encontrar,j,k,m,x,ganar,intentos,longitudPalabra,longitudComparar;char palabra[100] ;char comparar[100]; int comun; int posiciones; char caracteres[MAX_LENGTH];


int verificarNumero() {
    int numero=1;
    int valido = 0;

    while (!valido) {
        if (scanf("%d", &numero) == 1) {
            valido = 1;
        } else {
            printf("Error: No se ingreso un numero\n Esperando numero:");
            while (getchar() != '\n');  // Limpiar la entrada
        }
    }

    return numero;
}

int inicio(int letraCantidad){
    //Funcion que imprime la bienvenida y las intrucciones iniciales
    printf("Bienvenido al juego la palabra del dia\nTeclee un numero para adivinar una palabra con esa cantidad de letras: ");
    letraCantidad=verificarNumero();
    if(letraCantidad<3||letraCantidad>7){
    do{ 
        //Verificamos si la palabra esta en el rango correcto
        printf("Numero no valido, inserte numero entre 3 y 7:\n");
        scanf("%d",&letraCantidad);
    }
    while (letraCantidad<3||letraCantidad>7);
    }
    return(letraCantidad);
}

void intrucciones(){
    //Funcion instrucciones basicas
    printf("\nTienes que teclear las letras y luego apretar enter, solo se aceptan palabras en minuscula\n");
    RED;printf("ROJO");BLA;printf(" si la letra introducida no esta en la palabra\n");
    AMA;printf("AMARILLO");BLA;printf(" si la letra introduccida esta en la palabra pero no en la posicion indicada\n");
    GRN;printf("VERDE");BLA;printf(" si la letra introducida esta en la palabra y en la posicion adecuada\n");

}

int main(){
  letraCantidad= inicio(letraCantidad);
  printf("Inserte numero de intentos: "); 
  intentos=verificarNumero();
  intrucciones();
  //RESERVAR LUGAR PARA MATI Y SUS VECTORES QUE HAGAN SUS COSAS LOCAS
 char palabras[NPALABRAS][10]={"cliente","joyas","seis","ultimo","esta","diga","podrias","hielo","callate","trato","cola","sucede","feta","agudo","jamas","proceso","ira","ayudar","acerca","di","cambio","falta","hospital","lleva","actor","mil","gusto","conoces","diciendo","coma","fecha","general","extraño","semanas","coche","peor","mucha","disculpe","dire","anoche","perder","vamonos","nave","cielo","habra","orden","segura","querida","nena","mucha","altar","ademas","deben","libro","calle","cafe","piensas","hacemos","especial","queremos","pio","bachata","irme","perfecto","buscar","odio","piensa","entiendes","rojo","azul","ultimo","esta","diga","podrias","ciego","callate","trato","raton","sucede","corcho","denso","jamas","honesto","pescado","ayudar","acerca","fino","cambio","falta","hospital","lleva","presidente","mencion","gusto","conoces","diciendo","promesa","pelado","general","fallo"}; 
    
    char vectorde2letras[NPALABRAS][10], vectorde3letras[NPALABRAS][10], vectorde4letras[NPALABRAS][10], vectorde5letras[NPALABRAS][10],
        vectorde6letras[NPALABRAS][10],
        vectorde7letras[NPALABRAS][10]; //un vector para cada numero de longitud de palabra
    int largor;
    int i;
    int numdepalabra2 = 0, numdepalabra3 = 0, numdepalabra4 = 0,
    numdepalabra5=0, numdepalabra6=0, numdepalabra7=0;
    
    for(i=0; i<NPALABRAS; i++){
        largor=strlen(palabras[i]);
        if (largor==2){
            strcpy(vectorde2letras[numdepalabra2], palabras[i]);
            numdepalabra2++;
        } else if (largor == 3) {
            strcpy(vectorde3letras[numdepalabra3], palabras[i]);
            numdepalabra3++;
        } else if (largor == 4) {
            strcpy(vectorde4letras[numdepalabra4], palabras[i]);
            numdepalabra4++;
        } else if (largor == 5) {
            strcpy(vectorde5letras[numdepalabra5], palabras[i]);
            numdepalabra5++;
        } else if (largor == 6) {
            strcpy(vectorde6letras[numdepalabra6], palabras[i]);
            numdepalabra6++;
        } else if (largor == 7) {
            strcpy(vectorde7letras[numdepalabra7], palabras[i]);
            numdepalabra7++;
        }
    } //esta parte del codigo lo que hace es clasificar las palabras que están en el array "palabras" y las mete en un array dependiendo de su longitud, que calulamos con strlen
    
   
 srand(time(0));
   int numerorandom = (rand() % 700);
  //este codigo de aca lo que hace es generar un numero aleatorio que usaremos despues
   
   if (letraCantidad==2){
     while (numdepalabra2<numerorandom){
        for (i=0; i<2; i++){
        numerorandom=numerorandom-numdepalabra2*i;     
        }
    }strcpy(palabra,vectorde2letras[numerorandom]);
   }
   
   if (letraCantidad==3){
     while (numdepalabra3<numerorandom){
        for (i=0; i<2; i++){
          
        numerorandom=numerorandom-numdepalabra3*i;  
           
        }
    }strcpy(palabra,vectorde3letras[numerorandom]);
   }
   if (letraCantidad==4){
     while (numdepalabra4<numerorandom){
        for (i=0; i<2; i++){
        numerorandom=numerorandom-numdepalabra4*i;     
        }
    }strcpy(palabra,vectorde4letras[numerorandom]);
   }
  
  if (letraCantidad==5){
     while (numdepalabra5<numerorandom){
        for (i=0; i<2; i++){
        numerorandom=numerorandom-numdepalabra5*i;     
        }
    }strcpy(palabra,vectorde5letras[numerorandom]);
   }
   
   if (letraCantidad==6){
     while (numdepalabra6<numerorandom){
        for (i=0; i<2; i++){
        numerorandom=numerorandom-numdepalabra6*i; 
        }
    } strcpy(palabra,vectorde6letras[numerorandom]);
    
   }
   
   if (letraCantidad==7){
     while (numdepalabra7<numerorandom){
        for (i=0; i<2; i++){
        numerorandom=numerorandom-numdepalabra7*i;     
        }
    }strcpy(palabra,vectorde7letras[numerorandom]);
   }
   //esta parte que me costó una banda lo que hace es asegurarse de que el numero random generado, que es el que dará la posicion de la palabra del dia, siempre sea menor o igual a la canitidad de componentes del array de palabras de cierta longitud
  printf("%s \n",palabra);
  longitudPalabra=strlen(palabra);
  
  //comienza el juego
   
  
  printf("Escriba una palabra con %d letras \n",longitudPalabra);
  int wincount=0;
  int turnos=0;

  
  for (m=0;m<intentos;m++){
      wincount=0;
      printf("\nEste es el intento %d te quedan %d intentos\n",m+1,intentos-(m+1));
      turnos++;
      scanf("%s",comparar);
      longitudComparar=strlen(comparar);
      //verificar si la palabra ingresada es del tamaño adecuado y está en el array
      while (strlen(palabra) != strlen(comparar)) {
          printf("Las palabras no tienen la misma longitud.\n");
          printf("Ingrese una nueva palabra: ");
          scanf("%s", comparar);
          longitudComparar=strlen(comparar);
       }

int verif=0;

for (i = 0; i < NPALABRAS; i++) {
    if (longitudComparar == strlen(palabras[i])) {
        int coinciden = 1; // indica si las letras coinciden en la longitud asi es posible comparar

        for (x = 0; x < longitudComparar; x++) {
            if (comparar[x] != palabras[i][x]) {
                coinciden = 0; // No coinciden las letras
                break;
            }
        }

        if (coinciden==1) {
            printf("La palabra esta en el array.\n");
            verif=0;
            break; // Salir del bucle si se encuentra una coincidencia
        }
    }
}

    if (i == NPALABRAS) {
    verif=0;
    printf("La palabra no esta en el array. \n");

        } //como el break de la linea 191 nunca sucedió, el i llegará a NPALABRAS, significando que las palabras no son las mismas 

  
 
 for (j=0; j < longitudPalabra; j++) {
    char vecganador [longitudPalabra];
    char veccomun [longitudPalabra];
    if (comparar[j] == palabra[j]) {
        // Si la letra está en la misma posición en ambas palabras
        GRN;printf("%c", comparar[j]);BLA;
        vecganador[j] = comparar[j];
        wincount ++; //el wincount nos servirá para verificar si el usuario pudo ganar 
        
    } else {
        int k;
        int encontrada = 0;
        // Buscar la letra en la palabra pero en una posición diferente
        for (k = 0; k < longitudPalabra; k++) {
            if (comparar[j] == palabra[k] && comparar[k] != palabra[k] && !encontrada) {
                AMA;printf("%c", comparar[j]);BLA;
                veccomun[j] = comparar[j];
                encontrada = 1;
            } //lo que hacemos aca es ver si el elemento en la posición j de [comparar] es igual al elemento en la posición k de [palabra], vemos si el elemento en la posición k de [comparar] es diferente del elemento en la posición k de [palabra] y si la variable encontrada es falsa.
        }
        if (!encontrada) {
            RED;printf("%c", comparar[j]); BLA;
        }
    } 
}
  


  if (wincount==longitudPalabra){
      GRN; printf("\nGANASTE FELICIDADES :D"); BLA;
      break;
  } 
 }
if (m==intentos){
      RED;printf("\nPERDISTE"); BLA;
  }
  getchar();
return 0;
}
