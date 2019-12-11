/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 5 de junio de 2019, 9:20
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef MULTIMEDIA_h
#define MULTIMEDIA_h
#include "MULTIMEDIA.h"
#include "COMENTARIO.h"
#include "VALORACION.h"
#include <iostream>
#include <string.h>
#include <fstream>


using namespace std;

class MultiMedia{
	
	protected:
		unsigned int IDMedia;
		string Titulo;
		string Genero;
		int DuracionEnSegundos;
		string FechaPublicacion;
		int Pegi;
		string Descripcion;
		Valoracion** VectorValoraciones;
		unsigned int TotalVectorValoraciones;
		float ValoracionMedia;
		int MeGusta;
		Comentario** VectorComentario;
		unsigned int TotalVectorComentarios;

	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Multimedia.
		* @pre 
		* @post Definimos los valores de los atributos  y reservamos la memoria para los vectores de tipo Valoracion y Comentario;
		*/
		MultiMedia();
			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Multimedia y pasar por parametros los valores para asignarselos 				al objeto Multimedia.
		* @param  IDMedia (E) es el login para identificar el Multimedia dentro del sitema
		* @param  Titulo (E) es el Titulo de cada archivo multimedia de la clase MultiMedia
		* @param  Genero (E) es el Genero al que pertenece cada archivo Multimedia
		* @param  DuracionEnSegundos(E) es la duracion en segundos de cada archivo Multimedia .
		* @param  FechaPublicacion (E) es la Fecha en la que se publico ese archivo Multimedia.
		* @param  Pegi(E) es la edad en la que se clasifica cada archivo Multimedia .
		* @param  Descripcion (E) es la descripcion o pequeño resumen de en que consiste ese archivo Multimedia.
		* @param  TotalVectorValoraciones (E) es la variable que almacena el total de valoraciones sobre los archvios multimedia coincide con la dimension 				del vector Valoracion.
		* @param  ValoracionMedia(E) es la valoracion que hace cada usuario sobre ese archivo Multimedia.
		* @param  MeGusta(E) son los likes que dan los Usuarios sobre ese archivo Multimedia.
		* @param  TotalVectorComentarios(E) son los likes que dan los Usuarios sobre ese archivo Multimedia.
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Valoracion y Comentario;
		*/
		MultiMedia(unsigned int IDMedia, string Titulo, string Genero, int DuracionEnSegundos, string FechaPublicacion, int Pegi, string Descripcion, int 		TotalVectorValoraciones ,float ValoracionMedia, int MeGusta,unsigned int TotalVectorComentarios);
				/**
	 	* @brief Método encargado de eliminar el objeto de tipo Multimedia.
	 	* @pre .
	 	* @post Habré eliminado los vectores de tipo valoracion y comentario y puesto a "NULL" los objetos de tipo Multimedia
	 	*/
		virtual ~MultiMedia();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de IDMedia.
		* @param IDMedia(E) es el IDMedia para identificar al archivo Multimedia dentro del sitema
	 	* @pre .
	 	* @post Habre introducido el IDMedia de ese archivo Multimedia.
	 	*/
		void setIDMedia(unsigned int IDMedia);

				/**
	 	* @brief  Método encargado de insertar el Titulo de un archvio multimedia.
		* @param Titulo(E) es el Titulo del archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Titulo del archivo multimedia.
	 	*/
		void setTitulo(string Titulo);
		
				/**
	 	* @brief  Método encargado de insertar el Genero del archivo multimedia
		* @param Genero(E) es el Genero al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Genero del archivo multimedia.
	 	*/
		void setGenero(string Genero);
		
				/**
	 	* @brief  Método encargado de insertar  la DuracionEnSegundos del archivo multimedia
		* @param DuracionEnSegundos(E) es la Duracion En Segundos de cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido la DuracionEnSegundos del archivo multimedia.
	 	*/
		void setDuracionEnSegundos(int DuracionEnSegundos);

				/**
	 	* @brief  Método encargado de insertar  la FechaPublicaciondel archivo multimedia
		* @param FechaPublicacion(E) es la Fecha de Publicacion de cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido la Fecha de Publicacion del archivo multimedia.
	 	*/
		void setFechaPublicacion(string FechaPublicacion);

				/**
	 	* @brief  Método encargado de insertar el Pegi del archivo multimedia
		* @param Pegi(E) es el Pegi al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Pegi del archivo multimedia.
	 	*/
		void setPegi(int Pegi);
		
				/**
	 	* @brief  Método encargado de insertar la Descripcion del archivo multimedia
		* @param Descripcion(E) es la Descripcion de cada archivo multimedia
	 	* @pre .
	 	* @post Habre introducido la Descripcion del archivo multimedia.
	 	*/
		void setDescripcion(string Descripcion);

				/**
	 	* @brief  Método encargado de insertar el Total de Valoraciones del archivo multimedia
		* @param DTotalVectorValoraciones(E) es el Total de Valoraciones del archivo multimedia
	 	* @pre .
	 	* @post Habre introducido el Total de Valoraciones del archivo multimedia.
	 	*/
		void setTotalVectorValoraciones(unsigned int TotalVectorValoraciones);

				/**
	 	* @brief  Método encargado de insertar la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre introducido  la Valoracion del archivo multimedia.
	 	*/
		void setValoracionMedia(float ValoracionMedia);

				/**
	 	* @brief  Método encargado de insertar la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre introducido  la Valoracion del archivo multimedia.
	 	*/
		void setMeGusta(int MeGusta);

				/**
	 	* @brief  Método encargado de insertar la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre introducido  la Valoracion del archivo multimedia.
	 	*/
		void setTotalVectorComentarios(unsigned int TotalVectorComentarios);
		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de devolver el valor de IDMedia.
		* @param IDMedia(E) es el IDMedia para identificar al archivo Multimedia dentro del sitema
	 	* @pre .
	 	* @post Habre devuelto el IDMedia de ese archivo Multimedia.
	 	*/
		unsigned int getIDMedia();

				/**
	 	* @brief  Método encargado de devolver el Titulo de un archvio multimedia.
		* @param Titulo(E) es el Titulo del archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto el Titulo del archivo multimedia.
	 	*/
		string getTitulo();
		
				/**
	 	* @brief  Método encargado de devolver el Genero del archivo multimedia
		* @param Genero(E) es el Genero al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto el Genero del archivo multimedia.
	 	*/
		string getGenero();
		
				/**
	 	* @brief  Método encargado de devolver  la DuracionEnSegundos del archivo multimedia
		* @param DuracionEnSegundos(E) es la Duracion En Segundos de cada archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto la DuracionEnSegundos del archivo multimedia.
	 	*/
		int getDuracionEnSegundos();

				/**
	 	* @brief  Método encargado de devolver  la FechaPublicaciondel archivo multimedia
		* @param FechaPublicacion(E) es la Fecha de Publicacion de cada archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto la Fecha de Publicacion del archivo multimedia.
	 	*/
		string  getFechaPublicacion();

				/**
	 	* @brief  Método encargado de devolver el Pegi del archivo multimedia
		* @param Pegi(E) es el Pegi al que pertenece cada archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto el Pegi del archivo multimedia.
	 	*/
		int getPegi();
		
				/**
	 	* @brief  Método encargado de devolver la Descripcion del archivo multimedia
		* @param Descripcion(E) es la Descripcion de cada archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto la Descripcion del archivo multimedia.
	 	*/
		string getDescripcion();

				/**
	 	* @brief  Método encargado de devolver el Total de Valoraciones del archivo multimedia
		* @param DTotalVectorValoraciones(E) es el Total de Valoraciones del archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto el Total de Valoraciones del archivo multimedia.
	 	*/
		unsigned int getTotalVectorValoraciones();

				/**
	 	* @brief  Método encargado de devolver la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto  la Valoracion del archivo multimedia.
	 	*/
		float getValoracionMedia();

				/**
	 	* @brief  Método encargado de devolver la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto la Valoracion del archivo multimedia.
	 	*/
		int getMeGusta();

				/**
	 	* @brief  Método encargado de devolver la ValoracionMedia del archivo multimedia
		* @param  ValoracionMedia(E) es el la Valoracion sobre el archivo multimedia
	 	* @pre .
	 	* @post Habre devuelto  la Valoracion del archivo multimedia.
	 	*/
		unsigned int getTotalVectorComentarios();
	
		/**********************************************************
		** SOBRECARGA **
		**********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase MultiMedia usando la sintaxis (cout << m). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función 				externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir la Pelicula.
		* @param m (E) Puntero (direccion de memoria que apunta) de tipo MultiMedia que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos el archivo MultiMedia correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo,  MultiMedia *m);

			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase MULTIMEDIA usando la sintaxis (cin >> M). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param M (E) Puntero de tipo MUltiMeDIA al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto MultiMedia.
	 	*/
		friend istream& operator>>(istream &flujo,  MultiMedia *M);
		/**********************************************************
		** PRINT **
		**********************************************************/
				/**
	 	* @brief Método encargado de imprimir todos los COmentarios del vector de COmentarios.
	 	* @pre .
	 	* @post 
	 	*/
		void ImprimirVectorComentarios();

				/**
	 	* @brief Método  encargado de Imprimir un Unico Comentario por la pantalla para ello usaremos la sobrecarga del cout en su interior
	 	* @param c(E) puntero (o direcc. de memoria) del objeto comentario.
	 	* @post Imprimimos en pantalla el Comentario 
	 	*/
		void ImprimirComentario(Comentario *c);

				/**
	 	* @brief Método encargado de imprimir todos las Valoraciones del vector de Valoraciones.
	 	* @pre .
	 	* @post 
	 	*/
		void ImprimirVectorValoraciones();

				/**
	 	* @brief Método  encargado de Imprimir un Unica Valoracion por la pantalla para ello usaremos la sobrecarga del cout en su interior
	 	* @param v(E) puntero (o direcc. de memoria) del objeto Valoracion.
	 	* @post Imprimimos en pantalla la Valoracion
	 	*/
		void ImprimirValoracion(Valoracion *v);

		/**********************************************************
		** METODOS COMENTARIOS **
		**********************************************************/
				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces 			incrementare +1 la dimension cada vez que utilice este metodo.  Por lo tanto aumentare de uno en uno siempre la dimension del vector de 			Comentario
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeAumComentario();

				/**
	 	* @brief Método  encargado de disminuir la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. Una de las precondiciones seria comprobar que por lo menos has 			insertado antes una vez sino no puedes realizar el eliminar.
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Disminuir Vector).
	 	*/
		void ResizeDismComentario();

				/**
	 	* @brief Método  encargado de Insertar Comentario en el vector de Comentarios
		* @param c (E) puntero que señala al objeto comentario que va a ser insertado en el vector de comentarios
	 	* @pre Debemos haber redimensionado el vector un una dimension mayor a la anterior para poder insertar el comentario.
	 	* @post Habremos insertado el comentario nuevo en el vector de comentarios y tendremos un vector con una dimension mayor.
	 	*/
		void InsertarComentario(Comentario *c);

				/**
	 	* @brief Método  encargado de Crear un Comentario en el vector de Comentarios
	 	* @pre .
	 	* @post El usuario habra introducido los datos del comentario que desea.
	 	*/
		void CrearComentario();
		
				/**
	 	* @brief Método encargado de Buscar un Comentario por el ID del comentario en el vector de Comentarios
     		* @param id(E) es el id que introduce el usuario para buscar en el vector de comentarios.
	 	* @pre Por lo menos debe de haber un comentario creado.
	 	* @post El usuario introducira el Id del comentario que desea encontrar
	 	*/
		int BuscarComentario(int id);

				/**
	 	* @brief Método  encargado de intercambiar un COmentario en el vector COmenatarios
		* @param posicion(E) es la variable que almacena la posicion del vector donde esta la direccion de memoria del puntero al objeto Comentario que el 				usuario quiere eliminar
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a eliminar en el vector. 
	 	* @pre .
	 	* @post Hbremos intercambiado la ultima posicion del vector por la posicion que el usuario indico para eliminar.
	 	*/
		void IntercambiarComentario(int posicion);

				/**
	 	* @brief Método  encargado de Eliminar un Comentario por ID en el vector de Comentarios
	 	* @pre Debe de haber algún comentario en el vector.
	 	* @post El usuario ha eliminado el comentario 
	 	*/
		void EliminarComentario(int id);

		/**********************************************************
		** METODOS VALORACION **
		**********************************************************/
				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces 			incrementare +1 la dimension cada vez que utilice este metodo.  Por lo tanto aumentare de uno en uno siempre la dimension del vector de 			Comentario
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeAumValoracion();

				/**
	 	* @brief Método  encargado de disminuir la dimension del Vector.
	 	* @pre Cuando vaya a redimensionar el vector  tengo que tener en cuenta la dimension. Una de las precondiciones seria comprobar que por lo menos has 			insertado antes una vez sino no puedes realizar el eliminar.
	 	* @post Habre Redimensionado el vector  en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeDismValoracion();

				/**
	 	* @brief Método  encargado de Insertar Comentario en el vector de Comentarios
		* @param v (E) puntero que señala al objeto Valoracion que va a ser insertado en el vector de Valoracion
	 	* @pre Debemos haber redimensionado el vector un una dimension mayor a la anterior para poder insertar el comentario.
	 	* @post Habremos insertado el comentario nuevo en el vector de comentarios y tendremos un vector con una dimension mayor.
	 	*/
		void InsertarValoracion(Valoracion *v);

				/**
	 	* @brief Método  encargado de Crear una Valoracion en el vector de Valoraciones
	 	* @pre .
	 	* @post El usuario habra introducido los datos del Valoracion que desea.
	 	*/
		void CrearValoracion();
		
				/**
	 	* @brief Método encargado de Buscar una Valoracion por el IDUsuario del Valoracion en el vector de Comentarios
     		* @param id(E) es el id que introduce el usuario para buscar en el vector de Valoraciones.
	 	* @pre Por lo menos debe de haber una valoracion creada.
	 	* @post El usuario introducira el Id de la Valoracion que desea encontrar
	 	*/
		int BuscarValoracion(string id);

				/**
	 	* @brief Método  encargado de intercambiar una Valoracion en el vector Valoraciones
		* @param posicion(E) es la variable que almacena la posicion del vector donde esta la direccion de memoria del puntero al objeto Valoracion que el 				usuario quiere eliminar
	 	* @pre .
	 	* @post Hbremos intercambiado la ultima posicion del vector por la posicion que el usuario indico para eliminar.
	 	*/
		void IntercambiarValoracion(int posicion);

				/**
	 	* @brief Método  encargado de Eliminar un Valoracion por ID en el vector de Valoraciones
	 	* @pre Debe de haber algún valoracion en el vector.
	 	* @post El usuario ha eliminado el comentario 
	 	*/
		void EliminarValoracion(string id);
};
#endif		
