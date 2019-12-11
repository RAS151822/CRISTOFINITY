/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "MULTIMEDIA.h"
#include "CANCION.h"
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

Cancion::Cancion() : MultiMedia(){

	Artista = "NULL";
	Album = "NULL";
}

Cancion::Cancion(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, int TotalVectorValoraciones, string Artista, string Album,int MeGusta, unsigned int TotalVectorComentarios) : MultiMedia(IDMedia, Titulo, Genero, DuracionEnSegundos, FechaPublicacion, Pegi, Descripcion, TotalVectorValoraciones ,ValoracionMedia, MeGusta, TotalVectorComentarios){
	
	this->Artista = Artista;
	this->Album = Album;
}

Cancion::~Cancion(){
	
	Artista = "NULL";
	Album = "NULL";
}

/**********************************************************
** SETS **
**********************************************************/		
void Cancion::setArtista(string Artista){
	
	this->Artista = Artista;
}

void Cancion::setAlbum(string Album){

	this->Album = Album;
}
/**********************************************************
** GETS **
**********************************************************/		
string Cancion::getArtista(){
	
	return this->Artista;
}

string Cancion::getAlbum(){

	return this->Album;
}
/**********************************************************
** SOBRECARGA **
**********************************************************/
Cancion& Cancion::operator=(const Cancion &c){

	if(&c!=this){	
		
		this->Artista = c.Artista;
		this->Album = c.Album;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo,  Cancion *c){

	MultiMedia *m = dynamic_cast<MultiMedia*>(c);
	flujo << m;	

	flujo << NEW << "Artista: " << RESTORE << c->Artista << endl;
	flujo << NEW << "Album: " << RESTORE  << c->Album << endl;

	//cout << DEBUG << "total comentarios  " << c->getTotalVectorComentarios() << RESTORE << endl;

	if(c->getTotalVectorComentarios()>0){
		//cout << "ENtra " << endl;
		c->ImprimirVectorComentarios();
	}

	if(c->getTotalVectorValoraciones()>0){

		c->ImprimirVectorValoraciones();
	}

	flujo << endl;
	return flujo;
}

istream& operator>>(istream &flujo,  Cancion *c){


	cout << "Introduce los siguientes datos. " << endl;

	cout << NEW << "Titulo: " << RESTORE << endl; 
	flujo >> c->Titulo;
	cout << NEW << "Genero " << RESTORE << endl;  
	flujo >> c->Genero;
	cout << NEW << "Duracion en Segundos " << RESTORE << endl;  
	flujo >> c->DuracionEnSegundos;
	cout << NEW << "Fecha de Publicacion: "<< RESTORE << endl;  
	flujo >> c->FechaPublicacion;
	cout << NEW << "Pegi: " << RESTORE << endl;  
	flujo >> c->Pegi;
	cout << NEW << "Descripcion: "<< RESTORE << endl;  
	flujo >> c->Descripcion;
	cout << NEW << "ValoracionMedia: " << RESTORE << endl; 
	flujo >> c->ValoracionMedia;
	cout << NEW << "Me gusta: " << RESTORE << endl; 
	flujo >> c->MeGusta;
	cout << NEW << "Artista: " << RESTORE << endl;
	flujo >> c->Artista;
	cout << NEW << "Album: " << RESTORE << endl;  
	flujo >> c->Album;
	

	return flujo;		
}
