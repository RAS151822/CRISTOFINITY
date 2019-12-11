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
#include "USUARIO.h"
#include "USUARIONORMAL.h"
#include "MULTIMEDIA.h"
#define DEBUG "\033[1;31m"   
#define USER "\033[1;34m"
#define SOL "\033[1;35m"
#define COPY "\033[1;32m"
#define RESTORE "\033[1;0m"
#define NEW "\033[1;33m"
#define BLU "\033[1;36m"
#define SUB "\033[1;46m"
#define NEW2 "\033[1;43m"

Usuario:: Usuario(){
	
	 Login = "NULL";
	 Nombre = "NULL";
	 Apellidos = "NULL";
	 URLFotoPerfil = "NULL";
	 TotalMediaVisto = 0;


	this->VectorMediaVisto = new MultiMedia*[TotalMediaVisto];//Vector Polimorfico de archivos Multimedia

	if (!this->VectorMediaVisto){
	cerr << "Error en la creación del vector de clientes" << endl;
	exit(-1);
	}
	
}

Usuario::Usuario( string Login, string Nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalMediaVisto){
	
	 this->Login = Login;
	 this->Nombre = Nombre;
	 this->Apellidos = Apellidos;
	 this->URLFotoPerfil = URLFotoPerfil;
	 this->TotalMediaVisto = TotalMediaVisto;

	
	this-> VectorMediaVisto = new MultiMedia*[TotalMediaVisto];//Vector Polimorfico de archivos Multimedia

	if (!this->VectorMediaVisto){
	cerr << "Error en la creación del vector de clientes" << endl;
	exit(-1);
	}
		
}

Usuario::~Usuario(){
	
	 Login = "NULL";
	 Nombre = "NULL";
	 Apellidos = "NULL";
	 URLFotoPerfil = "NULL";
	 TotalMediaVisto = 0;

	
	//Ahora hay que liberar la memoria reservada del vector Usuarios
	delete[] this->VectorMediaVisto;
	this->VectorMediaVisto = 0; // Anti hacker jeje
	
}
/**********************************************************
 ** SETS **
 **********************************************************/

void Usuario::setLogin(string Login){
	
	this->Login = Login;
}

void Usuario::setNombre(string Nombre){

	this->Nombre = Nombre;
}

void Usuario::setApellido(string Apellidos){
	
	this->Apellidos = Apellidos;
}

void Usuario::setURLFotoPerfil(string URLFotoPerfil){

	this->URLFotoPerfil = URLFotoPerfil;
}

void Usuario::setTotalMediaVisto(int TotalMediaVisto){

	this->TotalMediaVisto = TotalMediaVisto;
}
/**********************************************************
 ** GETS **
 **********************************************************/
string Usuario::getLogin(){
	
	return this->Login;
}

string Usuario::getNombre(){

	return this->Nombre;
}

string Usuario::getApellido(){
	
	return this->Apellidos;
}

string Usuario::getURLFotoPerfil(){

	return this->URLFotoPerfil;
}

int Usuario::getTotalMediaVisto(){

	return this->TotalMediaVisto;

}
/**********************************************************
 ** SOBRECARGAS **
 **********************************************************/
Usuario& Usuario::operator=(const Usuario &u){
	
	if(&u!=this){
		delete[] this->VectorMediaVisto;
		this->Login = u.Login;
		this->Nombre = u.Nombre;
		this->Apellidos = u.Apellidos;
		this->URLFotoPerfil = u.URLFotoPerfil;

		//Asigno  la dimensión
		this->TotalMediaVisto = u.TotalMediaVisto;

		//Reservo la memoria de el vector para el usuario 
		this->VectorMediaVisto = new MultiMedia*[this->TotalMediaVisto+1];

		
		 if (!this->VectorMediaVisto){
		    cerr << "Error en la creación del vector de clientes" << endl;
		    exit(-1);
		}
		

		for(int i=0; i <= this->TotalMediaVisto; i++){
		
			this->VectorMediaVisto[i] = u.VectorMediaVisto[i];
		}
	}

	return *this;
}

ostream& operator<<(ostream &flujo, const Usuario *u){


	  flujo << endl;
	  flujo << NEW << "Login: " << RESTORE << u->Login << endl;
	  flujo << NEW << "Nombre: " << RESTORE  << u->Nombre << endl;
	  flujo << NEW << "Apellidos " << RESTORE  << u->Apellidos << endl;
	  flujo << NEW << "URL Foto Perfil " << RESTORE  << u->URLFotoPerfil << endl;
	  flujo << NEW << "Total Media Visto: "<< RESTORE  << u->TotalMediaVisto <<  endl;
	  flujo << endl;
	
	flujo << endl;
	return flujo;
}

istream& operator >> (istream &flujo,  Usuario *u){

	//cout << "Entra " << endl;
	cout << "Introduce los siguientes datos para tu nuevo USUARIO. " << endl;
 	cout << "Login: " << endl;
	flujo >>  u->Login;
	cout << "Nombre: " << endl;
	flujo >> u->Nombre;
	cout << "Apellidos " << endl;
	flujo >> u->Apellidos;
	cout << "URL Foto Perfil " << endl;
	flujo >> u->URLFotoPerfil;
	//flujo << endl;

	return flujo;		
}
/**********************************************************
** METODOS**
**********************************************************/
void Usuario:: introducirDatos(){

	cin >> this;	
}
/**********************************************************
** INSERTAR MEDIA VISTO**
**********************************************************/
void Usuario::ResizeAumMediaVisto(){
	int nueva_dim = getTotalMediaVisto()+1;
	MultiMedia** nuevo_vector = new MultiMedia*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	//Copio el contenido del vector de comentarios actual en el nuevo vector.
	for(int i=0; i<getTotalMediaVisto(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorMediaVisto[i]; 
	}

	

	this->VectorMediaVisto = 0;//Igualo el puntero del vector de comentario antigo a 0.
	delete [] this->VectorMediaVisto;//Elimino el puntero del vector de comentarios


	this->VectorMediaVisto = nuevo_vector;//Guardo el nuevo vector en el vector de comentarios que contiene el objeto
	
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalMediaVisto = nueva_dim;
	nueva_dim = 0;

	

	//cout << "ENtra "<< endl; 

}
int Usuario::BuscarMultiMedia(int id){
	
	bool encontrado = false;
	int posicion = 0;


	for(int i=0; i<getTotalMediaVisto() && encontrado == false; i++){
		
		if(this->VectorMediaVisto[i]->getIDMedia() == id){
			
			encontrado = true;
			posicion = i;
		}else{
			cout << USER << "Lo sentimos pero ese ID No existe en el catalogo, revise los datos. " << RESTORE << endl;
		}
	}

	return posicion;
}

void Usuario::InsertarMediaVisto(MultiMedia *m){
	
	this->ResizeAumMediaVisto();
	this->VectorMediaVisto[getTotalMediaVisto()-1] = m;
}
/**********************************************************
** INSERTAR Favoritos**
**********************************************************/
void Usuario::InsertarFavoritos(MultiMedia *m){
	
	//cout << "LLega " << endl;
	//cout << "TITULO MEDIA" << m->getTitulo() << endl;
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){
		un->InsertarFavoritos2(m);
	}
}
/**********************************************************
** MOSTRAR Favoritos**
**********************************************************/
void Usuario::MostrarFavoritos(){

	

	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){
		//cout << DEBUG << "DEBUG 1 " << un->getTotalFavoritos() << RESTORE << endl;
		un->MostrarFavoritos();
	}	
}

/**********************************************************
** ELIMINAR Favoritos**
**********************************************************/
void Usuario::EliminarFavoritos(){
	
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){
		cout << DEBUG << "DEBUG 1 " << un->getTotalFavoritos() << RESTORE << endl;
		un->EliminarMultiMedia();
	}	
}

/*
void Usuario::EliminarMultiMediaCatalogoYFavoritos(){
	
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){

		un->EliminarMultiMedia();
	}	
}
*/
