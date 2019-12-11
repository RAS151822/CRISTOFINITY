/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 10:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef COMENTARIO_h
#define COMENTARIO_h
#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>

using namespace std;

class Comentario{

	protected:
		unsigned int IDComentario;
		string Login;
		string Texto;

	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Comentario.
		* @pre 
		* @post Definimos los valores de los atributos 
		*/
		Comentario();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Usuario y pasar por parametros los valores para asignarselos al 				objeto Usuario.
		* @param Login (E) es el login para identificar al Usuario dentro del sitema
		* @param Nombre (E) es el nombre del Usuario
		* @param Apellido1 (E) es el  primer apellido del Usuario
		* @param Apellido2 (E) es el segudo apellido del Usuario
		* @param URLFotoPerfil (E) es la url de la foto de perfil del Usuario
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media;;
		*/
		Comentario(unsigned int IDComentario, string Login, string Texto);
				/**
	 	* @brief Método encargado de eliminar el objeto de tipo Comentario.
	 	* @pre .
	 	* @post 
	 	*/
		~Comentario();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor del ID Comentario.
		* @param IDComentario(E) es el IDComentario para identificar el comentario dentro del sistema
	 	* @pre .
	 	* @post Habre introducido el IDMedia de ese archivo Multimedia.
	 	*/
		void setIDComentario(unsigned int IDComentario);

				/**
	 	* @brief  Método encargado de insertar el Login de un comentario.
		* @param Login(E) es el nombre que identifica al Usuario en el sistema y sirve para saber quien hizo el comentario.
	 	* @pre .
	 	* @post Habre introducido el Login del comentario.
	 	*/
		void setLogin(string Login);
		
				/**
	 	* @brief  Método encargado de insertar el Genero del archivo multimedia
		* @param Genero(E) es el Genero al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Genero del archivo multimedia.
	 	*/
		void setTexto(string texto);
		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor del ID Comentario.
		* @param IDComentario(E) es el IDComentario para identificar el comentario dentro del sistema
	 	* @pre .
	 	* @post Habre introducido el IDMedia de ese archivo Multimedia.
	 	*/
		unsigned int getIDComentario();

				/**
	 	* @brief  Método encargado de insertar el Login de un comentario.
		* @param Login(E) es el nombre que identifica al Usuario en el sistema y sirve para saber quien hizo el comentario.
	 	* @pre .
	 	* @post Habre introducido el Login del comentario.
	 	*/
		string setLogin();
		
				/**
	 	* @brief  Método encargado de insertar el Genero del archivo multimedia
		* @param Genero(E) es el Genero al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Genero del archivo multimedia.
	 	*/
		string setTexto();
		
		/**********************************************************
		 ** SOBRECARGAS**
		 **********************************************************/
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Comentario.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post Habremos asignados dos objetos de la clase Comentario
	 	*/
		Comentario& operator=(const Comentario &c);

			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Comentario usando la sintaxis (cout << c). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param c (E) Puntero de tipo Comentario que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos el Comentario correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, const Comentario *c);
		
			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Comentario usando la sintaxis (cin >> u). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param u (E) Puntero de tipo Usuario al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Usuario.
	 	*/
		friend istream& operator>>(istream &flujo,  Comentario *c);

		/**********************************************************
		 ** METODOS**
		 **********************************************************/

				/**
	 	* @brief Método encargado de pedir los datos al Usuario para crear su Comentario
	 	* @pre .
	 	* @post EL usuario habra introducido un comentario con su Login
	 	*/
		void introducirDatosComentario();

};
#endif
