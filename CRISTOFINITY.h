/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 2 de junio de 2019, 21:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef CRISTOFINITY_h
#define CRISTOFINITY_h

#include "MULTIMEDIA.h"
#include "USUARIO.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class CristoFinity{
	
	private:
		
		Usuario** VectorUsuarios; //Vector encargado de guardar todos los Usuarios registrados en el sistema
        	MultiMedia** VectorMultiMedia; // Vector Polimorfico encargado de almacenar todos los archivos que se encuentran en el sitema
		int TotalUsuarios;
		int TotalMultimedia;
		Usuario* UsuarioActual;
		

	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/
			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Cristofinity.
		* @pre Definimos los valores de los atributos TotalUsuarios y TotalMultimedia y reservamos la memoria para los vectores de tipo Usuario y 				Multimedia;
		* @post El sistema nos reservara la memoria correspiendente al objeto;
		*/
		CristoFinity();

		//Constructores y Destructores
			/**
		* @brief Método constructor por parametros  es el encargado de dar memoria al objeto Cristofinity pasando por parametro la cantidad de Usuarios y 			objetos de tipo multimedia que tendra el objeto (cancion, pelicula, Videojuego, Seria.
		* @pre Definimos los valores de los atributos TotalUsuarios y TotalMultimedia y reservamos la memoria para los vectores de tipo Usuario y 				Multimedia;
		* @post Habremos creado el objeto de tipo vista
		*/
		CristoFinity(int TotalUsuarios, int TotalMultimedia );
		
				/**
		* @brief Método encargado de eliminar y poner a 0 el vector de usuarios y el vector multimedia.
		* @pre .
		* @post Habremos eliminado todo el contenido del objeto CristoFinity
		*/
		 ~CristoFinity();

		/**********************************************************
		** SETS **
		**********************************************************/

				/**
	 	* @brief  Método encargado de insertar el valor de los TotalUsuarios que hay  en el vector.
		* @param TotalUsuarios(E) es la variable que almacena la cantidad de Usuarios. Coincide con la dimension del vector de Usuarios.
	 	* @pre TotalUsuarios > 0 .
	 	* @post Habre introducido un nuevo valor para TotalUsuarios con su grado correspondiente en el vector.
	 	*/
		void setTotalUsuarios(int TotalUsuarios);
		
				/**
	 	* @brief  Método encargado de insertar el valor de los TotalMultimedia que hay  en el vector.
		* @param TotalMultimedia(E) es la variable que almacena la cantidad de Archivos. Coincide con la dimension del vector TotalMultimedia.
	 	* @pre TotalMultimedia > 0 .
	 	* @post Habre introducido un nuevo valor para TotalMultimedia con su grado correspondiente en el vector.
	 	*/
        	void setTotalMultimedia(int TotalMultimedia);

		/**********************************************************
		** GETS **
		**********************************************************/

				/**
	 	* @brief  Método encargado de devolver el Total de Usuarios que hay en el vector de Usuarios
		* @param TotalUsuarios (S) es la variable que contiene el Total de Usuarios que coincide con la dimension del vector de Usuarios
	 	* @pre .
	 	* @post Devuelvo el numero Total de Usuarios que contiene el vector de Usuarios.
	 	*/	
		int getTotalUsuarios();

				/**
	 	* @brief  Método encargado de devolver el Total de archivos multimedia que hay en el vector de catalogo
		* @param TotalMedia (S) es la variable que contiene el Total de archivos Multi Media que hay en el vector coincide con la dimension del vector de 				Multimedia
	 	* @pre .
	 	* @post Devuelvo el numero Total de archivos Multimedia que contiene el vector Multimedia.
	 	*/	
		int getTotalMultimedia();

		/**********************************************************
		** MENUs**
		**********************************************************/
				/**
	 	* @brief  Método encargado de  mostrar por pantalla las opciones de agregar archivo multimedia al catalogo.
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones de agregar  archivos MultiMedia  al vector Multimedia
	 	*/	
		void opcionesAgregarEliminarMultiMedia();
		
				/**
	 	* @brief  Método encargado de mostrar por pantalla el menu de agregar archivo multimedia al catalogo.
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones de agregar  archivos MultiMedia  al vector Multimedia.
	 	*/	
		void menuAgregarMultimedia();
	
		
				/**
	 	* @brief  Método encargado de mostrar por pantalla el menu para el Usuario de tipo Administrador
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones especificas para este tipo de Uusario.
	 	*/	
		void MenuAdmin();

				/**
	 	* @brief  Método encargado de  mostrar por pantalla las opciones del INIcio del Programa
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones de el iniicio del programa
	 	*/	
		void OpcionesInicio();

				/**
	 	* @brief  Método encargado de  mostrar por pantalla las opciones del Administrador en el Programa
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones del Administrador
	 	*/	
		void opcionesAdministrador();

				/**
	 	* @brief  Método encargado de  mostrar por pantalla el menu de Buscar en catalogo
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla el menu de Buscar archivo multimedia en catalogo
	 	*/	
		void menuBuscarCatalogo();

				/**
	 	* @brief  Método encargado de mostrar por pantalla el menu para el Usuario Normal
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones especificas para este tipo de Usuario Normal.
	 	*/	
		void MenuUsuario();
		
				/**
	 	* @brief  Método encargado de  mostrar por pantalla las opciones del Usuario Normal
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones del Usuario Normal
	 	*/	
		void opcionesUsuario();

				/**
	 	* @brief  Método encargado de  mostrar por pantalla el menu del Administrador para añadir y eliminarUsuario
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla el menu del Administrador para añadir y eliminarUsuario
	 	*/	
		void menuAgregarEliminarUsuario();

				/**
	 	* @brief  Método encargado de  mostrar por pantalla las opciones del Administrador para añadir y eliminarUsuario
		* @param 
	 	* @pre .
	 	* @post Muestra por pantalla las opciones del Administrador para añadir y eliminarUsuario
	 	*/	
		void opcionesAgregarEliminarUsuario();

		
				/**
	 	* @brief Método  encargado de iniciar el programa empezando pidiendo el Login al Usuario
	 	* @pre .
	 	* @post EL usuario dira si quiere crear un perfil o si esta registrado.
	 	*/
		void MenuInicio();
		/**********************************************************
		 ** PRINT**
		 **********************************************************/
				/**
	 	* @brief Método  encargado de Imprimir un Unico Usuario por la pantalla para ello usaremos la sobrecarga del cout en su interior
	 	* @pre .
	 	* @post Imprimimos en pantalla un unico usuario 
	 	*/
		void ImprimirUsuario(Usuario *u);
		
	 			/**
	 	* @brief Método de imprimir un Usuario por pantalla
	 	* @pre .
	 	* @post 
	 	*/
		void MostrarUsuarios();

				/**
	 	* @brief Método  encargado de Imprimir un Unico MultiMedia por pantalla diferenciando asi las diferentes clases con sus distintos atributos
	 	* @pre .
	 	* @post Imprimimos en pantalla un unico objeto MultiMedia 
	 	*/
		void ImprimirMultiMedia(MultiMedia *m);
		
	 			/**
	 	* @brief Método encargado de mostrar por pantalla todos los medias del CATALOGO
	 	* @pre Debe haber por lo menos un archivo multimedia en el catalogo.
	 	* @post Mostrare por pantalla los diferentes archivos Multimedia con sus respectivos items
	 	*/
		void MostrarMultiMedia();

		/**********************************************************
		 ** RESIZE**
		 **********************************************************/
				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector de tipo Usuario.
	 	* @pre Cuando vaya a redimensionar el vector de Usuario tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces sumare uno 				cada vez que utilice este metodo. De momento no voy a tener problmeas (creo) porque insertare de uno en uno los usuarios y cada vez que 			inserte llamare al resize. Por lo tanto aumentare de uno en uno siempre la dimension del vector de Usuarios
	 	* @post Habre Redimensionado el vector de Usuarios en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeUsuarioAum();

				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector de tipo MultiMedia.
	 	* @pre Cuando vaya a redimensionar el vector de MultiMedia tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces sumare 			uno cada vez que utilice este metodo. De momento no voy a tener problmeas (creo) porque insertare de uno en uno los usuarios y cada vez que 			inserte llamare al resize. Por lo tanto aumentare de uno en uno siempre la dimension del vector de Usuarios
	 	* @post Habre Redimensionado el vector de MultiMedia en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeMultiMediaAum();
		/**********************************************************
		 ** METODOS USUARIO**
		 **********************************************************/
		/**********************************************************
		** INSERTAR**
		**********************************************************/
				/**
	 	* @brief Método  encargado de Insertar Usuarios en el vector de Usuarios
	 	* @pre .
	 	* @post 
	 	*/
		void InsertarUsuario(Usuario *u);

				/**
	 	* @brief Método  encargado de Crear un Usuario en el vector de Usuarios
	 	* @pre .
	 	* @post 
	 	*/
		void CrearUsuario();

				/**
	 	* @brief Método  encargado de pedir los datos al Usuario para entrar en el sistema
	 	* @pre .
	 	* @post El Usuario habra introducido los datos.
	 	*/
		void IntroducirLogin();

				/**
	 	* @brief Método  encargado de saber si el Usuario se ha registrado en el sistema y diferenciar que tipo de Usuario es.
	 	* @pre .
	 	* @post Sabre si el Usuario esta registrado y que tipo de Usuario es según su Login.
	 	*/
		void BuscarUsuario(string Login);

		/**********************************************************
		** ELIMINAR**
		**********************************************************/
				/**
	 	* @brief Método  encargado de saber si el Usuario se encuentra en el sistema registrado y devuelve la posicion de donde se encuentra
	 	* @pre .
	 	* @post Sabre si el Usuario esta registrado y podre devolver la posicion donde se encuentra.
	 	*/
		int BuscarEliminarUsuario(string Login);

				/**
	 	* @brief Método  encargado de disminuir la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. Una de las precondiciones seria comprobar que por lo menos has 			insertado antes una vez sino no puedes realizar el eliminar.
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Disminuir Vector).
	 	*/
		void ResizeUsuarioDism();

				/**
	 	* @brief Método  encargado de intercambiar un Usuario en el vector de Usuarios
		* @param posicion(E) es la variable que almacena la posicion del vector donde esta la direccion de memoria del puntero al objeto MultiMedia que el 				usuario quiere eliminar
	 	* @pre .
	 	* @post Hbremos intercambiado la ultima posicion del vector por la posicion que el usuario indico para eliminar.
	 	*/
		void IntercambiarUsuarios(int posicion);

				/**
	 	* @brief Método  encargado de Eliminar un USUARIO por LOGIN en el vector de Usuarios
	 	* @pre Debe de haber algún Usuario en el vector.
	 	* @post El usuario habra eliminado el Usuario del sistema
	 	*/
		void EliminarUsuarios();

		/**********************************************************
		 ** METODOS USUARIO NORMAL**
		 **********************************************************/
				/**
	 	* @brief Método  encargado de IMPRIMIR el catalogo de FAVORITOS del Usuario Normal.
	 	* @pre Debe de haber algún archivo MultiMedia en el vector.
	 	* @post Imprimira por pantall el catalogo de Favoritos de el Usuario Normal Actual.
	 	*/
		void ImprimirFavoritos();
		/**********************************************************
		** METODOS USUARIOS NORMAL**
		**********************************************************/
				/**
	 	* @brief Método encargado de Buscar un archivo MultiMedia por el titulo del archivo Multimedia en el vector de Favoritos del Usuario
     		* @param Titulo(E) es el Titulo que introduce el usuario para buscar en el vector  de Favoritos del Usuario NOrmal.
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a buscar en el vector.
	 	* @pre Por lo menos debe de haber un archivo MultiMedia creado.
	 	* @post El usuario habra encontrado el archivo MultiMedia que desea guardar en su catalogo de Favoritos
	 	*/
		int BuscarMultiMediaFavoritos(string Titulo);

		/**********************************************************
		** INSERTAR Favoritos**
		**********************************************************/
				/**
	 	* @brief Método  encargado de Insertar archivos MultiMedia en el vector de Favorito del Usuario Normal
	 	* @pre .
	 	* @post Habre añadido un nuevo archivo MultiMedia al vector de Favoritos de un Usuario Normal.
	 	*/
		void InsertarFavoritos();
		
		/**********************************************************
		** ELIMINAR Favoritos**
		**********************************************************/
				/**
	 	* @brief Método  encargado de ELIMINAR archivos MultiMedia en el vector de Favorito del Usuario Normal
	 	* @pre .
	 	* @post Habre ELIMINADO un nuevo archivo MultiMedia al vector de Favoritos de un Usuario Normal.
	 	*/
		void EliminarFavoritos();
		/**********************************************************
		 ** METODOS MULTIMEDIA**
		 **********************************************************/
		/**********************************************************
		** IMPORTAR**
		**********************************************************/
				/**
	 	* @brief Método  encargado de simular una importacion del XML
	 	* @pre .
	 	* @post Habre introducido datos en el sistema(Usuarios, Archivos Multimedia);
	 	*/
		void ImportarXML();

		/**********************************************************
		** INSERTAR MULTIMEDIA**
		**********************************************************/
				/**
	 	* @brief Método  encargado de Insertar archivos multimedia en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		virtual void InsertarMultiMedia(MultiMedia *m);

				/**
	 	* @brief Método  encargado de Crear un clase vista CristoFinity  para poder ejecutar acciones dentro del sistema
	 	* @pre .
	 	* @post 
	 	*/
		CristoFinity* CrearCristoFinity();

				/**
	 	* @brief Método  encargado de Crear un archivo Multimedia en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		void CrearMultiMedia();
		
				/**
	 	* @brief Método  encargado de Crear una Pelicula en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		void CrearPelicula();

				/**
	 	* @brief Método  encargado de Crear una Serie en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		void CrearSerie();

				/**
	 	* @brief Método  encargado de Crear  un Videojuego en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		void CrearVideojuego();

				/**
	 	* @brief Método  encargado de Crear  una Cancion en el vector de archivos Multimedia
	 	* @pre .
	 	* @post 
	 	*/
		void CrearCancion();

		/**********************************************************
		** ELIMINAR MULTIMEDIA**
		**********************************************************/
				/**
	 	* @brief Método  encargado de disminuir la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. Una de las precondiciones seria comprobar que por lo menos has 			insertado antes una vez sino no puedes realizar el eliminar.
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Disminuir Vector).
	 	*/
		void ResizeMultiMediaDism();

				/**
	 	* @brief Método encargado de Buscar un archivo MultiMedia por el ID del archivo Multimedia en el vector de archivos MultiMedia
     		* @param id(E) es el id que introduce el usuario para buscar en el vector MultiMedia
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a eliminar en el vector.
	 	* @pre Por lo menos debe de haber un archivo MultiMedia creado.
	 	* @post El usuario introducira el Id del MultiMedia que desea encontrar
	 	*/
		int BuscarMultiMediaID(int id);

				/**
	 	* @brief Método encargado de Buscar un archivo MultiMedia por el titulo del archivo Multimedia en el vector de archivos MultiMedia
     		* @param Titulo(E) es el Titulo que introduce el usuario para buscar en el vector MultiMedia
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a eliminar en el vector.
	 	* @pre Por lo menos debe de haber un archivo MultiMedia creado.
	 	* @post El usuario introducira el Id del MultiMedia que desea encontrar
	 	*/
		int BuscarMultiMediaTitulo(string Titulo);

				/**
	 	* @brief Método  encargado de intercambiar un archivo MultiMedia en el vector MultiMedia
		* @param posicion(E) es la variable que almacena la posicion del vector donde esta la direccion de memoria del puntero al objeto MultiMedia que el 				usuario quiere eliminar
	 	* @pre .
	 	* @post Hbremos intercambiado la ultima posicion del vector por la posicion que el usuario indico para eliminar.
	 	*/
		void IntercambiarMultiMedia(int posicion);

				/**
	 	* @brief Método  encargado de Eliminar un archivo MultiMedia por ID en el vector MultiMedia
	 	* @pre Debe de haber algún archivo MultiMedia en el vector.
	 	* @post El usuario habra eliminado el archivo MultiMedia
	 	*/
		void EliminarMultiMedia();

		/**********************************************************
		** MODIFICAR MULTIMEDIA**
		**********************************************************/
				/**
	 	* @brief Método encargado de Buscar un archivo MultiMedia por el titulo del archivo Multimedia en el vector de archivos MultiMedia
     		* @param Titulo(E) es el Titulo que introduce el usuario para buscar en el vector MultiMedia
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a eliminar en el vector.
	 	* @pre Por lo menos debe de haber un archivo MultiMedia creado.
	 	* @post El usuario introducira el Id del MultiMedia que desea encontrar
	 	*/
		int BuscarMultiMediaModificar(string Titulo);

				/**
	 	* @brief Método  encargado de Modificar un archivo MultiMedia por Login en el vector MultiMedia
	 	* @pre Debe de haber algún archivo MultiMedia en el vector.
	 	* @post El usuario habra modificado el archivo MultiMedia deseado
	 	*/
		void ModificarMedia();
		/**********************************************************
		** MODIFICAR MULTIMEDIA**
		**********************************************************/
		void  ConsultarValoracionMedia();
		void EliminarMultiMediaCatalogoYFavoritos(string Titulo);
};
#endif
