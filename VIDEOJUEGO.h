/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 6 de junio de 2019, 21:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef VIDEOJUEGO_h
#define VIDEOJUEGO_h
#include "MULTIMEDIA.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>

using namespace std;

class Videojuego : public MultiMedia{

		protected:
			string Desarrollador;
			string Editor;
			int Jugadores;
			string Plataforma;

		public:

		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Videojuego.
		* @pre 
		* @post Definimos los valores de los atributos del objeto Videojuego.
		*/
		Videojuego();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Videojuego pasand por referencia los parametros.
		* @param Desarrollador(E) es la variable que almacena el Desarrollador del Videojuego
		* @param Editor(E)es la variable que almacena Editor del Videojuego
		* @param Jugadores(E) es la variable que almacena la cantidad de Jugadores del Videojuego
		* @param Plataformas(E) es la variable que almacena la informacion sobre Plataformas del Videojuego
		* @post Definimos los valores de los atributos del objeto Pelicula.
		*/
		Videojuego(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion,string Desarrollador, string Plataforma, string Editor, int Jugadores, int TotalVectorValoraciones , int MeGusta, unsigned int TotalVectorComentarios);

			/**
		* @brief Método destructor por defecto es el encargado de eliminar el objeto Videojuego.
		* @pre 
		* @post Definimos los valores de los atributos del objeto Pelicula a null o a 0.
		*/
		~Videojuego();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de Desarrollador.
		* @param Reparto(E) es el Desarrollador para identificar  el Videojuego
	 	* @pre .
	 	* @post Habre introducido el Editor del Videojuego
	 	*/
		void setDesarrollador(string Desarrollador);

				/**
	 	* @brief  Método encargado de insertar el valor de Editor.
		* @param Editor(E) es la variable que almacena el Editor del Videojuego
	 	* @pre .
	 	* @post Habre introducido el Editor del Videojuego
	 	*/
		void setEditor(string Editor);

				/**
	 	* @brief  Método encargado de insertar el valor de Jugadores.
		* @param Jugadores(E) es la variable que almacena la cantidad de Jugadores del Videojuego
	 	* @pre .
	 	* @post Habre introducido los Jugadores del Videojuego
	 	*/
		void setJugadores(int Jugadores);

				/**
	 	* @brief  Método encargado de insertar el valor de Plataformas.
		* @param Editor(E) es la variable que almacena Plataforma del Videojuego
	 	* @pre .
	 	* @post Habre introducido la Plataforma del Videojuego
	 	*/
		void setPlataforma(string Plataforma);


		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de devolver el valor de Desarrollador.
		* @param Reparto(S) es el Desarrollador para identificar  el Videojuego
	 	* @pre .
	 	* @post Habre devuelto el Editor del Videojuego
	 	*/
		string getDesarrollador();

				/**
	 	* @brief  Método encargado de devolver el valor de Editor.
		* @param Editor(S) es la variable que almacena el Editor del Videojuego
	 	* @pre .
	 	* @post Habre devuelto el Editor del Videojuego
	 	*/
		string getEditor();

				/**
	 	* @brief  Método encargado de devolver el valor de Jugadores.
		* @param Jugadores(S) es la variable que almacena la cantidad de Jugadores del Videojuego
	 	* @pre .
	 	* @post Habre devuelto los Jugadores del Videojuego
	 	*/
		int getJugadores();

				/**
	 	* @brief  Método encargado de devolver el valor de Plataformas.
		* @param Editor(S) es la variable que almacena Plataforma del Videojuego
	 	* @pre .
	 	* @post Habre devuelto la Plataforma del Videojuego
	 	*/
		string getPlataforma();
		/**********************************************************
		** SOBRECARGA **
		**********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Videojuego usando la sintaxis (cout << s). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función 				externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Videojuego.
		* @param v (E) Puntero (direccion de memoria que apunta) de tipo Videojuego que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos  el Videojuego correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, Videojuego *v);

		
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Videojuegos.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post Habremos asignados dos objetos de la clase Videojuego
	 	*/
		Videojuego& operator=(const Videojuego &v);

			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Serie usando la sintaxis (cin >> s). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param v (E) Puntero de tipo Videojuego al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Videojuego.
	 	*/
		friend istream& operator>>(istream &flujo,  Videojuego *v);	

};
#endif
