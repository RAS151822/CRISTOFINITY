/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 00:26
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "SERIE.h"
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

	/**
* @brief Método constructor por defecto es el encargado de dar memoria al objeto Serie.
* @pre 
* @post Definimos los valores de los atributos del objeto Serie.
*/
Serie::Serie() : Pelicula(){

	Temporadas = 0;
	Capitulos = 0;
	Estado = true;
}

	/**
* @brief Método constructor por parametros es el encargado de dar memoria al objeto Videojuego pasand por referencia los parametros.
* @param Temporadas(E) es la variable que almacena Temporadas de la Serie
* @param Capitulos(E)es la variable que almacena los capitulos de la Serie
* @param Estado(E) es la variable que almacena el Estado de la serie
* @post Definimos los valores de los atributos del objeto Serie.
*/
Serie::Serie(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, string Reparto, string Direccion, string Guion, string Productor, int Temporadas, int Capitulos, bool Estado, int TotalVectorValoraciones, int MeGusta, unsigned int TotalVectorComentarios):Pelicula(IDMedia, Titulo,Genero, DuracionEnSegundos, FechaPublicacion, Pegi, Descripcion, Reparto, Direccion, Guion, Productor, TotalVectorValoraciones, MeGusta, TotalVectorComentarios){

	this->Temporadas = Temporadas;
	this->Capitulos = Capitulos;
	this->Estado = Estado;  
}

	/**
* @brief Método destructor por defecto es el encargado de eliminar el objeto Serie.
* @pre 
* @post Definimos los valores de los atributos del objeto Pelicula a null o a 0.
*/
Serie::~Serie(){

	Temporadas = 0;
	Capitulos = 0;
	Estado = true;
}

/**********************************************************
** SETS **
**********************************************************/
void Serie::setTemporadas(int Temporadas){

	this->Temporadas = Temporadas;
}

void Serie::setCapitulos(int Capitulos){
	
	this->Capitulos = Capitulos;
}

void Serie::setEstado(bool Estado){

	this->Estado = Estado;
}
/**********************************************************
** GETS **
**********************************************************/
int Serie::getTemporadas(){

	return this->Temporadas;
}
int Serie::getCapitulos(){

	return this->Capitulos;
}
bool Serie::getEstado(){

	return this->Estado;
}

/**********************************************************
** SOBRECARGA **
**********************************************************/
Serie& Serie::operator=(const Serie &s){

	if(&s!= this){	
		this->Temporadas = s.Temporadas;
		this->Capitulos = s.Capitulos;
		this->Estado = s.Estado;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo,  Serie *s){

	MultiMedia *m = dynamic_cast<MultiMedia*>(s);
	flujo << m;	

	flujo << NEW << "Temporadas: " << RESTORE << s->Temporadas << endl;
	flujo << NEW << "Capitulos: " << RESTORE  << s->Capitulos << endl;
	flujo << NEW << "Estado: " << RESTORE  << s->Estado << endl;
	
	s->ImprimirVectorComentarios();
	s->ImprimirVectorValoraciones();

	flujo << endl;
	return flujo;
}

istream& operator>>(istream &flujo,  Serie *s){
	
	
	cout << "Introduce los siguientes datos para tu serie. " << endl;

	cout << NEW << "Titulo: " << RESTORE << endl; 
	flujo >> s->Titulo;
	cout << NEW << "Genero " << RESTORE << endl;  
	flujo >> s->Genero;
	cout << NEW << "Duracion en Segundos " << RESTORE << endl;  
	flujo >> s->DuracionEnSegundos;
	cout << NEW << "Fecha de Publicacion: "<< RESTORE << endl;  
	flujo >> s->FechaPublicacion;
	cout << NEW << "Pegi: " << RESTORE << endl;  
	flujo >> s->Pegi;
	cout << NEW << "Descripcion: "<< RESTORE << endl;  
	flujo >> s->Descripcion;
	cout << NEW << "ValoracionMedia: " << RESTORE << endl; 
	flujo >> s->ValoracionMedia;
	cout << NEW << "Me gusta: " << RESTORE << endl; 
	flujo >> s->MeGusta;
	cout << NEW << "Temporadas: " << RESTORE << endl; 
	flujo >> s->Temporadas;
	cout << NEW << "Capitulos: " << RESTORE << endl;  
	flujo >> s->Capitulos;
	cout << NEW << "Estado: " << RESTORE << endl;
	flujo >> s->Estado;

	return flujo;
}

