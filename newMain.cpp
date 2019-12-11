
/**
 ** VERSION 5.0
 ** BY RAUL ARENAS
*/
#include <iostream>
#include <string.h>
#include "MULTIMEDIA.h"
#include "COMENTARIO.h"
#include "CRISTOFINITY.h"
#include "PELICULA.h"
#include "SERIE.h"
#include "VIDEOJUEGO.h"
#include "CANCION.h"
#include <stdlib.h> 
#include <fstream> // La biblioteca  contiene caracteristicas especificass para incluir sentencias para importar/exportar ficheros
#define DEBUG "\033[1;31m"   
#define USER "\033[1;34m"
#define SOL "\033[1;35m"
#define COPY "\033[1;32m"
#define RESTORE "\033[1;0m"
#define NEW "\033[1;33m"
#define BLU "\033[1;36m"
#define SUB "\033[1;46m"
#define NEW2 "\033[1;43m"
using namespace std;
 /*
void opciones(){
	
	cout << "\n";
	cout << COPY << "Elija entre las siguientes opiciones. " << endl;
	cout << "1. Crear Usuario. " << endl;
	cout << "2. Elegir Usuario. " << endl;
	cout << "3. Ver Usuarios registrados. " << endl;
	cout << "4. Eliminar Usuario. " << endl;
	cout << "5. Salir. " << RESTORE << endl;
	
}
CristoFinity* CrearCristoFinity(){

	CristoFinity *c;
	c = new CristoFinity();
	

	return c;

}
void Salir(){
	
	
}
void menu(){

	CristoFinity *CF;
	CF=CrearCristoFinity();	

	
	int opcion = 0;

	while(opcion != 5){
	
		opciones();
		cin >> opcion;		

		switch(opcion){
			case 1:
				
					cout << BLU << "Esta usted en --> 1) Crear Usuario.." << RESTORE << endl;
					CF->CrearUsuario();		
					cout << "\n";
			break;
			case 2: 
					cout << "\n";
					cout << BLU << "Esta usted en --> 2) Elegir Usuario." << RESTORE << endl;
					
					cout << "\n";
			break;
			case 3:
					cout << "\n";
					cout << NEW << "Esta usted en -->  3) Ver Usuarios registrados." << RESTORE << endl;
					CF->MostrarUsuarios();
					cout << "\n";
			break;
			case 4:
					cout << "\n";
					cout << NEW << "Esta usted en -->  4) Eliminar Usuario" << RESTORE << endl;
					
					cout << "\n";
			break;
			case 5:
					cout << "\n";
					cout << NEW << "Esta usted en -->  5)  Salir." << RESTORE << endl;
					
					cout << "\n";
			break;

		
		}

	}

}
*/
int main(){
	
	CristoFinity *cf;
	cf = new CristoFinity();



	cf->ImportarXML();
	cf->MenuInicio();
	//cf->CrearMultiMedia();
	//cf->MostrarUsuarios();
	
	
	

	//cf->IntroducirLogin();
	/*	
	cf = new CristoFinity();

	Pelicula *p;
	p = new Pelicula();
	cf->InsertarMultiMedia(p);

	Cancion *c;
	c= new Cancion();
	cf->InsertarMultiMedia(c);

	Serie *s;
	s = new Serie();
	cf->InsertarMultiMedia(s);

	Videojuego *v;
	v = new Videojuego();
	cf->InsertarMultiMedia(v);
	*/

	
	/*
	MultiMedia *m;
	m = new MultiMedia();

	
	do{
		m->CrearComentario();
	}while(m->getTotalVectorComentarios() < 3);

	m->ImprimirVectorComentarios();
	//menu();

	cout << "Digame el Id del comentario que desea Eliminar." << endl;
	cin >> eliminado;
	
		m->EliminarComentario(eliminado);
		m->ImprimirVectorComentarios();
	
	cout << "2 Digame el Id del comentario que desea Eliminar." << endl;
	cin >> eliminado;

	
		m->EliminarComentario(eliminado);
		m->ImprimirVectorComentarios();	

	cout << "3Digame el Id del comentario que desea Eliminar." << endl;
	cin >> eliminado;

	
		m->EliminarComentario(eliminado);
		m->ImprimirVectorComentarios();

	m->ImprimirVectorComentarios();
	

	do{
		m->CrearValoracion();
	}while(m->getTotalVectorValoraciones() < 3);

	m->ImprimirVectorValoraciones();
	//menu();

	cout << "Digame el Id del valoracion que desea Eliminar." << endl;
	cin >> eliminado2;
	
		m->EliminarValoracion(eliminado2);
		m->ImprimirVectorValoraciones();
	
	cout << "2 Digame el Id del valoracion que desea Eliminar." << endl;
	cin >> eliminado2;

	
		m->EliminarValoracion(eliminado2);
		m->ImprimirVectorValoraciones();

	cout << "3Digame el Id del valoracion que desea Eliminar." << endl;
	cin >> eliminado2;

	
		m->EliminarValoracion(eliminado2);
		m->ImprimirVectorValoraciones();

	/*
		Serie *s;
	s = new Serie();

	cout << s;
	cin >> s;
	*/
	

	
}
