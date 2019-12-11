/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "VIDEOJUEGO.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
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
/**********************************************************
** CONSTRUCTORES Y DESTRUCTOR **
**********************************************************/
Videojuego::Videojuego() : MultiMedia(){

	Desarrollador = "NULL";
	Editor = "NULL";
	Jugadores = 0;
	Plataforma = "NULL";
}


Videojuego::Videojuego(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion,string Desarrollador, string Plataforma, string Editor, int Jugadores, int TotalVectorValoraciones , int MeGusta, unsigned int TotalVectorComentarios): MultiMedia(IDMedia, Titulo, Genero, DuracionEnSegundos, FechaPublicacion, Pegi, Descripcion, TotalVectorValoraciones ,ValoracionMedia, MeGusta, TotalVectorComentarios){
	
	  

	this->Desarrollador = Desarrollador;
	this->Editor = Editor;
	this->Jugadores = Jugadores;
	this->Plataforma = Plataforma;
}

Videojuego::~Videojuego(){
	
	Desarrollador = "NULL";
	Editor = "NULL";
	Jugadores = 0;
	Plataforma = "NULL";
}

/**********************************************************
** SETS **
**********************************************************/
void Videojuego::setDesarrollador(string Desarrollador){
	
	this->Desarrollador = Desarrollador;
}

void Videojuego::setEditor(string Editor){
	
	this->Editor = Editor;
}

void Videojuego::setJugadores(int Jugadores){

	this->Jugadores = Jugadores;
}

void Videojuego::setPlataforma(string Plataforma){

	this->Plataforma = Plataforma;
}


/**********************************************************
** GETS **
**********************************************************/
	

string Videojuego::getDesarrollador(){
	
	return this->Desarrollador;
}

string Videojuego::getEditor(){

	return this->Editor;
}

int Videojuego::getJugadores(){

	return this->Jugadores;
}

string Videojuego::getPlataforma(){

	return this->Plataforma;
}
/**********************************************************
** SOBRECARGA **
**********************************************************/
Videojuego& Videojuego::operator=(const Videojuego &v){


	if(&v!= this){	
		this->Desarrollador = v.Desarrollador;
		this->Editor = v.Editor;
		this->Jugadores = v.Jugadores;
		this->Plataforma = v.Plataforma;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo, Videojuego *v){

	MultiMedia *m = dynamic_cast<MultiMedia*>(v);
	flujo << m;	

	flujo << NEW << "Desarrollador: " << RESTORE << v->Desarrollador << endl;
	flujo << NEW << "Editor: " << RESTORE  << v->Editor << endl;
	flujo << NEW << "Jugadores: " << RESTORE  << v->Jugadores << endl;
	flujo << NEW << "Plataforma: " << RESTORE  << v->Plataforma << endl;
	
	v->ImprimirVectorComentarios();
	v->ImprimirVectorValoraciones();

	flujo << endl;
	return flujo;
}

istream& operator>>(istream &flujo,  Videojuego *v){
	
	
	cout << "Introduce los siguientes datos. " << endl;

	cout << NEW << "Titulo: " << RESTORE << endl; 
	flujo >> v->Titulo;
	cout << NEW << "Genero " << RESTORE << endl;  
	flujo >> v->Genero;
	cout << NEW << "Duracion en Segundos " << RESTORE << endl;  
	flujo >> v->DuracionEnSegundos;
	cout << NEW << "Fecha de Publicacion: "<< RESTORE << endl;  
	flujo >> v->FechaPublicacion;
	cout << NEW << "Pegi: " << RESTORE << endl;  
	flujo >> v->Pegi;
	cout << NEW << "Descripcion: "<< RESTORE << endl;  
	flujo >> v->Descripcion;
	cout << NEW << "ValoracionMedia: " << RESTORE << endl; 
	flujo >> v->ValoracionMedia;
	cout << NEW << "Me gusta: " << RESTORE << endl; 
	flujo >> v->MeGusta;
	cout << NEW << "Desarrollador: " << RESTORE << endl;
	flujo >> v->Desarrollador;
	cout << NEW << "Editor: " << RESTORE << endl;   
	flujo >> v->Editor;
	cout << NEW << "Jugadores: " << RESTORE  << endl;  
	flujo >> v->Jugadores;
	cout << NEW << "Plataforma: " << RESTORE << endl;   
	flujo >> v->Plataforma;
	
	return flujo;
}
