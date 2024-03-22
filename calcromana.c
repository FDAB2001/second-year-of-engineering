#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <stdint.h>
#include <unistd.h>
//un define para acortar la sintaxis
#define GET_WIDGET(builder, name) GTK_WIDGET(gtk_builder_get_object(builder, name))

//el filepath del glade para rapido acceso y uso
#define GLADE_FILE_PATH "calcromana.glade"

	//declaracion del constructor
	GtkBuilder *constructor;

	/*declaracion del ID de los widgets en el glade, aun no esta asignado, se
	 * ponen el mismo nombre que el ID solo por conveniencia pero no es necesario
	 */
	GtkWidget *calcGTK,*botoni,*botonv,*botonx,*botonl,*botonc,*botond,*botonm;
	GtkWidget *botonmas,*botonmenos,*botonans,*botonigual;
	GtkWidget *entry,*label;
	//Una trampa que veremos mas adelante
	int numeropresionado=0;
	int numcant;
	char arrayromano[21];//cambiar el nombre de este a el nombre del array propio
void asignacionBotones(){
		/*Esta seccion puede hacerse en una funcion para mejor ordenamiento
	     para que sea mas facil el aprender a como asignar
	    */
	    calcGTK = GET_WIDGET(constructor, "calcGTK"); //La ventana de la calculadora
	    //Botones
	    botoni = GET_WIDGET(constructor, "botoni");
		botonv = GET_WIDGET(constructor, "botonv");
		botonx = GET_WIDGET(constructor, "botonx");
		botonl = GET_WIDGET(constructor, "botonl");
		botonc = GET_WIDGET(constructor, "botonc");
		botond = GET_WIDGET(constructor, "botond");
		botonm = GET_WIDGET(constructor, "botonm");
		botonmas = GET_WIDGET(constructor, "botonmas");
		botonigual = GET_WIDGET(constructor, "botonigual");
		botonmenos = GET_WIDGET(constructor, "botonmenos");
		botonans = GET_WIDGET(constructor, "botonans");
		//Cuadros de texto
		entry = GET_WIDGET(constructor, "entry");
		label= GET_WIDGET(constructor, "label");
}
void BOTON_PRESIONADO(GtkButton *button, gpointer data){
	numeropresionado = GPOINTER_TO_INT(data);
	switch (numeropresionado) {
	case 1:
		if(numcant+1<=20){
			arrayromano[numcant]
		}
		break;
	case 5:
		if(numcant+1<=20){

				}
		break;
	case 10:
		if(numcant+1<=20){

				}
		break;
	case 50:
		if(numcant+1<=20){

				}
		break;
	case 100:
		if(numcant+1<=20){

				}
		break;
	case 500:
		if(numcant+1<=20){

				}
		break;
	case 1000:
		if(numcant+1<=20){

				}
		break;
	}
}
void ENTER(GtkButton *button, gpointer data){
	//Aca llamar el codigo
}
 int main (int argc, char *argv[])
 {
    gtk_init (&argc, &argv);
    //Se llama a una funcion que setea el codigo para recibir de un archivo los widget
    constructor = gtk_builder_new_from_file(GLADE_FILE_PATH);
    //Funcion creada por el usuario (fede) para asignar botones a las variables supramencionadas
    asignacionBotones();
    //Señal de botones
    g_signal_connect(botoni, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(1));
    g_signal_connect(botonv, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(5));
    g_signal_connect(botonx, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(10));
    g_signal_connect(botonl, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(50));
    g_signal_connect(botonc, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(100));
    g_signal_connect(botond, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(500));
    g_signal_connect(botonv, "clicked",G_CALLBACK (BOTON_PRESIONADO),GINT_TO_POINTER(1000));
	g_signal_connect(botonigual, "clicked",G_CALLBACK (ENTER),NULL));

    g_signal_connect (calcGTK, "destroy", G_CALLBACK (gtk_main_quit), NULL);

    /* start the main loop, and let it rest there until the application is closed */
    gtk_main ();

    return 0;
 }
