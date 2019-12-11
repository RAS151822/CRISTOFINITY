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
#include "PELICULA.h"
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
Pelicula::Pelicula() : MultiMedia(){

	 Reparto = "NULL";
	 Direccion = "NULL";
	 Guion = "NULL";
	 Productor = "NULL";
}

Pelicula::Pelicula(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, string Reparto, string Direccion, string Guion, string Productor, int TotalVectorValoraciones, int MeGusta, unsigned int TotalVectorComentarios) : MultiMedia(IDMedia, Titulo, Genero, DuracionEnSegundos, FechaPublicacion, Pegi, Descripcion, TotalVectorValoraciones , ValoracionMedia, MeGusta, TotalVectorComentarios){

	this->Reparto = Reparto;
	this->Direccion = Direccion;
	this->Guion = Guion;
	this->Productor = Productor;
}

Pelicula::~Pelicula(){

	 Reparto = "NULL";
	 Direccion = "NULL";
	 Guion = "NULL";
	 Productor = "NULL";
}

/**********************************************************
** SETS **
**********************************************************/

void Pelicula::setReparto(string Reparto){

	this->Reparto = Reparto;
}

void Pelicula::setGuion(string Guion){
	
	this->Guion = Guion;
}

void Pelicula::setDireccion(string Direccion){

	this->Direccion = Direccion;
}

void Pelicula::setProductor(string Productor){

	this->Productor = Productor;
}

/**********************************************************
** GETS **
**********************************************************/

string Pelicula::getReparto(){

	return this->Reparto;
}

string Pelicula::getGuion(){

	return this->Guion;
}

string Pelicula::getDireccion(){

	return this->Direccion;
}

string Pelicula::getProductor(){

	return this->Productor;
}
/**********************************************************
** SOBRECARGA **
**********************************************************/
Pelicula& Pelicula::operator=(const Pelicula &p){

	if(&p!=this){	
		
		this->Direccion = p.Direccion;
		this->Guion = p.Guion;
		this->Productor = p.Productor;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo, Pelicula *p){

	
	MultiMedia *m = dynamic_cast<MultiMedia*>(p);
	flujo << m;

	flujo << NEW << "Reparto: " << RESTORE << p->Reparto << endl;
	flujo << NEW << "Direccion: " << RESTORE  << p->Direccion << endl;
	flujo << NEW << "Guion: " << RESTORE  << p->Guion << endl;
	flujo << NEW << "Productor: " << RESTORE  << p->Productor << endl;

	p->ImprimirVectorComentarios();
	p->ImprimirVectorValoraciones();

	flujo << endl;
	return flujo;
}

istream& operator>>(istream &flujo,  Pelicula *p){
	
	
	cout << "Introduce los siguientes datos. " << endl;

	cout << NEW << "Titulo: " << RESTORE << endl; 
	flujo >> p->Titulo;
	cout << NEW << "Genero " << RESTORE << endl;  
	flujo >> p->Genero;
	cout << NEW << "Duracion en Segundos " << RESTORE << endl;  
	flujo >> p->DuracionEnSegundos;
	cout << NEW << "Fecha de Publicacion: "<< RESTORE << endl;  
	flujo >> p->FechaPublicacion;
	cout << NEW << "Pegi: " << RESTORE << endl;  
	flujo >> p->Pegi;
	cout << NEW << "Descripcion: "<< RESTORE << endl;  
	flujo >> p->Descripcion;
	cout << NEW << "ValoracionMedia: " << RESTORE << endl; 
	flujo >> p->ValoracionMedia;
	cout << NEW << "Me gusta: " << RESTORE << endl; 
	flujo >> p->MeGusta;
	cout << NEW << "Reparto: " << RESTORE << endl; 
	flujo >> p->Reparto;
	cout << NEW << "Direccion: " << RESTORE << endl;  
	flujo >> p->Direccion;
	cout << NEW << "Guion: " << RESTORE << endl;  
	flujo >> p->Guion;
	cout << NEW << "Productor: " << RESTORE << endl;  
	flujo >> p->Productor ;

	return flujo;
}
