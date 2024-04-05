/*
 ============================================================================
 Name        : EjemploGTK.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in GTK+
 ============================================================================
 */

#include <gtk/gtk.h>
#define GLADE_FILE_PATH "romanos.glade" //Es solo para cambiar el path si necesario


char Vector[100]; // Aqui se almacenaran los caracteres introducidos por el usuario
//-------------------------------------------------------
GtkBuilder *constructor;
GtkWidget *ventana;
GtkWidget *introducir;
GtkWidget *boton;
GtkLabel *label;
//-------------------------------------------------------
void textoIntro(GtkEntry *widget, gpointer data) {
	const gchar *TextoIntroducidoPorUsuario = gtk_entry_get_text(data);
	g_print("%s", TextoIntroducidoPorUsuario);
	gtk_label_set_text(label, TextoIntroducidoPorUsuario);
}
//--------------------------------------------------------
int main(int argc, char *argv[]) {
	//Declarar todos los widgets que se van a utilizar en el codigo

	gtk_init(&argc, &argv);
	//Crear el constructor
	constructor = gtk_builder_new_from_file(GLADE_FILE_PATH);

	//Declarar los widgets
	ventana = GTK_WIDGET(gtk_builder_get_object(constructor, "ventana"));
	introducir = GTK_WIDGET(gtk_builder_get_object(constructor, "introducir"));
	boton = GTK_WIDGET(gtk_builder_get_object(constructor, "boton"));
	label = GTK_LABEL(gtk_builder_get_object(constructor, "label"));

	g_signal_connect(ventana, "destroy", G_CALLBACK (gtk_main_quit), NULL);

	g_signal_connect(boton, "clicked", G_CALLBACK (textoIntro), introducir); // Esto es importante

	//g_signal_connect(introducir, "activate", G_CALLBACK (textoIntro), introducir);

	gtk_widget_show_all(ventana);

	gtk_main();

	return 0;
}
