/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 9:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#include "COMENTARIO.h"
#include "VALORACION.h"
#include "MULTIMEDIA.h"
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

MultiMedia::MultiMedia(){
	
	IDMedia = 0;
	Titulo = "NULL";
	Genero = "NULL";
	DuracionEnSegundos = 0;
	FechaPublicacion = "NULL";
	Pegi = 18;
	Descripcion = "NULL";
	TotalVectorValoraciones = 0;
	
	
	this->VectorValoraciones = new Valoracion*[TotalVectorValoraciones];

		if (!this->VectorValoraciones){
		cerr << "Error en la creación del vector de VectorUsuarios" << endl;
		exit(-1);
		}

	ValoracionMedia = 0.0;
	MeGusta = 0;
	TotalVectorComentarios = 0;


	this->VectorComentario = new Comentario*[TotalVectorComentarios];

		if (!this->VectorComentario){
		cerr << "Error en la creación del vector de VectorUsuarios" << endl;
		exit(-1);
		}
	
}
		
MultiMedia::MultiMedia(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, int 		TotalVectorValoraciones ,float ValoracionMedia, int MeGusta, unsigned int TotalVectorComentarios){

	this->IDMedia = IDMedia;
	this->Titulo = Titulo;
	this->Genero = Genero;
	this->DuracionEnSegundos = DuracionEnSegundos;
	this->FechaPublicacion = FechaPublicacion;
	this->Pegi = Pegi;
	this->Descripcion = Descripcion;
	this->TotalVectorValoraciones = TotalVectorValoraciones;

	
	this->VectorValoraciones = new Valoracion*[TotalVectorValoraciones];

		if (!this->VectorValoraciones){
		cerr << "Error en la creación del vector de VectorUsuarios" << endl;
		exit(-1);
		}
	

	this->ValoracionMedia = ValoracionMedia;
	this->MeGusta = MeGusta;
	this->TotalVectorComentarios = 0;

	
	this->VectorComentario = new Comentario*[TotalVectorComentarios];

		if (!this->VectorComentario){
		cerr << "Error en la creación del vector de VectorUsuarios" << endl;
		exit(-1);
		}
}
		
MultiMedia::~MultiMedia(){

	IDMedia = 0;
	Titulo = "NULL";
	Genero = "NULL";
	DuracionEnSegundos = 0;
	FechaPublicacion = "NULL";
	Pegi = 18;
	Descripcion = "NULL";
	ValoracionMedia = 0.0;
	MeGusta = 0;
	
	for(int i=0; i<TotalVectorValoraciones; i++){
		
		delete VectorValoraciones[i];
	}

	delete[] this->VectorValoraciones;
	this->VectorValoraciones = 0; // Anti hacker jeje
	TotalVectorValoraciones = 0;	


	for(int i=0; i<TotalVectorComentarios; i++){
		
		delete VectorComentario[i];
	}
	
	delete[] this->VectorComentario;
	this->VectorComentario = 0; // Anti hacker jeje
	TotalVectorComentarios = 0;	
}

/**********************************************************
** SETS **
**********************************************************/
		
void MultiMedia::setIDMedia(unsigned int IDMedia){
	
	this->IDMedia = IDMedia;
}

void MultiMedia::setTitulo(string Titulo){

	this->Titulo = Titulo;
}
		
void MultiMedia::setGenero(string Genero){
	
	this->Genero = Genero;
}
		
void MultiMedia::setDuracionEnSegundos(int DuracionEnSegundos){
	
	this->DuracionEnSegundos = DuracionEnSegundos;
}

		
void MultiMedia::setFechaPublicacion(string FechaPublicacion){
	
	this->FechaPublicacion = FechaPublicacion;
}

void MultiMedia::setPegi(int Pegi){
	
	this->Pegi = Pegi;
}
		
void MultiMedia::setDescripcion(string Descripcion){
	
	this->Descripcion = Descripcion;
}

void MultiMedia::setTotalVectorValoraciones(unsigned int TotalVectorValoraciones){
	
	this->TotalVectorValoraciones = TotalVectorValoraciones;
}

void MultiMedia::setValoracionMedia(float ValoracionMedia){
	
	this->ValoracionMedia = ValoracionMedia;
}

void MultiMedia::setMeGusta(int MeGusta){
	
	this->MeGusta = MeGusta;
}

void MultiMedia::setTotalVectorComentarios(unsigned int TotalVectorComentarios){

	this->TotalVectorComentarios = TotalVectorComentarios;
}
/**********************************************************
** GETS **
**********************************************************/

unsigned int MultiMedia::getIDMedia(){

	return this->IDMedia;
}

string MultiMedia::getTitulo(){

	return this->Titulo;
}

string MultiMedia::getGenero(){
	
	return this->Genero;
}

int MultiMedia::getDuracionEnSegundos(){

	return this->DuracionEnSegundos;
}

string  MultiMedia::getFechaPublicacion(){

	return this->FechaPublicacion;
}

int MultiMedia::getPegi(){

	return this->Pegi;
}

string MultiMedia::getDescripcion(){

	return this->Descripcion;
}

unsigned int MultiMedia::getTotalVectorValoraciones(){
	
	return this->TotalVectorValoraciones;
}

float MultiMedia::getValoracionMedia(){

	return this->ValoracionMedia;
}

int MultiMedia::getMeGusta(){

	return this->MeGusta;
}

unsigned int MultiMedia::getTotalVectorComentarios(){

	return this->TotalVectorComentarios;
}

/**********************************************************
** SOBRECARGA **
**********************************************************/
ostream& operator<<(ostream &flujo,  MultiMedia *m){

	flujo << endl;
	flujo << NEW << "ID: " << RESTORE << m->IDMedia << endl;
	flujo << NEW << "Titulo: " << RESTORE  << m->Titulo << endl;
	flujo << NEW << "Genero " << RESTORE  << m->Genero << endl;
	flujo << NEW << "Duracion en Segundos " << RESTORE  << m->DuracionEnSegundos << endl;
	flujo << NEW << "Fecha de Publicacion: "<< RESTORE  << m->FechaPublicacion <<  endl;
	flujo << NEW << "Pegi: "<< RESTORE  << m->Pegi <<  endl;
	flujo << NEW << "Descripcion: "<< RESTORE  << m->Descripcion <<  endl;
	flujo << NEW << "Total Valoraciones: "<< RESTORE  << m->TotalVectorValoraciones <<  endl;
	flujo << NEW << "ValoracionMedia: "<< RESTORE  << m->ValoracionMedia <<  endl;
	flujo << NEW << "Me gusta: "<< RESTORE  << m->MeGusta <<  endl;
	flujo << NEW << "Total Comentarios: "<< RESTORE  << m->TotalVectorComentarios <<  endl;
	flujo << endl;
	
	flujo << endl;
	return flujo;
}
istream& operator>>(istream &flujo,  MultiMedia *M){
	
	
	cout << "Introduce los siguientes datos. " << endl;

	cout << NEW << "Titulo: " << RESTORE << endl; 
	flujo >> M->Titulo;
	cout << NEW << "Genero " << RESTORE << endl;  
	flujo >> M->Genero;
	cout << NEW << "Duracion en Segundos " << RESTORE << endl;  
	flujo >> M->DuracionEnSegundos;
	cout << NEW << "Fecha de Publicacion: "<< RESTORE << endl;  
	flujo >> M->FechaPublicacion;
	cout << NEW << "Pegi: " << RESTORE << endl;  
	flujo >> M->Pegi;
	cout << NEW << "Descripcion: "<< RESTORE << endl;  
	flujo >> M->Descripcion;
	cout << NEW << "ValoracionMedia: " << RESTORE << endl; 
	flujo >> M->ValoracionMedia;
	cout << NEW << "Me gusta: " << RESTORE << endl; 
	flujo >> M->MeGusta;
	

	return flujo;
}
/**********************************************************
** COMENTARIOS **
**********************************************************/

/**********************************************************
** PRINTs **
**********************************************************/
void MultiMedia::ImprimirVectorComentarios(){

	if(getTotalVectorComentarios() > 0){
		for(int i=0; i<getTotalVectorComentarios(); i++){
	
			ImprimirComentario(this->VectorComentario[i]);
		}
	}
}
void MultiMedia::ImprimirComentario(Comentario *c){
	
	cout << c << endl;
}

void MultiMedia::ImprimirVectorValoraciones(){

	if(getTotalVectorValoraciones() > 0){
		for(int i=0; i<getTotalVectorValoraciones(); i++){

			ImprimirValoracion(this->VectorValoraciones[i]);
		}
	}
}
void MultiMedia::ImprimirValoracion(Valoracion *v){
	
	cout << v << endl;
}

/**********************************************************
** METODOS **
**********************************************************/
/**********************************************************
** RESIZES COMENTARIO **
**********************************************************/

void MultiMedia::ResizeAumComentario(){
	int nueva_dim = getTotalVectorComentarios()+1;
	Comentario** nuevo_vector = new Comentario*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	//Copio el contenido del vector de comentarios actual en el nuevo vector.
	for(int i=0; i<getTotalVectorComentarios(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorComentario[i]; 
	}

	
	this->VectorComentario = 0;//Igualo el puntero del vector de comentario antigo a 0.
	delete [] this->VectorComentario;//Elimino el puntero del vector de comentarios


	this->VectorComentario = nuevo_vector;//Guardo el nuevo vector en el vector de comentarios que contiene el objeto
	
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalVectorComentarios = nueva_dim;
	nueva_dim = 0;

	

	//cout << "ENtra "<< endl; 

}

void MultiMedia::ResizeDismComentario(){
	int nueva_dim = getTotalVectorComentarios()-1;
	Comentario** nuevo_vector = new Comentario*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	//Copio el contenido del vector de comentarios actual en el nuevo vector.
	for(int i=0; i<nueva_dim; i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorComentario[i]; 
	}


	delete this->VectorComentario[getTotalVectorComentarios()-1];
	this->VectorComentario[this->getTotalVectorComentarios()-1] = 0;
	delete [] this->VectorComentario;//Elimino el puntero del vector de comentarios
	this->VectorComentario = nuevo_vector;//Guardo el nuevo vector en el vector de comentarios que contiene el objeto
	nuevo_vector = 0;//Igualo el puntero del vector de comentario antigo a 0.
	delete [] nuevo_vector;
	
	this->TotalVectorComentarios = nueva_dim;
	nueva_dim = 0;

	//cout << "ENtra "<< endl; 

}
/**********************************************************
** RESIZES VALORACION **
**********************************************************/
void MultiMedia::ResizeAumValoracion(){
	int nueva_dim = getTotalVectorValoraciones()+1;
	Valoracion** nuevo_vector = new Valoracion*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	//Copio el contenido del vector de comentarios actual en el nuevo vector.
	for(int i=0; i<getTotalVectorValoraciones(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorValoraciones[i]; 
	}

	

	this->VectorValoraciones = 0;//Igualo el puntero del vector de comentario antigo a 0.
	delete [] this->VectorValoraciones;//Elimino el puntero del vector de comentarios


	this->VectorValoraciones = nuevo_vector;//Guardo el nuevo vector en el vector de comentarios que contiene el objeto
	
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalVectorValoraciones = nueva_dim;
	nueva_dim = 0;

	

	//cout << "ENtra "<< endl; 

}

void MultiMedia::ResizeDismValoracion(){
	int nueva_dim = getTotalVectorValoraciones()-1;
	Valoracion** nuevo_vector = new Valoracion*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	//Copio el contenido del vector de comentarios actual en el nuevo vector.
	for(int i=0; i<getTotalVectorValoraciones(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorValoraciones[i]; 
	}


	delete VectorValoraciones[getTotalVectorValoraciones()-1];
	VectorValoraciones[getTotalVectorValoraciones()-1] = 0;	

	this->VectorValoraciones = 0;//Igualo el puntero del vector de comentario antigo a 0.
	delete [] this->VectorValoraciones;//Elimino el puntero del vector de comentarios


	this->VectorValoraciones = nuevo_vector;//Guardo el nuevo vector en el vector de comentarios que contiene el objeto
	
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalVectorValoraciones = nueva_dim;
	nueva_dim = 0;

	

	//cout << "ENtra "<< endl; 

}
/**********************************************************
** AÑADIR COMENTARIO**
**********************************************************/

void MultiMedia::InsertarComentario(Comentario *c){

	this->ResizeAumComentario();
	this->VectorComentario[getTotalVectorComentarios()-1] = c;
	this->VectorComentario[getTotalVectorComentarios()-1]-> setIDComentario(getTotalVectorComentarios());
}

void MultiMedia::CrearComentario(){

	Comentario  *c;
	c = new Comentario();
	cin >> c;
	
	this->InsertarComentario(c);
}
/**********************************************************
** ELIMINAR COMENTARIO**
**********************************************************/
int MultiMedia::BuscarComentario(int id){
	bool encontrado = false;
	int posicion = 0;


	for(int i=0; i<getTotalVectorComentarios() && encontrado == false; i++){
		
		if(this->VectorComentario[i]->getIDComentario() == id ){
			
			encontrado = true;
			posicion = i;

			cout << "Perfecto este Comentario se encuentra en el sistema." << endl;
		}

	}
	
	if(encontrado == false){
		cout << USER << "Lo sentimos pero ese Comentario No existe en el sistema, revise los datos. " << RESTORE << endl;
	}

	return posicion;
}

void MultiMedia::IntercambiarComentario(int posicion){
	
	Comentario *aux;
	//cout << "posicion" << posicion << endl;
	
	if(getTotalVectorValoraciones() > 2){
		aux = this->VectorComentario[getTotalVectorComentarios()-1]; 
		this->VectorComentario[getTotalVectorComentarios()-1] = this->VectorComentario[posicion];
		this->VectorComentario[posicion]  = aux;	
		this->VectorComentario[posicion]-> setIDComentario(posicion+1);		
	}
}

void MultiMedia::EliminarComentario(int id){
	
	if(getTotalVectorComentarios() > 0){
		this->IntercambiarComentario(this->BuscarComentario(id));
		this->ResizeDismComentario();
	}else{
		cout << DEBUG << "No hay comentarios que eliminar " << endl;
	}
	
}
/**********************************************************
** AÑADIR VALORACION**
**********************************************************/

void MultiMedia::InsertarValoracion(Valoracion *v){

	this->ResizeAumValoracion();
	//cout << "ENtra " << endl;
	this->VectorValoraciones[getTotalVectorValoraciones()-1] = v;
	//cout << VectorValoraciones[getTotalVectorValoraciones()-1] << endl;
}

void MultiMedia::CrearValoracion(){

	Valoracion *v;
	v = new Valoracion();
	cin >> v;
	
	this->InsertarValoracion(v);
}
/**********************************************************
** ELIMINAR VALORACION**
**********************************************************/
int MultiMedia::BuscarValoracion(string id){
	bool encontrado = false;
	int posicion = 0;


	for(int i=0; i<getTotalVectorValoraciones() && encontrado == false;i++){
		
		if(this->VectorValoraciones[i]->getIDUsuario() == id){
			
			encontrado = true;
			posicion = i;
		}
	}

	return posicion;
}

void MultiMedia::IntercambiarValoracion(int posicion){

	Valoracion *aux;
	//cout << "posicion" << posicion << endl;
	
	if(getTotalVectorValoraciones()>2){
		aux = this->VectorValoraciones[getTotalVectorValoraciones()-1]; 
		this->VectorValoraciones[getTotalVectorValoraciones()-1] = this->VectorValoraciones[posicion];
		this->VectorValoraciones[posicion]  = aux;
	}	

}

void MultiMedia::EliminarValoracion(string id){
	
	if(getTotalVectorValoraciones()>0){
		this->IntercambiarValoracion(this->BuscarValoracion(id));
		this->ResizeDismValoracion();
	}else{
		cout << DEBUG << "No hay valoraciones que eliminar" << endl;
	}
	
}
