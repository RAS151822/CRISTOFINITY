/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef CANCION_h
#define CANCION_h
#include "MULTIMEDIA.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Cancion : public MultiMedia{

		private:
			string Artista;
			string Album;

		public:

		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Cancion.
		* @pre 
		* @post Definimos los valores de los atributos del objeto cancion.
		*/
		Cancion();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Cancion pasand por referencia los parametros.
		* @pre 
		* @post Definimos los valores de los atributos del objeto cancion.
		*/
		Cancion(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, int TotalVectorValoraciones, string Artista, string Album,int MeGusta, unsigned int TotalVectorComentarios);

			/**
		* @brief Método destructor por defecto es el encargado de eliminar el objeto cancion.
		* @pre 
		* @post Definimos los valores de los atributos del objeto cancion a null o a 0.
		*/
		~Cancion();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de Artista.
		* @param Artista(E) es el Artista para identificar la cancion dentro del sistema
	 	* @pre .
	 	* @post Habre introducido el Artista de esa cancion.
	 	*/
		void setArtista(string Artista);

				/**
	 	* @brief  Método encargado de insertar el Album en una cancion.
		* @param Album(E) es el Album del archivo cancion
	 	* @pre .
	 	* @post Habre introducido el Album de la cancion.
	 	*/
		void setAlbum(string Album);

		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de devolver el valor de Artista.
	 	* @pre .
	 	* @post Habre devuelto el Artista de esa cancion.
	 	*/
		string getArtista();

				/**
	 	* @brief  Método encargado de devolver el Album en una cancion.
	 	* @pre .
	 	* @post Habre devuelto el Album de la cancion.
	 	*/
		string getAlbum();

		/**********************************************************
		** SOBRECARGA **
		**********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Cancion usando la sintaxis (cout << c). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param c (E) Puntero de tipo Cancion que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos la Cancion correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo,  Cancion *c);

				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Canciones.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post Habremos asignados dos objetos de la clase Cancion
	 	*/
		Cancion& operator=(const Cancion &c);

			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Cancion usando la sintaxis (cin >> c). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param c (E) Puntero de tipo Cancion al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Cancion.
	 	*/
		friend istream& operator>>(istream &flujo,  Cancion *c);		
};
#endif
