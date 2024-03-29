all: cristofinity

cristofinity:  newMain.o COMENTARIO.o MULTIMEDIA.o VALORACION.o CANCION.o PELICULA.o VIDEOJUEGO.o SERIE.o CRISTOFINITY.o USUARIO.o USUARIONORMAL.o ADMIN.o
	g++ -o cristofinity newMain.o COMENTARIO.o MULTIMEDIA.o VALORACION.o CANCION.o PELICULA.o VIDEOJUEGO.o SERIE.o CRISTOFINITY.o USUARIO.o USUARIONORMAL.o ADMIN.o

newMain.o: newMain.cpp
	g++ -c newMain.cpp

MULTIMEDIA.o: MULTIMEDIA.cpp
	g++ -c MULTIMEDIA.cpp

COMENTARIO.o: COMENTARIO.cpp
	g++ -c COMENTARIO.cpp

VALORACION.o: VALORACION.cpp
	g++ -c VALORACION.cpp

CANCION.o: CANCION.cpp
	g++ -c CANCION.cpp

PELICULA.o: PELICULA.cpp
	g++ -c PELICULA.cpp

VIDEOJUEGO.o: VIDEOJUEGO.cpp
	g++ -c VIDEOJUEGO.cpp

SERIE.o: SERIE.cpp
	g++ -c SERIE.cpp

CRISTOFINITY.o: CRISTOFINITY.cpp
	g++ -c CRISTOFINITY.cpp

USUARIO.o: USUARIO.cpp
	g++ -c USUARIO.cpp

USUARIONORMAL.o: USUARIONORMAL.cpp
	g++ -c USUARIONORMAL.cpp

ADMIN.o: ADMIN.cpp
	g++ -c ADMIN.cpp

clean:
	rm -f cristofinity *.o
