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
#include "PELICULA.h"
#include "CANCION.h"
#include "SERIE.h"
#include "VIDEOJUEGO.h"
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

UsuarioNormal::UsuarioNormal() : Usuario(){
	 
	TotalFavoritos = 0;
	ValoracionMediaListaMultiMedia = 0;


	this->Favoritos = new MultiMedia*[TotalFavoritos];//Vector Polimorfico de archivos Multimedia

	if (!this->Favoritos){
	cerr << "Error en la creación del vector de clientes" << endl;
	exit(-1);
	}
	
}

UsuarioNormal::UsuarioNormal(string Login, string Nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalFavoritos) : Usuario(Login, Nombre, Apellidos, URLFotoPerfil, TotalMediaVisto){
	
	 this->TotalFavoritos = TotalFavoritos;
	 this->ValoracionMediaListaMultiMedia = ValoracionMediaListaMultiMedia;
	 
	
	this->Favoritos = new MultiMedia*[TotalFavoritos];//Vector Polimorfico de archivos Multimedia

	if (!this->Favoritos){
	cerr << "Error en la creación del vector de clientes" << endl;
	exit(-1);
	}
		
}

UsuarioNormal::~UsuarioNormal(){
	
	 Login = "NULL";
	 Nombre = "NULL";
	 Apellidos = "NULL";
	 URLFotoPerfil = "NULL";
	 TotalMediaVisto = 0;

	
	//Ahora hay que liberar la memoria reservada del vector Usuarios
	delete[] this->Favoritos;
	this->Favoritos = 0; // Anti hacker jeje
	
}
/**********************************************************
** SETS **
**********************************************************/

void UsuarioNormal::setTotalFavoritos(unsigned int TotalFavoritos){

	this->TotalFavoritos = TotalFavoritos;
}

void UsuarioNormal::setValoracionMediaListaMultiMedia(float ValoracionMediaListaMultiMedia){

	this->ValoracionMediaListaMultiMedia = ValoracionMediaListaMultiMedia;
}

/**********************************************************
** GETS **
**********************************************************/

unsigned int  UsuarioNormal::getTotalFavoritos(){

	return this->TotalFavoritos;
}

float UsuarioNormal::getValoracionMediaListaMultiMedia(){

	return this->ValoracionMediaListaMultiMedia;
}

/**********************************************************
 ** SOBRECARGAS **
 **********************************************************/

ostream& operator<<(ostream &flujo, UsuarioNormal *u){

	 Usuario *m = dynamic_cast<Usuario*>(u);
	  flujo << m;	
	
	return flujo;
}

istream& operator >> (istream &flujo,  UsuarioNormal *u){

	 Usuario *m = dynamic_cast<Usuario*>(u);
	  flujo >> m;

	return flujo;		
}
/**********************************************************
 ** INSERTAR FAVORITOS**
 **********************************************************/
void UsuarioNormal::ResizeFavoritoAum(){
	
	int nueva_dim = getTotalFavoritos()+1;
	MultiMedia** nuevo_vector = new MultiMedia*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	for(int i=0; i<getTotalFavoritos(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->Favoritos[i]; 
	}

	delete [] this->Favoritos;
	this->Favoritos = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalFavoritos = nueva_dim;
	nueva_dim = 0;
}
void UsuarioNormal::InsertarFavoritos2(MultiMedia *m){
	this->ResizeFavoritoAum();
	this->Favoritos[getTotalFavoritos()-1] = m;
	cout << USER << "Perfecto su archivo multimedia ha sido agregado a sus Favoritos. " << RESTORE << endl;
}

/**********************************************************
 ** IMPRIMIR FAVORITOS**
 **********************************************************/
void UsuarioNormal::ImprimirFavoritos(MultiMedia *m){

	if(Pelicula *p = dynamic_cast<Pelicula*>(m)){

          	if(Serie *s = dynamic_cast<Serie*>(m)){
			cout << SOL << "SERIE:" << RESTORE;
			cout << s << endl;
			
			
		}else{
			cout << SOL << "PELICULA:" << RESTORE;
			cout << p << endl;

		}
         }
	if(Cancion *c = dynamic_cast<Cancion*>(m)){
		cout << SOL << "CANCION:" << RESTORE;
		cout << c << endl;

         }

	if(Videojuego *v = dynamic_cast<Videojuego*>(m)){
		cout << SOL << "VIDEOJUEGO:" << RESTORE;
		cout << v << endl;

         } 
	
}
 
void UsuarioNormal::MostrarFavoritos(){

	//cout << DEBUG << "DEBUG " << getTotalFavoritos() << RESTORE << endl;	

	if(this->getTotalFavoritos()>0){
		for(int i=0; i<getTotalFavoritos(); i++){
	
			this->ImprimirFavoritos(Favoritos[i]);
		
		}
	}else{
		cout << "\n";
		cout << DEBUG << "No hay ningun archivo Multimedia en Favoritos."<< RESTORE << endl;
		cout << NEW << "Deberias de Insertar alguno en tu lista de Favoritos. " << RESTORE << endl;
	}
}
/**********************************************************
 ** ELIMINAR FAVORITOS**
 **********************************************************/
int UsuarioNormal::BuscarMultiMediaFavoritosTitulo(string Titulo){
	
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;

	//cout << "Titulo pasado por parametro " << Titulo << endl;

	for(int i=0; i<getTotalFavoritos() && encontrado == false; i++){
		
		if(this->Favoritos[i]->getTitulo() == Titulo){

			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){
				//cout << SOL << "NORMAL USER"  << RESTORE;
				this->InsertarMediaVisto(this->Favoritos[posicion]);	
			}
			
		}
		
	}

	
	if(encontrado == false){
		cout << USER << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

	}

	return posicion;

}
int UsuarioNormal::BuscarMultiMediaFavoritosID(int id){
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;


	for(int i=0; i<getTotalFavoritos() && encontrado == false; i++){
		
		if(this->Favoritos[i]->getIDMedia() == id){
			
			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this)){
				//cout << SOL << "NORMAL USER"  << RESTORE;
				this->InsertarMediaVisto(this->Favoritos[posicion]);
	
			}
				
				
		}

	}

		
	if(encontrado == false){
		cout << DEBUG << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

	}
	
	//cout << "Llega " << endl;

	//cout << DEBUG <<  "Posicion alfinal del buscar =  " << posicion << RESTORE << endl;

	return posicion;
}
void UsuarioNormal::ResizeMultiMediaDism(){
	
	//cout << DEBUG <<  "DEBUG Resize ALPRINCIPIO dimension =  " << RESTORE <<  getTotalMultimedia() << endl;	

	int nueva_dim = getTotalFavoritos()-1;
	MultiMedia** nuevo_vector = new MultiMedia*[nueva_dim];
	
	//cout << DEBUG << "Debug dimension nueva  " << nueva_dim <<  RESTORE << endl;

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector MultiMedia" << endl;
		exit(-1);
		}

	for(int i=0; i<nueva_dim; i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->Favoritos[i]; 
	}

	//delete this->Favoritos[getTotalFavoritos()-1];
	this->Favoritos[this->getTotalFavoritos()-1] = 0;
	delete [] this-> Favoritos;
	this-> Favoritos = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	//cout << DEBUG << "Debug dimension alfinal del resize " << nueva_dim <<  RESTORE << endl;	

	this->TotalFavoritos = nueva_dim;
	nueva_dim = 0;
	
	
}

void UsuarioNormal::IntercambiarMultiMedia(int posicion){
	
	
	MultiMedia *aux;


	if(getTotalFavoritos()>2){
		aux = this->Favoritos[getTotalFavoritos()-1];
		//cout << DEBUG <<  "LLEGA 1 " << RESTORE << endl; 
		this->Favoritos[getTotalFavoritos()-1] = this->Favoritos[posicion];
		//cout << DEBUG <<  "LLEGA 2 " << RESTORE << endl;
		this->Favoritos[posicion]  = aux;
		this->Favoritos[posicion]-> setIDMedia(posicion+1);	
		//cout << DEBUG <<  "LLEGA 3 " << RESTORE << endl;
	}
		
}
bool UsuarioNormal::buscarTituloVectorFavoritos(string Titulo){
	bool encontrado = false;

	for(int i = 0;i < getTotalFavoritos(); i++){

		if(Titulo == Favoritos[i]->getTitulo()){
			
			encontrado = true;
		}
	}

	return encontrado;
}

void UsuarioNormal::EliminarMultimediaFavoritos(string Titulo){
	
	this->IntercambiarMultiMedia(this->BuscarMultiMediaFavoritosTitulo(Titulo));
	this->ResizeMultiMediaDism();
}

void UsuarioNormal::EliminarMultiMedia(){
	int id = 0;
	char Titulo[200];

	cout << "Entra " << endl;	

	if(getTotalFavoritos() > 0){

			int opcion = 0;

				
			cout << USER << "Bienvenido a eliminar, introduzca porque desea buscar. " << endl;
			cout << "1.Titutlo" << endl;
			cout << "2.ID" << RESTORE << endl;

		while(opcion != 2){


			cin >> opcion;		

			switch(opcion){
					case 1:
		
							cout << BLU << "Perfecto, Esta usted en buscar por TItulo" << RESTORE << endl;
							cout << "\n";
							cout << USER << "Escriba el Titulo del archivo que desea " << DEBUG << " ELIMINAR " << RESTORE << endl;
							cin.clear();
							cin.ignore();
							cin.getline(Titulo,200,'\n');

							this->IntercambiarMultiMedia(this->BuscarMultiMediaFavoritosTitulo(Titulo));
							this->ResizeMultiMediaDism();
			
							cout << "\n";
					break;
					case 2: 
							cout << "\n";
				
							cout << BLU << "Perfecto, Esta usted en buscar por ID" << RESTORE << endl;
							cout << "\n";
							cout << USER << "Escriba el ID del archivo que desea " << DEBUG << " ELIMINAR " << RESTORE << endl;
							cin >> id;

							this->IntercambiarMultiMedia(this->BuscarMultiMediaFavoritosID(id));
							this->ResizeMultiMediaDism();
					
			}
		}
	}else{
		cout << DEBUG << "No hay archivos que eliminar " << endl;
	}
	
}

