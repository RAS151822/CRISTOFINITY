/* 
 * File:   Fynal Practice
 * Author: RAS
 *
 * Modificated on 12 de junio de 2019, 21:07
 * Muy importante la lectura:
 * http://c.conclase.net/curso/index.php?cap=037#inicio
 *  
 */
#ifndef USUARIONORMAL_h
#define USUARIONORMAL_h
#include "MULTIMEDIA.h"
#include "USUARIO.h"
#include <iostream>
#include <string.h>

using namespace std;

class UsuarioNormal : public Usuario{
	
	protected:
		MultiMedia** Favoritos;
		unsigned int TotalFavoritos;
		float ValoracionMediaListaMultiMedia;

	public:
		/**********************************************************
		** CONSTRUCTORES Y DESTRUCTOR **
		**********************************************************/

			/**
		* @brief Método constructor por defecto es el encargado de dar memoria al objeto Usuario Normal.
		* @pre 
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo Media
		*/
		UsuarioNormal();

			/**
		* @brief Método constructor por parametros es el encargado de dar memoria al objeto Usuario y pasar por parametros los valores para asignarselos al 				objeto Usuario.
		* @param TotalListaMedia (E) es la variable que almacena el total de los medias que contiene el Usuario Normal
		* @param ValoracionMediaListaMultiMedia (E) almacena el resultado de la media de las valoraciones hechas por el usuario.
		* @post Definimos los valores de los atributos  y reservamos la memoria para el vector de tipo MultiMedia
		*/
		UsuarioNormal(string Login, string Nombre, string Apellidos, string URLFotoPerfil, unsigned int TotalFavoritos);
				/**
	 	* @brief Método encargado de eliminar el objeto de tipo Usuario.
	 	* @pre .
	 	* @post 
	 	*/
		~UsuarioNormal();

		/**********************************************************
		** SETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de TotalListaMedia.
		* @param TotalListaMedia (E) es la variable que almacena el total de los archivos  Multimedia que contiene el Usuario Normal
	 	* @pre .
	 	* @post Habre introducido el TotalListaMedia  del usuario.
	 	*/
		void setTotalFavoritos(unsigned int TotalFavoritos);

				/**
	 	* @brief  Método encargado de insertar el valor de nombre.
		* @param nombre(E) es la vira
	 	* @pre .
	 	* @post Habre introducido el nombre del usuario.
	 	*/
		void setValoracionMediaListaMultiMedia(float ValoracionMediaListaMultiMedia);
		
		/**********************************************************
		** GETS **
		**********************************************************/
				/**
	 	* @brief  Método encargado de insertar el valor de TotalListaMedia.
		* @param TotalListaMedia (S) es la variable que almacena el total de los medias que contiene el Usuario Normal
	 	* @pre .
	 	* @post Habre devuelto el TotalListaMedia  del usuario normal.
	 	*/
		unsigned int  getTotalFavoritos();

				/**
	 	* @brief  Método encargado de insertar el valor de nombre.
		* @param ValoracionMediaListaMultiMedia(S) es la variable que almacena la media de valoraciones sobre los archivos Multimedia.
	 	* @pre .
	 	* @post Habre devuelto el resultado la ValoracionMediaListaMultiMedia del resultado normal.
	 	*/
		float getValoracionMediaListaMultiMedia();

		/**********************************************************
		 ** SOBRECARGAS**
		 **********************************************************/
			/**
	 	* @brief Método encargado de sobrecargar el operador << para mostrar un objeto de clase Usuario Normal usando la sintaxis (cout << u). Puesto 			que no 	podemos añadir un método a la clase ostream ya que romperiamos el encapsulamiento sobrecargamos este operador con una función externa.
		* @param flujo (E) también conocido como la sintaxis cout. Sentencia que pasamos como referencia para imprimir el Usuario.
		* @param u (E) Puntero de tipo Usuario Administrador que vamos a mostrar por pantalla.
	 	* @pre .
	 	* @post Imprimiremos el Usuario correspondiente a la direccion de memoria asignada.
	 	*/
		friend ostream& operator<<(ostream &flujo,  UsuarioNormal *u);
		
			/**
	 	* @brief Módulo de proceso encargado de sobrecargar el operador >> para escribir un objeto de clase Usuario Normal usando la sintaxis (cin >> u). 
		* @param flujo (E) también conocido como la sintaxis cin. Sentencia que pasamos como referencia para que el usuario introduzca sus datos.
		* @param u (E) Puntero de tipo Usuario Administrador al que introduciremos los datos.
	 	* @pre .
	 	* @post Podremos escribir los datos del objeto Usuario.
	 	*/
		friend istream& operator>>(istream &flujo,  UsuarioNormal *u);

		/**********************************************************
		 ** METODOS**
		 **********************************************************/
		/**********************************************************
		** INSERTAR FAVORITOS **
		**********************************************************/
				/**
	 	* @brief Método  encargado de aumentar la dimension del Vector de Favoritos.
	 	* @pre Cuando vaya a redimensionar el vector de Favoritos tengo que tener en cuenta la dimension. En mi caso esta inicializada a 0 entonces sumare uno 				cada vez que utilice este metodo. De momento no voy a tener problmeas (creo) porque insertare de uno en uno los usuarios y cada vez que 			inserte llamare al resize. Por lo tanto aumentare de uno en uno siempre la dimension del vector de Usuarios
	 	* @post Habre Redimensionado el vector de Favoritos en uno su dimension(Resize para Aumentar Vector).
	 	*/
		void ResizeFavoritoAum();
				/**
	 	* @brief Método  encargado de Insertar archivos MultiMedia en el vector de Favoritos
		*@param m (E) ES el puntero de tipo MultiMedia que vamos a guardar en el vector de Favoritos
	 	* @pre Debo haber redimensionado antes la dimension del vector.
	 	* @post Habre aumentado la dimension del vector en +1 y a continuacion habre introducido un archivo multimedia del catalogo en el vector de favoritos
	 	*/
		void InsertarFavoritos2(MultiMedia *m);

		/**********************************************************
		** IMPRIMIR FAVORITOS**
		**********************************************************/
				/**
	 	* @brief Método  encargado de Imprimir un Unico MultiMedia por pantalla diferenciando asi las diferentes clases con sus distintos atributos
	 	* @pre .
	 	* @post Imprimimos en pantalla un unico objeto MultiMedia 
	 	*/
		void ImprimirFavoritos(MultiMedia *m);

				/**
	 	* @brief Método encargado de mostrar por pantalla todos los medias del USUARIO
	 	* @pre Debe haber por lo menos un archivo multimedia en el catalogo.
	 	* @post Mostrare por pantalla los diferentes archivos Multimedia de su vector de favoritos con sus respectivos items
	 	*/
		void MostrarFavoritos();

		/**********************************************************
		** ELIMINAR MULTIMEDIA FAVORITOS**
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
		int BuscarMultiMediaFavoritosID(int id);

				/**
	 	* @brief Método encargado de Buscar un archivo MultiMedia por el titulo del archivo Multimedia en el vector de archivos MultiMedia
     		* @param Titulo(E) es el Titulo que introduce el usuario para buscar en el vector MultiMedia
		* @param posicion (S) es la variable que almacena la posicion donde se encuentra el puntero a eliminar en el vector.
	 	* @pre Por lo menos debe de haber un archivo MultiMedia creado.
	 	* @post El usuario introducira el Id del MultiMedia que desea encontrar
	 	*/
		int BuscarMultiMediaFavoritosTitulo(string Titulo);

				/**
	 	* @brief Método  encargado de intercambiar un archivo MultiMedia en el vector MultiMedia
		* @param posicion(E) es la variable que almacena la posicion del vector donde esta la direccion de memoria del puntero al objeto MultiMedia que el 				usuario quiere eliminar
	 	* @pre .
	 	* @post Hbremos intercambiado la ultima posicion del vector por la posicion que el usuario indico para eliminar.
	 	*/
		void IntercambiarMultiMedia(int posicion);

				/**
	 	* @brief Método  encargado de Eliminar un archivo MultiMedia por ID en el vector MultiMedia
	 	* @pre Debe de haber algún comentario en el vector.
	 	* @post El usuario habra eliminado el archivo MultiMedia
	 	*/
		void EliminarMultiMedia();

		void EliminarMultimediaFavoritos(string Titulo);

		bool buscarTituloVectorFavoritos(string Titulo);	
};
#endif		
