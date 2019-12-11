/**
 * File:   CRISTOFINITY.cpp
 * Author: RAS
 * Version: 1.0
 * 
 * Created on 30 de MAYO de 2019, 23:28
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "ADMIN.h"
#include "USUARIO.h"
#define DEBUG "\033[1;31m"   
#define USER "\033[1;34m"
#define SOL "\033[1;35m"
#define COPY "\033[1;32m"
#define RESTORE "\033[1;0m"
#define NEW "\033[1;33m"
#define BLU "\033[1;36m"
#define SUB "\033[1;46m"
#define NEW2 "\033[1;43m"

Admin:: Admin(){
	
	//cout << "Entra Constructor Admin " << endl;
}

Admin:: Admin(string Login, string nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalMediaVisto): Usuario(Login, nombre, Apellidos, URLFotoPerfil, TotalMediaVisto){
	
	//cout << "Entra COnstructor Admin Parametros " << endl;
}

Admin:: ~Admin(){
	
	cout << "Entra DES-tructor Admin " << endl;
}

/**********************************************************
 ** SOBRECARGAS **
 **********************************************************/
/*
Admin& Admin::operator=(const Admin &u){
	
	if(&u!=this){
		 Admin *m = dynamic_cast<Admin*>(u);
		 m = u;
	}

	return *this;
}
*/

ostream& operator<<(ostream &flujo,  Admin *u){


	  Usuario *m = dynamic_cast<Usuario*>(u);
	  flujo << m;
	
	return flujo;
}

istream& operator >> (istream &flujo,  Admin *u){

	  Usuario *m = dynamic_cast<Usuario*>(u);
	  flujo >> m;

	return flujo;		
}

