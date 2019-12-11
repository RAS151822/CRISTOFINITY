/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 11:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "VALORACION.h"
#include <iostream>
#include <string.h>
#define DEBUG "\033[1;31m"   
#define USER "\033[1;34m"
#define SOL "\033[1;35m"
#define COPY "\033[1;32m"
#define RESTORE "\033[1;0m"
#define NEW "\033[1;33m"
#define BLU "\033[1;36m"
#define SUB "\033[1;46m"
#define NEW2 "\033[1;43m"

/**********************************************************
** CONSTRUCTORES Y DESTRUCTOR **
**********************************************************/
Valoracion::Valoracion(){

	IDUsuario = "NULL";
	Puntuacion = 0;
	
}

Valoracion::Valoracion(string IDUsuario, float Puntuacion){
	
	this->IDUsuario = IDUsuario;
	this->Puntuacion = Puntuacion;
	
}

Valoracion::~Valoracion(){
	
	IDUsuario = "NULL";
	Puntuacion = 0;
}
/**********************************************************
** SETS **
**********************************************************/
void Valoracion::setIDUsuario(string IDUsuario){

	this->IDUsuario = IDUsuario;
}

void Valoracion::setPuntuacion(float Puntuacion){
	
	this->Puntuacion = Puntuacion;
}

/**********************************************************
** GETS **
**********************************************************/
string  Valoracion::getIDUsuario(){
	
	return this->IDUsuario;
}

float Valoracion::getPuntuacion(){

	return this->Puntuacion;
}

/**********************************************************
 ** SOBRECARGAS **
 **********************************************************/
Valoracion& Valoracion::operator=(const Valoracion &v){
	
	if(&v!=this){	

		this->IDUsuario = v.IDUsuario;
		this->Puntuacion = v.Puntuacion;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo, const Valoracion *v){


	flujo << endl;
	cout << SUB << "VALORACION " <<  RESTORE << endl;
	flujo << NEW << "ID Usuario: " << RESTORE << v->IDUsuario << endl;
	flujo << NEW << "Puntuacion: " << RESTORE  << v->Puntuacion << endl;
	flujo << endl;
	
	flujo << endl;
	return flujo;
}

istream& operator >> (istream &flujo,  Valoracion *v){

	//cout << "Entra " << endl;
	cout << USER << "Introduce  tu Valoracion. " << RESTORE << endl;
 	cout << "ID Usuario: " << endl;
	flujo >> v->IDUsuario;
	cout << "Puntuacion: " << endl;
	flujo >> v->Puntuacion;

	return flujo;		
}
/**********************************************************
** METODOS**
**********************************************************/
void Valoracion::introducirDatosValoracion(){

	cin >> this;	
}
