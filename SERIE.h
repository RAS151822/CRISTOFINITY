/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef SERIE_h
#define SERIE_h
#include "PELICULA.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>

using namespace std;

class Serie : public Pelicula{

		private:
			int Temporadas;
			int Capitulos;
			bool Estado;
		public:

		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Serie.
		* @pre 
		* @post Definimos los valores de los atributos del objeto Serie.
		*/
		Serie();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Videojuego pasand por referencia los parametros.
		* @param Temporadas(E) es la variable que almacena Temporadas de la Serie
		* @param Capitulos(E)es la variable que almacena los capitulos de la Serie
		* @param Estado(E) es la variable que almacena el Estado de la serie
		* @post Definimos los valores de los atributos del objeto Serie.
		*/
		Serie(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, string Reparto, string Direccion, string Guion, string Productor, int Temporadas, int Capitulos, bool Estado, int TotalVectorValoraciones, int MeGusta, unsigned int TotalVectorComentarios);

			/**
		* @brief Método destructor por defecto es el encargado de eliminar el objeto Serie.
		* @pre 
		* @post Definimos los valores de los atributos del objeto Pelicula a null o a 0.
		*/
		~Serie();

		/**********************************************************
		** SETS **
		**********************************************************/

				/**
	 	* @brief  Método encargado de insertar el valor de Desarrollador.
		* @param Reparto(E) es el Desarrollador para identificar  el Videojuego
	 	* @pre .
	 	* @post Habre introducido las Temporadas totales de la Serie
	 	*/
		void setTemporadas(int Temporadas);

				/**
	 	* @brief  Método encargado de insertar el valor de Capitulos.
		* @param Capitulos(E) es la variable que almacena Capitulos de la Serie
	 	* @pre .
	 	* @post Habre introducido los  Capitulos totales de la Serie
	 	*/
		void setCapitulos(int Capitulos);

				/**
	 	* @brief  Método encargado de insertar el valor de Estado.
		* @param Estado(E) es la variable que almacena el Estado de la Serie
	 	* @pre .
	 	* @post Habre introducido el Estado de la Serie
	 	*/
		void setEstado(bool Estado);

		/**********************************************************
		** GETS **
		**********************************************************/
		
				/**
	 	* @brief  Método encargado de devolver el valor de Desarrollador.
		* @param Reparto(S) es el Desarrollador para identificar  el Videojuego
	 	* @pre .
	 	* @post Habre devuelto las Temporadas totales de la Serie
	 	*/
		int getTemporadas();

				/**
	 	* @brief  Método encargado de devolver el valor de Capitulos.
		* @param Capitulos(S) es la variable que almacena Capitulos de la Serie
	 	* @pre .
	 	* @post Habre devuelto los  Capitulos totales de la Serie
	 	*/
		int getCapitulos();

				/**
	 	* @brief  Método encargado de devolver el valor de Estado.
		* @param Estado(E) es la variable que almacena el Estado de la Serie
	 	* @pre .
	 	* @post Habre devuelto el Estado de la Serie
	 	*/
		bool getEstado();

		/**********************************************************
		** SOBRECARGA **
		**********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase SERIE usando la sintaxis (cout << s). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función 				externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir la Serie.
		* @param s (E) Puntero (direccion de memoria que apunta) de tipo Serie que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos la Serie correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, Serie *s);

		
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Series.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post Habremos asignados dos objetos de la clase Serie
	 	*/
		Serie& operator=(const Serie &s);

			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Serie usando la sintaxis (cin >> s). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param s (E) Puntero de tipo Serie al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Serie.
	 	*/
		friend istream& operator>>(istream &flujo,  Serie *s);	

};
#endif
