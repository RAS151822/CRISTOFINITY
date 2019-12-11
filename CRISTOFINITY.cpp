/**
 * File:   CRISTOFINITY.cpp
 * Author: RAS
 * Version: 1.0
 * 
 * Created on 2 de junio de 2019, 23:28
 */
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "CRISTOFINITY.h"
#include "PELICULA.h"
#include "CANCION.h"
#include "SERIE.h"
#include "VIDEOJUEGO.h"
#include "MULTIMEDIA.h"
#include "USUARIO.h"
#include "USUARIONORMAL.h"
#include "ADMIN.h"
#include <iomanip>
#define DEBUG "\033[1;31m"   
#define USER "\033[1;34m"
#define SOL "\033[1;35m"
#define COPY "\033[1;32m"
#define RESTORE "\033[1;0m"
#define NEW "\033[1;33m"
#define BLU "\033[1;36m"
#define SUB "\033[1;46m"
#define NEW2 "\033[1;43m" 

CristoFinity::CristoFinity(){
    
	
	this->TotalUsuarios = 0;
	this->TotalMultimedia = 0;
	this->UsuarioActual = 0;

	this->VectorUsuarios = new Usuario*[TotalUsuarios];

		if (!this->VectorUsuarios){
		cerr << "Error en la creación del vector de VectorUsuarios" << endl;
		exit(-1);
		}

	this->VectorMultiMedia = new MultiMedia*[TotalMultimedia];

		if (!this->VectorMultiMedia){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
		}

}

CristoFinity::CristoFinity(int TotalUsuarios, int TotalMultimedia ){
    
	
	this->TotalUsuarios = TotalUsuarios;
	this->TotalMultimedia = TotalMultimedia;

	this->VectorUsuarios = new Usuario*[TotalUsuarios];

		if (!this->VectorUsuarios){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
		}

	
	this->VectorMultiMedia = new MultiMedia*[TotalMultimedia];

		if (!this->VectorMultiMedia){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
		}
	
}

CristoFinity::~CristoFinity(){

	this->TotalUsuarios = 0;
	this->TotalMultimedia = 0;
	

	//Ahora hay que liberar la memoria reservada del vector Usuarios
	delete[] this->VectorUsuarios;
	this->VectorUsuarios = 0; // Anti hacker jeje
	

  	//Ahora hay que liberar la memoria reservada del vector Multimedia
	delete[] this->VectorMultiMedia;
	this->VectorMultiMedia = 0; // Anti hacker jeje
	
	
}
/**********************************************************
 ** SETS **
 **********************************************************/

void CristoFinity::setTotalUsuarios(int TotalUsuarios){
	
	this->TotalUsuarios = TotalUsuarios;
}

void CristoFinity::setTotalMultimedia(int TotalMultimedia){
	
	this->TotalMultimedia = TotalMultimedia;
}

/**********************************************************
 ** GETS **
 **********************************************************/

int CristoFinity::getTotalUsuarios(){
	
	return this->TotalUsuarios;
}

int CristoFinity::getTotalMultimedia(){
	
	return this->TotalMultimedia;
}

/**********************************************************
 ** MENUs**
 **********************************************************/
void CristoFinity::IntroducirLogin(){
	string Login;
	int contador = 0;	

	/*PRUEBA TESTING 
	do{
		this->CrearUsuario();
		contador++;
	}while(contador <= 4);
	*/

	cout << USER << "Introduzca el Login de Usuario " << RESTORE << endl;
	cin >> Login;

	this->BuscarUsuario(Login);

	if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
		cout << endl;
		cout << SOL << "ADMINISTRADOR "  << RESTORE;
		this->MenuAdmin();
	}
	
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
		cout << endl;
		cout << SOL << "NORMAL USER "  << RESTORE;
		this->MenuUsuario();	
	}
}
void CristoFinity::OpcionesInicio(){
	
	cout << USER << "Bienvenido a CRISTOFINITY diseñado por Raúl Arenas Senabre. " << RESTORE << endl;
		cout << BLU << "[1] INICIAR SESION" << RESTORE << endl;
		cout << NEW << "[2] REGISTRARSE " << RESTORE << endl;
		cout << DEBUG << "[3] SALIR " << RESTORE << endl;

}
void CristoFinity::MenuInicio(){
	int opcion = 0;	

		
	while(opcion != 3){

		OpcionesInicio();
		cin >> opcion;		

		switch(opcion){
			case 1:
				
	
					cout << BLU << "INICIAR SESION" << RESTORE << endl;
					this->IntroducirLogin();		
					cout << "\n";
			break;
			case 2: 
					cout << "\n";
					cout << NEW << "REGISTRARSE " << RESTORE << endl;
					this->CrearUsuario();
					cout << "\n";

			break;
			case 3:
					cout << "\n";
					cout << NEW << "Esta usted en --> Salir." << RESTORE << endl;
					
					cout << "\n";
			break;
		}
	}
}
void CristoFinity::opcionesAgregarEliminarMultiMedia(){
	
	cout << "\n";
	cout << COPY << "Bienvenido, elija entre las siguientes opciones. " << endl;
	cout << "1.Añadir Pelicula. " << endl;
	cout << "2.Añadir Serie. " << endl;
	cout << "3.Añadir Cancion. " << endl;
	cout << "4.Añadir Videojuego. " << endl;
	cout << "5.Visualizar Catalogo. " << endl;
	cout << "6.Eliminar." << endl;
	cout << "7.Salir." << RESTORE << endl;
	
}
void CristoFinity::menuAgregarMultimedia(){

	//CristoFinity *CF;
	//CF=CrearCristoFinity();	

	
	int opcion = 0;

	while(opcion != 7){
	
		opcionesAgregarEliminarMultiMedia();
		cin >> opcion;		

		switch(opcion){
			case 1:
				
					this->CrearPelicula();
					cout << BLU << "Perfecto, espere unos segundo estamos insertando su Pelicula" << RESTORE << endl;		
					cout << "\n";
			break;
			case 2: 
					cout << "\n";
					this->CrearSerie();
					cout << BLU << "Perfecto, espere unos segundo estamos insertando su Serie" << RESTORE << endl;
					cout << "\n";
			break;
			case 3:
					cout << "\n";
					this->CrearCancion();
					cout << NEW << "Perfecto, espere unos segundo estamos insertando su Cancion" << RESTORE << endl;
					cout << "\n";
			break;
			case 4:
					cout << "\n";
					this->CrearVideojuego();
					cout << NEW << "Perfecto, espere unos segundo estamos insertando su Videojuego" << RESTORE << endl;
					cout << "\n";
			break;
			case 5:
					cout << "\n";
					cout << NEW << "Esta usted en Visualizar Catalogo." << RESTORE << endl;
					this->MostrarMultiMedia();
					cout << "\n";
			break;

			break;
			case 6:
					cout << "\n";
					cout << NEW << "Esta usted en " << DEBUG << "ELIMINAR." << RESTORE << endl;
					this->EliminarMultiMedia();
					cout << "\n";
			break;
			
			break;
			case 7:
					cout << "\n";
					cout << NEW << "Esta usted en -->  5)  Salir." << RESTORE << endl;
					
					cout << "\n";
			break;
		}

	}

}
void CristoFinity::menuBuscarCatalogo(){
	int id = 0;
	char Titulo[200];
	
	if(getTotalMultimedia() > 0){

		int opcion = 0;
		
		cout << USER << "Bienvenido a Buscar en Catalogo, introduzca porque desea buscar. " << endl;
		cout << "1.Titutlo" << endl;
		cout << "2.ID" << RESTORE << endl;

	while(opcion != 2){
	

		cin >> opcion;		

		switch(opcion){
				case 1:
			
						cout << BLU << "Perfecto, Esta usted en buscar por TItulo" << RESTORE << endl;
						cout << "\n";
						cout << USER << "Escriba el Titulo del archivo que desea " << DEBUG << " ENCONTRAR " << RESTORE << endl;
						cin.clear();
						cin.ignore();
						cin.getline(Titulo,200,'\n');

						this->BuscarMultiMediaTitulo(Titulo);
				
						cout << "\n";
				break;
				case 2: 
						cout << "\n";
					
						cout << BLU << "Perfecto, Esta usted en buscar por ID" << RESTORE << endl;
						cout << "\n";
						cout << USER << "Escriba el ID del archivo que desea " << DEBUG << " ENCONTRAR " << RESTORE << endl;
						cin >> id;

						this->BuscarMultiMediaID(id);
						
		}
		}
	}else{
		cout << DEBUG << "No hay archivos en el Catalogo " << endl;
	}
}
void CristoFinity::opcionesAgregarEliminarUsuario(){
	
	cout << "\n";
	cout << COPY << "Bienvenido Administrador, elija entre las siguientes opciones. " << endl;
	cout << "1.Añadir Usuario del sistema. " << endl;
	cout << "2.Eliminar Usuario del Sistema. " << endl;
	cout << "3.Mostrar Usuarios. " <<  endl;
	cout << "4.Salir. " << endl;
}
void CristoFinity::menuAgregarEliminarUsuario(){
	
	int opcion = 0;

	while(opcion != 3){
	
		opcionesAgregarEliminarUsuario();
		cin >> opcion;		

		switch(opcion){
			case 1:
				
					this->CrearUsuario();
					cout << BLU << "Perfecto, espere unos segundo estamos insertando su Usuario" << RESTORE << endl;
					cout << "\n";
			break;
			case 2: 
					this->EliminarUsuarios();
					cout << BLU << "Perfecto, espere unos segundo estamos Eliminando su Usuario" << RESTORE << endl;
					cout << "\n";

			break;
			case 3: 
					this->MostrarUsuarios();
					cout << "\n";

		}
	}
}
/*
CristoFinity* CristoFinity::CrearCristoFinity(){

	CristoFinity *c;
	c = new CristoFinity();
	

	return c;

}
*/
/**********************************************************
 ** ADMINISTRADOR **
 **********************************************************/
void CristoFinity::opcionesAdministrador(){	

	cout << "\n";
	cout << BLU << "Bienvenido  " << SUB << " Administrador" << RESTORE << BLU << ",elija entre las siguientes opciones. " << RESTORE << endl;
	cout << COPY << "1.Añadir y Eliminar Archivo Multimedia del Catalogo. " << endl;
	cout << "2.Añadir y Eliminar Usuario del Sistema. " << endl;
	cout << "3.Mostrar Usuarios. " << endl;
	cout << "4.Mostrar Catalogo. " << endl;
	cout << "5.Buscar Catalogo. " << endl;
	cout << "6.Buscar Usuario." << endl;
	cout << "7 Modificar Archivo MultiMedia en CATALOGO." << endl;
	cout << "8.Consultar Valoracion Media MultiMedia"  << endl;
	cout << "9.SALIR" << RESTORE << RESTORE << endl;
}
void CristoFinity::MenuAdmin(){
	int opciones = 0;	

	cout << USER << "Bienvenido, " << NEW << this->UsuarioActual->getLogin() << USER << "  Elija entre las siguientes opciones. " << RESTORE << endl;

	while(opciones != 2){

		opcionesAdministrador();
		cin >> opciones;		

		switch(opciones){
			case 1:
				
	
					cout << BLU << "AÑADIR " << DEBUG << "ELIMINAR " << USER << " MULTIMEDIA " << RESTORE << endl;
					this->menuAgregarMultimedia();		
					cout << "\n";
			break;
			case 2: 
					cout << "\n";
					cout << BLU << "AÑADIR " << DEBUG << "ELIMINAR " << USER << " USUARIO del Sistema " << RESTORE << endl;
					this->menuAgregarEliminarUsuario();
					cout << "\n";

			break;
			case 3: 
					cout << "\n";
					cout << BLU << "MOSTRAR " << USER << " USUARIOS del Sistema " << RESTORE << endl;
					this->MostrarUsuarios();
					cout << "\n";

			break;
			case 4: 
					cout << "\n";
					cout << BLU << "MOSTRAR " << USER << " CATALOGO del Sistema " << RESTORE << endl;
					this->MostrarMultiMedia();
					cout << "\n";

			break;
			case 5:
					cout << "\n";
					cout << BLU << "BUSCAR " << USER << " CATALOGO del Sistema " << RESTORE << endl;
					this->menuBuscarCatalogo();
					cout << "\n";
			break;
			case 6:
					cout << "\n";
					cout << BLU << "BUSCAR " << USER << " USUARIOS del Sistema" << RESTORE << endl;
					
					cout << "\n";
			break;
			break;
			case 7:
					cout << "\n";
					cout << BLU << "MODIFICAR " << USER << "DATOS DEL MEDIA en el CATALOGO" << RESTORE << endl;
					this->ModificarMedia();
					cout << "\n";
			break;

			break;
			break;
			case 8:
					cout << "\n";
					cout << BLU << "CONSULTAR " << USER << "VALORACION MEDIA SOBRE ARCHIVO MULTIMEDIA" << RESTORE << endl;
					this->ConsultarValoracionMedia();
					cout << "\n";
			break;

			case 9:
					cout << "\n";
					cout << BLU << "MENU INICIO " << USER << " VOLVER " << RESTORE << endl;
					this->MenuInicio();
					cout << "\n";
			break;
		}
	}	

}
/**********************************************************
 ** USUARIO **
 **********************************************************/
void CristoFinity::opcionesUsuario(){	

	cout << "\n";
	cout << BLU << "Bienvenido  " << SUB <<  this->UsuarioActual->getLogin()  << RESTORE << BLU << ",elija entre las siguientes opciones. " << RESTORE << endl;
	cout << COPY << "1.Buscar Catalogo. " << endl;
	cout << COPY << "2.Mostrar Catalogo. " << endl;
	cout << COPY << "3.Añadir a FAVORITOS. " << endl;
	cout << COPY << "4.ELiminar de FAVORITOS. " << endl;
	cout << COPY << "5.Ver Tus FAVORITOS. " << endl;
	cout << "6.SALIR" <<  RESTORE << endl;
}
void CristoFinity::MenuUsuario(){
	int opciones = 0;	

	cout << USER << "Bienvenido, " << NEW << this->UsuarioActual->getLogin() << USER << "  Elija entre las siguientes opciones. " << RESTORE << endl;

	while(opciones != 6){

		opcionesUsuario();
		cin >> opciones;		

		switch(opciones){
			case 1:
					cout << "\n";
					cout << BLU << "BUSCAR " << USER << " CATALOGO del Sistema " << RESTORE << endl;
					this->menuBuscarCatalogo();
					cout << "\n";
			break;

			case 2:
					cout << "\n";
					cout << BLU << "MOSTRAR " << USER << " CATALOGO del Sistema " << RESTORE << endl;
					this->MostrarMultiMedia();
					cout << "\n";
			break;

			case 3:
					cout << "\n";
					cout << BLU << "AÑADIR " << USER << " archivo MULTIMEDIA " << NEW << " A FAVORITOS " << RESTORE << endl;
					this->InsertarFavoritos();
					cout << "\n";
			break;

			case 4:
					cout << "\n";
					cout << BLU << "ELIMINAR " << USER << " archivo MULTIMEDIA " << NEW << " DE FAVORITOS " << RESTORE << endl;
					this->EliminarFavoritos();
					cout << "\n";
			break;		

			case 5:
					cout << "\n";
					cout << BLU << "VISUALIZAR TUS " << USER << " archivo MULTIMEDIA " << NEW << " FAVORITOS " << RESTORE << endl;
					this->ImprimirFavoritos();
					cout << "\n";
			break;

			case 6:
					cout << "\n";
					cout << BLU << "VOLVER A TU " << USER << " MENU DE " << NEW << " INICIO " << RESTORE << endl;
					this->MenuInicio();
					cout << "\n";
			break;
					
		}
	}	

}
/**********************************************************
 ** PRINT **
 **********************************************************/
void CristoFinity::ImprimirUsuario(Usuario *u){

	//cout << "entra cout" << endl;	
	//cout << u << endl;
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(u)){
		cout << SOL << "NORMAL USER"  << RESTORE;
		cout << u << endl;
	}
	if(Admin *ad = dynamic_cast<Admin*>(u)){
	   cout << SOL << "ADMINISTRADOR: " << RESTORE;
           cout << u << endl;
	}
}

void CristoFinity::MostrarUsuarios(){

	//cout << "entra fuera" << endl;	

	for(int i=0; i<getTotalUsuarios(); i++){
		//cout << "entra Buckle" << endl;	
		this->ImprimirUsuario(this->VectorUsuarios[i]);
	}
}
void CristoFinity::ImprimirMultiMedia(MultiMedia *m){

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
 
void CristoFinity::MostrarMultiMedia(){
	
	if(this->getTotalMultimedia()>0){
		for(int i=0; i<getTotalMultimedia(); i++){
	
			this->ImprimirMultiMedia(VectorMultiMedia[i]);
		
		}
	}else{
		cout << DEBUG << "No hay ningun archivo Multimedia en el Catalogo. " << RESTORE << endl;
	}
}

/**********************************************************
 ** METODOS USUARIOS**
 **********************************************************/
/**********************************************************
 ** INSERTAR**
 **********************************************************/
void CristoFinity::ResizeUsuarioAum(){
	
	int nueva_dim = getTotalUsuarios()+1;
	Usuario** nuevo_vector = new Usuario*[nueva_dim];

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector de Usuarios" << endl;
		exit(-1);
		}

	for(int i=0; i<getTotalUsuarios(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this->VectorUsuarios[i]; 
	}

	delete [] this->VectorUsuarios;
	this->VectorUsuarios = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalUsuarios = nueva_dim;
	nueva_dim = 0;
}

void CristoFinity::InsertarUsuario(Usuario* u){

	this->ResizeUsuarioAum();
	this->VectorUsuarios[getTotalUsuarios()-1] = u;
	//cout << VectorUsuarios[getTotalUsuarios()-1] << endl;
}

void CristoFinity::CrearUsuario(){

	int opciones = 0;

	cout << USER << "Que tipo de Usuario quieres crear: " << RESTORE << endl;
	cout << NEW << "Opcion [1] " << RESTORE << USER << "NORMAL " <<  RESTORE << endl;
	cout << NEW << "Opcion [2] " << RESTORE << USER << "ADMINISTRADOR " << RESTORE << endl;

	do{
		cin >> opciones;
		
		if(opciones !=1 && opciones !=2){
			
			cout << DEBUG << "Recuerda solo puedes marcar opcion 1 y 2!  " << RESTORE << endl;
		}
		
	}while(opciones != 1 && opciones != 2);

	if(opciones == 1){

		cout << NEW << "USUARIO " << RESTORE << USER << "NORMAL " <<  RESTORE << endl;
		Admin *ua;
		ua = new Admin();

		cin >> ua;
		this->InsertarUsuario(ua);
		this->MenuAdmin();
	}
	
	if(opciones == 2){
		
		cout << NEW << "USUARIO " << RESTORE << USER << "ADMINISTRADOR " <<  RESTORE << endl;
		UsuarioNormal *u;
		u = new UsuarioNormal();
	
		cin >> u;
		this->InsertarUsuario(u);
		this->MenuAdmin();
	}
}
void CristoFinity::BuscarUsuario(string Login){
	bool encontrado = false;

	for(int i=0; i<getTotalUsuarios() && encontrado == false; i++){
		
		if(this->VectorUsuarios[i]->getLogin() == Login){
			
			encontrado = true;

			cout << USER << "Perfecto se encuentra REGISTRADO en el sistema." << RESTORE << endl;
			cout << endl;


			this->UsuarioActual = VectorUsuarios[i];

		}
	}
	
	if(encontrado == false){
		cout << USER << "Lo sentimos pero " << DEBUG << "NO ESTA REGISTRADO" << USER << ", revise los datos o registrese en el sistema. " << RESTORE << endl;
		this->MenuInicio();
	}

		
}
/**********************************************************
 ** ELIMINAR**
 **********************************************************/
int CristoFinity::BuscarEliminarUsuario(string Login){
	bool encontrado = false;
	int posicion = 0;

		for(int i=0; i<getTotalUsuarios() && encontrado == false; i++){

			if(this->VectorUsuarios[i]->getLogin() == Login){

				encontrado = true;
				posicion = i;

				cout << USER << "Perfecto se encuentra REGISTRADO en el sistema." << RESTORE << endl;
				cout << endl;

			}
		}

		if(encontrado == false){
			cout << USER << "Lo sentimos pero " << DEBUG << "NO ESTA REGISTRADO" << USER << ", revise los datos o registrese en el sistema. " << 			RESTORE << endl;
			this->MenuAdmin();
		}
	
	return posicion;
}

void CristoFinity::ResizeUsuarioDism(){
	
	//cout << DEBUG <<  "DEBUG Resize ALPRINCIPIO dimension =  " << RESTORE <<  getTotalMultimedia() << endl;	

	int nueva_dim = getTotalUsuarios()-1;
	Usuario** nuevo_vector = new Usuario*[nueva_dim];
	
	//cout << DEBUG << "Debug dimension nueva  " << nueva_dim <<  RESTORE << endl;

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector MultiMedia" << endl;
		exit(-1);
		}

	for(int i=0; i<nueva_dim; i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this-> VectorUsuarios[i]; 
	}

	delete this->VectorUsuarios[getTotalUsuarios()-1];
	this->VectorUsuarios[this->getTotalUsuarios()-1] = 0;
	delete [] this-> VectorUsuarios;
	this-> VectorUsuarios = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	//cout << DEBUG << "Debug dimension alfinal del resize " << nueva_dim <<  RESTORE << endl;	

	this->TotalUsuarios = nueva_dim;
	nueva_dim = 0;
	
	
}

void CristoFinity::IntercambiarUsuarios(int posicion){
	
	
	Usuario *aux;


	if(getTotalUsuarios()>2){
		aux = this->VectorUsuarios[getTotalUsuarios()-1];
		//cout << DEBUG <<  "LLEGA 1 " << RESTORE << endl; 
		this->VectorUsuarios[getTotalUsuarios()-1] = this->VectorUsuarios[posicion];
		//cout << DEBUG <<  "LLEGA 2 " << RESTORE << endl;
		this->VectorUsuarios[posicion]  = aux;
		//cout << DEBUG <<  "LLEGA 3 " << RESTORE << endl;
	}
		
}

void CristoFinity::EliminarUsuarios(){
	int id = 0;
	char Login[200];
	
	if(getTotalUsuarios() > 0){

		int opcion = 0;
		
		cout << USER << "Bienvenido a eliminar, introduzca el Login del Usuario. " << endl;
		cin.clear();
		cin.ignore();
	
		do{
			cin.getline(Login,200,'\n');

			if(this->UsuarioActual->getLogin() == Login){
				
				cout << NEW << " jejejej Amiguito no puede borrarse a " << DEBUG << " si MISMO!! "  << endl;
				cout << NEW << "Introduce otro Granujilla :) " << endl;
			}

		}while(this->UsuarioActual->getLogin() == Login);		

		this->IntercambiarUsuarios(this->BuscarEliminarUsuario(Login));
		this->ResizeUsuarioDism();
		cout << USER << "Perfecto su Usuario ha sido " << DEBUG << " ELIMINADO " << RESTORE << endl;

		
	}else{
		cout << DEBUG << "No hay Usuarios que eliminar " << endl;
	}
	
}
/**********************************************************
 ** METODOS USUARIOS NORMAL**
 **********************************************************/
int CristoFinity::BuscarMultiMediaFavoritos(string Titulo){
	
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;

	//cout << "Titulo pasado por parametro " << Titulo << endl;

	for(int i=0; i<getTotalMultimedia() && encontrado == false; i++){
		
		if(this->VectorMultiMedia[i]->getTitulo() == Titulo){

			encontrado = true;
			posicion = i;
			//cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
				//cout << SOL << "NORMAL USER"  << RESTORE;
				this->UsuarioActual->InsertarMediaVisto(this->VectorMultiMedia[posicion]);	
			}
			
			/*	
				cout << USER << "Desea visualizar el archivo multimedia ? " << RESTORE << endl;
				cout << USER << "Pulse [1] para " << NEW << " SI " << RESTORE << endl;
				cout << USER << "Pulse [2] para " << DEBUG  << " volver al menu principal " << DEBUG <<  " SIN INSERTAR" << RESTORE << endl;
				cin >> opciones;

			do{
				if(opciones == 1){

					this->ImprimirMultiMedia(VectorMultiMedia[i]);
					
				}
				if(opciones == 2){
						this->MenuUsuario();

				}
				if(opciones!=1 || opciones!=2){
					cout << "Recuerde pulse 1 o 2 ! " << endl;
				}	

			}while(opciones!=1 || opciones!=2);
			
			*/
		}
		
	}

	
	if(encontrado == false){
		cout << USER << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;		
		posicion = -1;

	}

	return posicion;

}
void CristoFinity::InsertarFavoritos(){
	char Titulo[200];
	int posicion = 0;
	int opcion = 0;


			cout << USER << "Bienvenido introduzca el Titulo del Media que desea añadir a " << NEW << " FAVORITOSS " << RESTORE << endl;
			cin.clear();
			cin.ignore();
			cin.getline(Titulo,200,'\n');

		if(this->getTotalMultimedia()>0){
				posicion = this->BuscarMultiMediaFavoritos(Titulo);
				this->UsuarioActual->InsertarFavoritos(VectorMultiMedia[posicion]);
				//this->MenuUsuario();
		}else{
			cout << DEBUG << "No hay ningun archivo en el catalogo lo sentimos. " << RESTORE << endl;
		}
}
void CristoFinity::ImprimirFavoritos(){
	
	this->UsuarioActual->MostrarFavoritos();

	/*
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
		cout << "DEBUG " << un->getTotalFavoritos() << endl;
	}
	*/
}
void CristoFinity::EliminarFavoritos(){
	
	if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
		//cout << "DEBUG " << un->getTotalFavoritos() << endl;

		if( un->getTotalFavoritos()>0){

			this->UsuarioActual->EliminarFavoritos();

		}else{
			cout << DEBUG << "No hay nada que ELIMINAR AMIGO! " << RESTORE << endl;
			
		}
	}
}

void CristoFinity::EliminarMultiMediaCatalogoYFavoritos(string Titulo){

	int pos = 0;
		//cout << "DEBUG " << un->getTotalFavoritos() << endl
	pos = this->BuscarMultiMediaFavoritos(Titulo);
	
	if(pos != -1){
		for(int i=0; i < getTotalUsuarios();i++){

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->VectorUsuarios[i])){

				if(un->buscarTituloVectorFavoritos(Titulo) == 1){

					un->EliminarMultimediaFavoritos(Titulo);

				}
			}	
		}
	}

	
}
/*
void CristoFinity::EliminarMultiMediaCatalogoYFavoritos(string Titulo){

	for(int i=0; i<getTotalUsuarios(); i++){
			
		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->VectorUsuarios[i])){
			//cout << DEBUG << "ENTRA 1 IF " << RESTORE << endl; 
			for(int j=0; j< un->getTotalFavoritos(); j++){

					//cout << DEBUG << "ENTRA FOR 2 " << RESTORE << endl; 				

				if(un->Favoritos[j]->getTitulo() == Titulo){
					cout << DEBUG << "ENTRA 2 IF " << RESTORE << endl; 
					un->IntercambiarMultiMedia(un->BuscarMultiMediaFavoritosTitulo(Titulo));
					un->ResizeMultiMediaDism();
						
				}else{
					
					cout << "QUE PASO! " << endl;
				}
			}
		}else{
			cout << NEW << "No eres Usuario NOrmal eres admin. " << RESTORE << endl;
		}
	}
	
}
*/
/**********************************************************
** METODOS MULTIMEDIA**
**********************************************************/
/**********************************************************
** IMPORTAR XML**
**********************************************************/
void CristoFinity:: ImportarXML(){
		
	Pelicula *p = new Pelicula(1, "Vengadores EndGame", "Ficcion", 16200, "24/04/2019", 13, "Ultima pelicula de los vengadores..", "Chris Hemsworth, Mark Ruffalo, Chris Evans, Josh Brolin, Tom Hiddleston", "Anthony Russo, Joe Russo", "Christopher Markus, Stephen McFeely", "Marvel Studios", 0, 2, 2);
	Comentario *pc = new Comentario(0, "Layla7", "Vaya final..!");
	Comentario *pc2 = new Comentario(0, "ras01", "Chacho Chacho!");
	Valoracion *pv = new Valoracion("ras01", 3);
	Valoracion *pv2 = new Valoracion("Layla7", 8);
	
	p->setValoracionMedia(2.625);
	
	this->InsertarMultiMedia(p);
	p->InsertarComentario(pc);
	p->InsertarComentario(pc2);
	p->InsertarValoracion(pv);
	p->InsertarValoracion(pv2);
	
	Pelicula *p1 = new Pelicula(2, "Vengadores Era de Ultron", "Ficcion", 16200, "24/04/2015", 13, "Tony Stark intenta crear un escudo para el mundo....", "Chris Hemsworth, Mark Ruffalo, Chris Evans, Josh Brolin, Tom Hiddleston", "Anthony Russo, Joe Russo", "Christopher Markus, Stephen McFeely", "Marvel Studios", 0, 1, 1);
	Comentario *p1c = new Comentario(0,"ras01", "La pelicula me parece una M..");
	Valoracion *p1v = new Valoracion("ras01", 3);
	
	p1->setValoracionMedia(1.562);

	this->InsertarMultiMedia(p1);
	p1->InsertarComentario(p1c);
	p1->InsertarValoracion(p1v);
	
	Cancion *c1 = new Cancion(3, "Welcome to the Jungle", "Hair Metal", 194, "24/04/2019", 13, "Jungle, welcome to the jungle Watch it bring you to your shun n-n-n-n-n-n-n-n knees, knees...", 0, "Guns N' Roses", "Appetite for Destruction", 5, 0);
	Comentario *c1c = new Comentario(0,"ras01", "No esta mal..");	
	Valoracion *c1v = new Valoracion("ras01", 5);

	this->InsertarMultiMedia(c1);
	c1->InsertarComentario(c1c);
	c1->InsertarValoracion(c1v);
	c1->setValoracionMedia(2.562);


	Serie *s1 = new Serie(4, "Juego de Tronos", "Fantasia", 180000, "24/04/2019", 18, "Unos ti@s se pelean por un trono de hierro...", ">Emilia Clarke, Peter Dinklage, Kit Harington, Maisie Williams...", "Alan Taylor, Alex Graves, Jeremy Podeswa", "George R. R. Martin, David Benioff, D. B. Weiss...", "David Benioff, D. B. Weiss", 8, 90, "finalizada", 0, 1, 0);
	Comentario *s1c = new Comentario(1,"Layla7", "Vaya FInal");	
	Valoracion *s1v = new Valoracion("Layla7", 9);

	this->InsertarMultiMedia(s1);	
	s1->InsertarComentario(s1c);
	s1->InsertarValoracion(s1v);
	s1->setValoracionMedia(4.612);
	

	Videojuego *v1 = new Videojuego(5, "Call Of Duty", "Shooter", 10800000, "24/04/2019", 18, "Gente se pega tiros y grita por su micro de la Play...", "Ben Chichoski", "ps2", "Tencent Holdings, Activision, Nokia", 10, 0, 3, 0);
	InsertarMultiMedia(v1);
	Comentario *v1c = new Comentario(1,"marioloops", "Este juego me puede venir bien para un ejercicio...");	
	Comentario *v1c1 = new Comentario(2,"ras01", "Este juego no mola");
	Comentario *v1c2 = new Comentario(3,"Layla7", "Este juego es de niños rata");		
	Valoracion *v1v = new Valoracion("marioloops", 9);
	Valoracion *v1v1 = new Valoracion("ras01", 5);
	Valoracion *v1v2 = new Valoracion("Layla7", 7);

	v1->InsertarComentario(v1c);
	v1->InsertarComentario(v1c1);
	v1->InsertarComentario(v1c2);
	v1->InsertarValoracion(v1v);
	v1->InsertarValoracion(v1v1);
	v1->InsertarValoracion(v1v2);
	v1->setValoracionMedia(3.687);

		
	UsuarioNormal *u1 = new UsuarioNormal("ras01", "Raspu", "Arenas", "/home/cristofinity/user/ras01/perfil.jpg", 0);
	InsertarUsuario(u1);
	
	UsuarioNormal *u2 = new UsuarioNormal("Layla7", "Azahara", "Escudero", "/home/cristofinity/user/thanos/perfil.jpg", 0);
	InsertarUsuario(u2);

	UsuarioNormal *u3 = new UsuarioNormal("marioloops", "mario", "mdma", "/home/cristofinity/user/matt/perfil.jpg", 0);
	InsertarUsuario(u3);

	Admin *u4 = new Admin("zizou", "Jaime", "Zidane God", "/home/cristofinity/user/zizou/perfil.jpg",0);
	InsertarUsuario(u4);
}
/**********************************************************
** INSERTAR**
**********************************************************/
void CristoFinity::ResizeMultiMediaAum(){
	
	//cout << "Debug resize dimension antes de aum: " << getTotalMultimedia() << endl;
	int nueva_dim = getTotalMultimedia()+1;
	MultiMedia** nuevo_vector = new MultiMedia*[nueva_dim];
	
	//cout << DEBUG << "Debug: " << nueva_dim << RESTORE << endl;

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector de Vector MultiMedia" << endl;
		exit(-1);
		}

	for(int i=0; i<getTotalMultimedia(); i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this-> VectorMultiMedia[i]; 
	}

	delete [] this-> VectorMultiMedia;
	this-> VectorMultiMedia = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	this->TotalMultimedia = nueva_dim;
	nueva_dim = 0;
}

void CristoFinity::InsertarMultiMedia(MultiMedia* m){

	this->ResizeMultiMediaAum();
	this->VectorMultiMedia[getTotalMultimedia()-1] = m;
	//cout << "Debug  vector " << VectorMultiMedia[getTotalMultimedia()-1] << endl;
	this->VectorMultiMedia[getTotalMultimedia()-1]-> setIDMedia(getTotalMultimedia());
}

void CristoFinity::CrearMultiMedia(){

	this->menuAgregarMultimedia();
	this->opcionesAgregarEliminarMultiMedia();
}

void CristoFinity::CrearPelicula(){

	Pelicula *p;
	p = new Pelicula();
	cin >> p;
	InsertarMultiMedia(p);	
}

void CristoFinity::CrearSerie(){

	Serie *s;
	s = new Serie();
	cin >> s;
	InsertarMultiMedia(s);

}

void CristoFinity::CrearVideojuego(){

	Videojuego *v;
	v = new Videojuego();
	cin >> v;
	InsertarMultiMedia(v);

}

void CristoFinity::CrearCancion(){

	Cancion *c;
	c = new Cancion();
	cin >> c;
	InsertarMultiMedia(c);

}
/**********************************************************
** ELIMINAR**
**********************************************************/
int CristoFinity::BuscarMultiMediaTitulo(string Titulo){
	
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;

	//cout << "Titulo pasado por parametro " << Titulo << endl;

	for(int i=0; i<getTotalMultimedia() && encontrado == false; i++){
		
		if(this->VectorMultiMedia[i]->getTitulo() == Titulo){

			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
				//cout << SOL << "NORMAL USER"  << RESTORE;
				this->UsuarioActual->InsertarMediaVisto(this->VectorMultiMedia[posicion]);	
			}
				
				cout << USER << "Desea visualizar el archivo multimedia ? " << RESTORE << endl;
				cout << USER << "Pulse [1] para " << NEW << " SI " << RESTORE << endl;
				cout << USER << "Pulse [2] para " << DEBUG  << " volver al menu principal " << RESTORE << endl;
				cin >> opciones;

			do{
				if(opciones == 1){

					this->ImprimirMultiMedia(VectorMultiMedia[i]);

					if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
						cout << endl;

						
						this->IntercambiarMultiMedia(posicion);
						this->ResizeMultiMediaDism();
						this->MenuAdmin();
					}

					if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
						cout << endl;

						this->MenuUsuario();

					}
				}
				if(opciones == 2){

					if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
						cout << endl;
						this->IntercambiarMultiMedia(posicion);
						this->ResizeMultiMediaDism();
						this->MenuAdmin();
					}

					if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
						cout << endl;

						this->MenuUsuario();
					}
				}
				if(opciones!=1 || opciones!=2){
					cout << "Recuerde pulse 1 o 2 ! " << endl;
				}	

			}while(opciones!=1 || opciones!=2);
		}
	}

	
	if(encontrado == false){
		cout << DEBUG << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
			cout << endl;
			this->MenuAdmin();
		}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
			cout << endl;

			this->MenuUsuario();
		}
	}

	return posicion;
}
int CristoFinity::BuscarMultiMediaID(int id){
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;


	for(int i=0; i<getTotalMultimedia() && encontrado == false; i++){
		
		if(this->VectorMultiMedia[i]->getIDMedia() == id){
			
			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
				//cout << SOL << "NORMAL USER"  << RESTORE;
				this->UsuarioActual->InsertarMediaVisto(this->VectorMultiMedia[posicion]);
	
			}
				
				cout << USER << "Desea visualizar el archivo multimedia ? " << RESTORE << endl;
				cout << USER << "Pulse [1] para " << NEW << " SI " << RESTORE << endl;
				cout << USER << "Pulse [2] para " << DEBUG  << " volver al menu principal " << RESTORE << endl;
				cin >> opciones;

			do{
				if(opciones == 1){

					this->ImprimirMultiMedia(VectorMultiMedia[i]);
					if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
						cout << endl;

						IntercambiarMultiMedia(posicion);
						this->ResizeMultiMediaDism();
						this->MenuAdmin();
					}

					if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){

						this->MenuUsuario();
					}
				}
				if(opciones == 2){

					if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
						cout << endl;
						this->MenuAdmin();
					}

					if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
					
						this->MenuUsuario();	
					}
				}
				if(opciones!=1 || opciones!=2){
					cout << "Recuerde pulse 1 o 2 ! " << endl;
				}	

			}while(opciones!=1 || opciones!=2);
		}

	}

		
	if(encontrado == false){
		cout << DEBUG << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
			cout << endl;
			this->MenuAdmin();
		}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
			cout << endl;

			this->MenuUsuario();
		}
	}
	
	//cout << "Llega " << endl;

	//cout << DEBUG <<  "Posicion alfinal del buscar =  " << posicion << RESTORE << endl;

	return posicion;
}
void CristoFinity::ResizeMultiMediaDism(){
	
	//cout << DEBUG <<  "DEBUG Resize ALPRINCIPIO dimension =  " << RESTORE <<  getTotalMultimedia() << endl;	

	int nueva_dim = getTotalMultimedia()-1;
	MultiMedia** nuevo_vector = new MultiMedia*[nueva_dim];
	
	//cout << DEBUG << "Debug dimension nueva  " << nueva_dim <<  RESTORE << endl;

	if (nuevo_vector == 0){
		cerr << "Error resize en la creación del nuevo vector MultiMedia" << endl;
		exit(-1);
		}

	for(int i=0; i<nueva_dim; i++){

		//cout << DEBUG << "Entra bUCKLE RESIZE " <<  RESTORE << endl;
		nuevo_vector[i] = this-> VectorMultiMedia[i]; 
	}

	delete this->VectorMultiMedia[getTotalMultimedia()-1];
	this->VectorMultiMedia[this->getTotalMultimedia()-1] = 0;
	delete [] this-> VectorMultiMedia;
	this-> VectorMultiMedia = nuevo_vector;
	nuevo_vector = 0;
	delete [] nuevo_vector;
	
	//cout << DEBUG << "Debug dimension alfinal del resize " << nueva_dim <<  RESTORE << endl;	

	this->TotalMultimedia = nueva_dim;
	nueva_dim = 0;
	
	
}

void CristoFinity::IntercambiarMultiMedia(int posicion){
	
	
	MultiMedia *aux;


	if(getTotalMultimedia()>2){
		aux = this->VectorMultiMedia[getTotalMultimedia()-1];
		//cout << DEBUG <<  "LLEGA 1 " << RESTORE << endl; 
		this->VectorMultiMedia[getTotalMultimedia()-1] = this->VectorMultiMedia[posicion];
		//cout << DEBUG <<  "LLEGA 2 " << RESTORE << endl;
		this->VectorMultiMedia[posicion]  = aux;
		this->VectorMultiMedia[posicion]-> setIDMedia(posicion+1);	
		//cout << DEBUG <<  "LLEGA 3 " << RESTORE << endl;
	}
		
}

void CristoFinity::EliminarMultiMedia(){
	int id = 0;
	char Titulo[200];
	
	if(getTotalMultimedia() > 0){

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

							this->EliminarMultiMediaCatalogoYFavoritos(Titulo);
							this->BuscarMultiMediaTitulo(Titulo);
			
							cout << "\n";
					break;
					case 2: 
							cout << "\n";
				
							cout << BLU << "Perfecto, Esta usted en buscar por ID" << RESTORE << endl;
							cout << "\n";
							cout << USER << "Escriba el ID del archivo que desea " << DEBUG << " ELIMINAR " << RESTORE << endl;
							cin >> id;

							this->BuscarMultiMediaID(id);
							
					
			}
		}
	}else{
		cout << DEBUG << "No hay archivos que eliminar " << endl;
	}
	
}
/**********************************************************
**MODIFICAR MEDIA**
**********************************************************/
int CristoFinity::BuscarMultiMediaModificar(string Titulo){
	
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;

	//cout << "Titulo pasado por parametro " << Titulo << endl;

	for(int i=0; i<getTotalMultimedia() && encontrado == false; i++){
		
		if(this->VectorMultiMedia[i]->getTitulo() == Titulo){

			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;
			
		}
	}

	
	if(encontrado == false){
		cout << "\n";
		cout << DEBUG << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
		
						this->MenuAdmin();
			}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){

		}

	}
	

	return posicion;
}
void CristoFinity::ModificarMedia(){
	char Titulo[200];
	int posicion = 0;

	if(getTotalMultimedia()>0){
		cout << USER << "Bienvenido a " << NEW << " MODIFICAR MEDIA " << USER << "comencemos... " << RESTORE << endl;
		cout << NEW << "Introduzca " << USER << " el Titulo del Media que desea MODIFICAR " << endl;
		cin.clear();
		cin.ignore();
		cin.getline(Titulo,200,'\n');
		posicion = this->BuscarMultiMediaModificar(Titulo);
		
		cout << "Archivo Multimedia antes de dynamist cast " << VectorMultiMedia[posicion] << endl;	

		if(posicion>=0){
	

				if(Pelicula *p = dynamic_cast<Pelicula*>(VectorMultiMedia[posicion])){

					if(Serie *s = dynamic_cast<Serie*>(VectorMultiMedia[posicion])){
					cout << SOL << "SERIE:" << RESTORE;
					cin >> this->VectorMultiMedia[posicion];


					}else{
					cout << SOL << "PELICULA:" << RESTORE;
					cin >> this->VectorMultiMedia[posicion];

					}
				}
				if(Cancion *c = dynamic_cast<Cancion*>(VectorMultiMedia[posicion])){
				cout << SOL << "CANCION:" << RESTORE;
				cin >> this->VectorMultiMedia[posicion];

				}

				if(Videojuego *v = dynamic_cast<Videojuego*>(VectorMultiMedia[posicion])){
				cout << SOL << "VIDEOJUEGO:" << RESTORE;
				cin >> this->VectorMultiMedia[posicion];

		}

			if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
		
						this->MenuAdmin();
			}

			if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){

						this->MenuUsuario();
			}
		}
	}else{
		cout << DEBUG << "No hay archivos Multimedia por lo tanto no puede Modificar. " << endl;
		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
		
			this->MenuAdmin();
		}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
			
			this->MenuUsuario();
		}
	}
}
/**********************************************************
**CONSULTAR VALORACION MEDIA DE UN ARCHIVO MULTIMEDIA**
**********************************************************/
void CristoFinity:: ConsultarValoracionMedia(){
	char Titulo[200];
	int posicion = 0;	

	cout << USER << "Bienvenido, que valoracion media desea consultar? Escriba el Titulo. " << RESTORE << endl;
	cin.clear();
	cin.ignore();
	cin.getline(Titulo,200,'\n');
	posicion = this->BuscarMultiMediaTitulo(Titulo);
	
	cout << NEW << "VALORACION MEDIA de " << RESTORE << BLU << this->VectorMultiMedia[posicion]->getTitulo() << RESTORE << endl;
	cout << COPY << "/********************************************************** " << endl;
	cout << COPY << "** "<< NEW2 << this->VectorMultiMedia[posicion]->getValoracionMedia() << COPY << "**" << endl;
	cout << COPY << "/********************************************************** " << RESTORE << endl;
}

/**********************************************************
**INSERTAR COMENTARIO EN ARCHIVO MULTIMEDIA**
**********************************************************//*
int CristoFinity::BuscarMultiMediaComentario(string Titulo){
	
	bool encontrado = false;
	int posicion = 0;
	int opciones = 0;

	//cout << "Titulo pasado por parametro " << Titulo << endl;

	for(int i=0; i<getTotalMultimedia() && encontrado == false; i++){
		//SOLUCIONAR COMO HACER QUE EL USUARIO Y EL ADMINISTRADOR PUEDAN ELIMINAR COMENTARIOS
		if(this->VectorMultiMedia[i]->getTitulo() == this->UsuarioActual->Favo Titulo){

			encontrado = true;
			posicion = i;
			cout << NEW << "Perfecto este archivo multimedia se encuentra en el sistema." << RESTORE << endl;
			
		}
	}

	
	if(encontrado == false){
		cout << "\n";
		cout << DEBUG << "Lo sentimos pero ese Titulo No existe en el catalogo, revise los datos. " << RESTORE << endl;

		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
		
						this->MenuAdmin();
			}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){

		}

	}
	

	return posicion;
}
void CristoFinity::InsertarComentarioenMultiMedia{
	char Titulo[200];
	int posicion = 0;
	int opciones = 0;

	cout << USER << "Bienvenido, que archivo Multimedia desea comentar? Escriba el Titulo" << RESTORE << endl;
	cin.clear();
	cin.ignore();
	cin.getline(Titulo,200,'\n');
	posicion = this->BuscarMultiMediaTitulo(Titulo);

	this->VectorMultiMedia[posicion]->CrearComentario();//INSERTAMOS COMENTARIO EN ARCHIVO MULTIMEDIA CORRESPONDIENTE.

	cout << USER << "Desea visualizar el comentario realizado ? " << RESTORE << endl;
	cin >> opciones;

	if(opciones == 1){
		this->MostrarMultiMedia();
	}else{
		
		if(Admin *ad = dynamic_cast<Admin*>(this->UsuarioActual)){
			cout << endl;
			this->MenuAdmin();
		}

		if(UsuarioNormal *un = dynamic_cast<UsuarioNormal*>(this->UsuarioActual)){
			cout << endl;

			this->MenuUsuario();
		}
	}
}

*/







