/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef PELICULA_h
#define PELICULA_h
#include "MULTIMEDIA.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

class Pelicula : public MultiMedia{

		protected:
			string Reparto;
			string Direccion;
			string Guion;
			string Productor;

		public:

		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Pelicula.
		* @pre 
		* @post Definimos los valores de los atributos del objeto cancion.
		*/
		Pelicula();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Pelicula pasand por referencia los parametros.
		* @param Reparto(E) es la variable que almacena el reparto de la pelicula
		* @param Direccion(E)es la variable que almacena la direccion del cortometraje
		* @param Guion(E) es la variable que almacena el guion de la peli
		* @param Productor(E) es la variable que almacena la informacion sobre el productor
		* @post Definimos los valores de los atributos del objeto Pelicula.
		*/
		Pelicula(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, string Reparto, string Direccion, string Guion, string Productor, int TotalVectorValoraciones, int MeGusta, unsigned int TotalVectorComentarios);

			/**
		* @brief Método destructor por defecto es el encargado de eliminar el objeto Pelicula.
		* @pre 
		* @post Definimos los valores de los atributos del objeto Pelicula a null o a 0.
		*/
		~Pelicula();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de Reparto.
		* @param Reparto(E) es el Reparto para identificar la pelicula dentro del sistema
	 	* @pre .
	 	* @post Habre introducido el Reparto de esa cancion.
	 	*/
		void setReparto(string Reparto);

				/**
	 	* @brief  Método encargado de insertar el Guion en una pelicula.
		* @param Guion(E) es el Guion del archivo pelicula
	 	* @pre .
	 	* @post Habre introducido el Guion de la pelicula.
	 	*/
		void setGuion(string Guion);

				/**
	 	* @brief  Método encargado de insertar la Direccion en una pelicula.
		* @param Direccion(E) es la Direccion del archivo pelicula
	 	* @pre .
	 	* @post Habre introducido la Direccion de la pelicula.
	 	*/
		void setDireccion(string Direccion);

				/**
	 	* @brief  Método encargado de insertar el Productor en una pelicula.
		* @param Direccion(E) es la Direccion del archivo pelicula
	 	* @pre .
	 	* @post Habre introducido el Productor de la pelicula.
	 	*/
		void setProductor(string Productor);

		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de devolver el valor de Reparto.
		* @param Reparto(E) es el Reparto para identificar la pelicula dentro del sistema
	 	* @pre .
	 	* @post Habre devuelto el Reparto de esa cancion.
	 	*/
		string getReparto();

				/**
	 	* @brief  Método encargado de devolver el Guion en una pelicula.
		* @param Guion(E) es el Guion del archivo pelicula
	 	* @pre .
	 	* @post Habre devuelto el Guion de la pelicula.
	 	*/
		string getGuion();

				/**
	 	* @brief  Método encargado de devolver la Direccion en una pelicula.
		* @param Direccion(E) es la Direccion del archivo pelicula
	 	* @pre .
	 	* @post Habre devuelto la Direccion de la pelicula.
	 	*/
		string getDireccion();

				/**
	 	* @brief  Método encargado de devolver el Productor en una pelicula.
		* @param Direccion(E) es la Direccion del archivo pelicula
	 	* @pre .
	 	* @post Habre devuelto el Productor de la pelicula.
	 	*/
		string getProductor();
		/**********************************************************
		** SOBRECARGA **
		**********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Pelicula usando la sintaxis (cout << c). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función 				externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir la Pelicula.
		* @param p (E) Puntero (direccion de memoria que apunta) de tipo Pelicula que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos la Pelicula correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, Pelicula *p);

		
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Peliculas.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post Habremos asignados dos objetos de la clase Pelicula
	 	*/
		Pelicula& operator=(const Pelicula &p);

			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Peliula usando la sintaxis (cin >> p). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param p (E) Puntero de tipo Peliula al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Peliula.
	 	*/
		friend istream& operator>>(istream &flujo,  Pelicula *p);	

};
#endif
