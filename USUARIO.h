/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 12 de junio de 2019, 21:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef USUARIO_h
#define USUARIO_h
#include "MULTIMEDIA.h"
#include <iostream>
#include <string.h>

using namespace std;

class Usuario{
	
	protected:
	
		string Login;
        	string Nombre;
		string Apellidos;
        	string URLFotoPerfil;
		MultiMedia** VectorMediaVisto;//Vector Polimorfico de archivos Multimedia
		unsigned int TotalMediaVisto;//Dimension del vector Media coincicde con los componentes que pueden ser ocupados
		
	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Usuario.
		* @pre 
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media;;
		*/
		Usuario();
			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Usuario y pasar por parametros los valores para asignarselos al 				objeto Usuario.
		* @param Login (E) es el login para identificar al Usuario dentro del sitema
		* @param Nombre (E) es el nombre del Usuario
		* @param Apellido1 (E) es el  primer apellido del Usuario
		* @param Apellido2 (E) es el segudo apellido del Usuario
		* @param URLFotoPerfil (E) es la url de la foto de perfil del Usuario
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media;;
		*/
		Usuario( string Login, string nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalMediaVisto);
				/**
	 	* @brief Método encargado de eliminar el objeto de tipo Usuario.
	 	* @pre .
	 	* @post 
	 	*/
		virtual ~Usuario();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de Login.
		* @param Login(E) es el login para identificar al Usuario dentro del sitema
	 	* @pre .
	 	* @post Habre introducido el Login del usuario.
	 	*/
		void setLogin(string Login);

				/**
	 	* @brief  Método encargado de insertar el valor de nombre.
		* @param nombre(E) es el nombre del Usuario
	 	* @pre .
	 	* @post Habre introducido el nombre del usuario.
	 	*/
		void setNombre(string nombre);
		
				/**
	 	* @brief  Método encargado de insertar el valor de Apellido1
		* @param Apellido1(E) es el Apellido1 del Usuario
	 	* @pre .
	 	* @post Habre introducido el Apellido1 del usuario.
	 	*/
		void setApellido(string Apellido1);
				/**
	 	* @brief  Método encargado de insertar el valor de la URL de la foto de perfil del usuario
		* @param URLfotoPerfil(E) es el la ruta de la foto del perfil del Usuario
	 	* @pre .
	 	* @post Habre introducido la URL de la foto del perfil del Usuario
	 	*/
		void setURLFotoPerfil(string URLFotoPerfil);
				/**
	 	* @brief  Método encargado de insertar el valor de el total de archivos multimedia que contiene el Usuario en su perfil
		* @param TotalMediaVisto(E) es la variable que almacena la cantidad de objetos multimedia seleccionado por el usuario
	 	* @pre .
	 	* @post Habre introducido la URL de la foto del perfil del Usuario
	 	*/
		void setTotalMediaVisto(int TotalMediaVisto);

				/**
	 	* @brief  Método encargado de devolver el Login del Usuario
		* @param Login (S) es la variable que contiene el Login del Usuario
	 	* @pre .
	 	* @post Devuelvo el login del Usuario.
	 	*/

		/**********************************************************
		** GETS **
		**********************************************************/
		string getLogin();
		
				/**
	 	* @brief  Método encargado de devolver el Nombre del Usuario
		* @param Nombre (S) es la variable que contiene el Nombre del Usuario
	 	* @pre .
	 	* @post Devuelvo el Nombre del Usuario.
	 	*/	
		string getNombre();

				/**
	 	* @brief  Método encargado de devolver el Apellido del Usuario
		* @param Apellido (S) es la variable que contiene el Apellido del Usuario
	 	* @pre .
	 	* @post Devuelvo el Apellido del Usuario.
	 	*/	
		string getApellido();

				/**
	 	* @brief  Método encargado de devolver la URL de la Foto de Perfil del Usuario
		* @param URLFotoPerfil (S) es la variable que contiene la URL de la Foto de Perfil del Usuario
	 	* @pre .
	 	* @post Devuelvo la URL de la Foto de Perfil del Usuario.
	 	*/	
		string getURLFotoPerfil();
		
				/**
	 	* @brief  Método encargado de devolver el número total de contenido multimedia que posee el usuario.
		* @param TotalMediaVisto (S) es la variable que contiene el número total de contenido multimedia que posee el usuario.
	 	* @pre .
	 	* @post Devuelvo el número total de contenido multimedia que posee el usuario.
	 	*/	
		int getTotalMediaVisto();

		/**********************************************************
		 ** SOBRECARGAS**
		 **********************************************************/
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Usuarios.
	 	* @pre .
	 	* @post 
	 	*/
		Usuario& operator=(const Usuario &u);

			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Usuario usando la sintaxis (cout << u). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param u (E) Puntero de tipo Usuario que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos el Usuario correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, const Usuario *u);
		
			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Usuario usando la sintaxis (cin >> u). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param u (E) Puntero de tipo Usuario al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Usuario.
	 	*/
		friend istream& operator>>(istream &flujo,  Usuario *u);

		/**********************************************************
		 ** METODOS**
		 **********************************************************/

				/**
	 	* @brief Método encargado de pedir los datos al Usuario para crear su perfil
	 	* @pre .
	 	* @post EL usuario habra personalizado e introducido sus datos
	 	*/
		void introducirDatos();
		
				/**
	 	* @brief Método encargado de Buscar un Media por el ID del Media en el vector de Medias
     		* @param id(E) es el id que introduce el usuario para buscar en el vector de Medias.
	 	* @pre Por lo menos debe de haber un Media creado.
	 	* @post El usuario introducira el Id del Media que desea encontrar
	 	*/
		int BuscarMultiMedia(int id);

		/**********************************************************
		 **INSERTAR MEDIA VISTO**
		 **********************************************************/
				/**
	 	* @brief Método encargado de insertar los Medias vistos por todos los Usuarios del sistema
	 	* @pre .
	 	* @post Tanto el Administrador como el U.Normal cada vez que hagan una busqueda su busqueda quedara guardada aqui.
	 	*/
		void InsertarMediaVisto(MultiMedia *m);

				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector Media Visto.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces 			incrementare +1 la dimension cada vez que utilice este metodo.  Por lo tanto aumentare de uno en uno siempre la dimension del vector de 			Comentario
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeAumMediaVisto();
		/**********************************************************
		** INSERTAR Favoritos**
		**********************************************************/
				/**
	 	* @brief Método encargado de insertar los Medias seleccionados por el Usuario Normal para su catalogo de favoritos. Solo me sirve para conectar entre
			el puntero de usuario actual y la subclase Usuario Normal y poder ejecutar sus metodos.
	 	* @pre .
	 	* @post el U.Normal cada vez que seleccione un Media se guardara en su vector de Favoritos.
		*/
		void InsertarFavoritos(MultiMedia *m);
		
		/**********************************************************
		** MOSTRAR Favoritos**
		**********************************************************/
				/**
	 	* @brief Método encargado de enlazar el puntero usuario actual con los metodos de la subclase Usuario Normal
	 	* @pre 
	 	* @post Mostrare por pantalla los diferentes archivos Multimedia con sus respectivos items que contiene cada usuario.
	 	*/
		void MostrarFavoritos();

		/**********************************************************
		** ELIMINAR Favoritos**
		**********************************************************/
				/**
	 	* @brief Método  encargado de ELIMINAR archivos MultiMedia en el vector de Favorito del Usuario Normal
	 	* @pre .
	 	* @post Habre ELIMINADO un nuevo archivo MultiMedia al vector de Favoritos de un Usuario Normal.
	 	*/
		void EliminarFavoritos();
};
#endif
