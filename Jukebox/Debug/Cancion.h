#ifndef CANCION_H
#define CANCION_H

#include "Reproductor.h"

using namespace std;
class Cancion {
private:
	string nombre;
	string titulo;
	string autor;
	Reproductor reproductor;
protected:
public:
	Cancion(string);
	bool getStatus();
	void reproducir(bool);
	void setNombre(string);
	void setAutor(string);
	string getNombre();
	string getAutor();
	void pausa();
	void parar();
	~Cancion();
};

#endif

