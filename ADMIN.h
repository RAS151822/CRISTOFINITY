/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 12 de junio de 2019, 21:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef ADMIN_h
#define ADMIN_h
#include "USUARIO.h"
#include <iostream>
#include <string.h>

using namespace std;

class Admin : public Usuario{
	
	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Usuario Admin.
		* @pre 
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media
		*/
		Admin();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Usuario Admin.
		* @pre 
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media
		*/
		Admin(string Login, string nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalMediaVisto);
				/**
	 	* @brief Método encargado de eliminar el objeto de tipo Usuario.
	 	* @pre .
	 	* @post 
	 	*/
		~Admin();
		
		/**********************************************************
		 ** SOBRECARGAS**
		 **********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Administrador usando la sintaxis (cout << u). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param u (E) Puntero de tipo Usuario Administrador que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos el Usuario correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo,  Admin *u);
		
			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Administrador usando la sintaxis (cin >> u). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param u (E) Puntero de tipo Usuario Administrador al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Usuario.
	 	*/
		friend istream& operator>>(istream &flujo,  Admin *u);

};
#endif
