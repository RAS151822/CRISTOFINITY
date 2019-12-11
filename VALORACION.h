/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 10:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef VALORACION_h
#define VALORACION_h
#include <iostream>
#include <string.h>
#include <fstream>
#include <typeinfo>

using namespace std;

class Valoracion{

	protected:
		string IDUsuario;
		float Puntuacion;

	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/
		
			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Valoracion.
		* @pre 
		* @post Definimos los valores de los atributos 
		*/
		Valoracion();
		
			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Valoracion y pasar por parametros los valores para asignarselos 				al objeto Valoracion.
		* @param IDUsuario (E) sirve para identificar el comentario del Usuario.
		* @param Puntuacion (E) es la calificacion dada al archivo multimedia
		* @post Habremos introducido los valores de IDUsuario y la PUntuacion
		*/
		Valoracion(string IDUsuario, float Puntuacion);

		
			/**
		* @brief Método  encargado de eliminar el objeto Valoracion.
		* @pre 
		* @post Habremos destruido el objeto dentro del sistema
		*/
		~Valoracion();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor del ID Usuario.
		* @param IDUsuario(E) es el IDUsuario para identificar el comentario dentro del sistema
	 	* @pre .
	 	* @post Habre introducido el IDUsuario de esa valoracion.
	 	*/
		void setIDUsuario(string IDUsuario);

				/**
	 	* @brief  Método encargado de insertar la Puntuacion de un Valoracion.
		* @param Puntuacion(E) es la puntucion sobre un archivo multimedia.
	 	* @pre .
	 	* @post Habre introducido el Login del comentario.
	 	*/
		void setPuntuacion(float Puntuacion);
		
		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de devolver el valor del ID Usuario.
		* @param IDUsuario(E) es el IDUsuario para identificar el comentario dentro del sistema
	 	* @pre .
	 	* @post Devolvere el valor de el IDUsuario de esa valoracion.
	 	*/
		string getIDUsuario();

				/**
	 	* @brief  Método encargado de insertar la Puntuacion de un Valoracion.
		* @param Puntuacion(E) es la puntucion sobre un archivo multimedia.
	 	* @pre .
	 	* @post Habre introducido el Login del comentario.
	 	*/
		float getPuntuacion();

		/**********************************************************
		 ** SOBRECARGAS**
		 **********************************************************/
				/**
	 	* @brief Método sobrecargando el simbolo = encargado de asignar dos Valoraciones.
		*@param v(E) puntero que al ser pasado por referencia se refiere al contenido del objeto al que este señala.
	 	* @pre Deben ser objetos de la misma clase.
	 	* @post  Devolvemos el puntero this  y habremos asignados dos objetos de la clase Valoracion
	 	*/
		Valoracion& operator=(const Valoracion &v);

			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Comentario usando la sintaxis (cout << v). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param c (E) Puntero de tipo Comentario que vamos a mostrar por pantalla.
		* @param flujo (S) devolveremos el flujo mostrando el objeto por pantalla.
	 	* @pre .
	 	* @post Imprimiremos la Valoracion correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo, const Valoracion *v);
		
			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Valoracion usando la sintaxis (cin >> v). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param v (E) Puntero de tipo Valoracion al que introduciremos los datos.
		* @param flujo (S) devolveremos el flujo mostrando el objeto por pantalla.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Valoracion.
	 	*/
		friend istream& operator>>(istream &flujo,  Valoracion *v);

		/**********************************************************
		 ** METODOS**
		 **********************************************************/

				/**
	 	* @brief Método encargado de pedir los datos  en Valoracion para crear su Valoracion
	 	* @pre .
	 	* @post EL usuario habra introducido una Valoracion con su ID
	 	*/
		void introducirDatosValoracion();
};
#endif
