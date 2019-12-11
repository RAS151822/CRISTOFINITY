/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 10:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "COMENTARIO.h"
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
Comentario::Comentario(){

	
	IDComentario = 0;
	Login = "NULL";
	Texto = "NULL";
}

Comentario::Comentario(unsigned int IDComentario, string Login, string Texto){
	
	this->IDComentario = IDComentario;
	this->Login = Login;
	this->Texto = Texto;
}

Comentario::~Comentario(){
	
	IDComentario = 0;
	Login = "NULL";
	Texto = "NULL";
}
/**********************************************************
** SETS **
**********************************************************/
void Comentario::setIDComentario(unsigned int IDComentario){

	this->IDComentario = IDComentario;
}

void Comentario::setLogin(string Login){
	
	this->Login = Login;
}

void Comentario::setTexto(string Texto){
	
	this->Texto = Texto;
}
/**********************************************************
** GETS **
**********************************************************/
unsigned int Comentario::getIDComentario(){
	
	return this->IDComentario;
}

string Comentario::setLogin(){

	return this->Login;
}


string Comentario::setTexto(){
	
	return this->Texto;
}
/**********************************************************
 ** SOBRECARGAS **
 **********************************************************/
Comentario& Comentario::operator=(const Comentario &c){
	
	if(&c!=this){	

		//Porqe el id no quiero que me lo iguale
		this->Login = c.Login;
		this->Texto = c.Texto;
	}
		

	return *this;
}

ostream& operator<<(ostream &flujo, const Comentario *c){


	flujo << endl;
	cout << SUB << "COMENTARIO" << RESTORE << endl;
	flujo << NEW << "ID Comentario: " << RESTORE << c->IDComentario << endl;
	flujo << NEW << "Login: " << RESTORE  << c->Login << endl;
	flujo << NEW << "Texto: " << RESTORE  << c->Texto << endl;
	flujo << endl;
	
	flujo << endl;
	return flujo;
}

istream& operator >> (istream &flujo,  Comentario *c){

	//cout << "Entra " << endl;
	cout << USER <<  "Introduce los siguientes datos para tu COMENTARIO. " << RESTORE << endl;


		cout << "Login: " << endl;
		flujo >> c->Login;
		cout << "Texto: " << endl;
		flujo >> c->Texto;
	

	return flujo;		
}
/**********************************************************
** METODOS**
**********************************************************/

void Comentario:: introducirDatosComentario(){

	cin >> this;	
}


