#include "Cancion.h"
#include "Reproductor.h"

Cancion::Cancion(string titulo) {
	this->titulo=titulo;
}

void Cancion::setNombre(string nombre){
	this->nombre=nombre;
}
string Cancion::getNombre(){
	return nombre;
}
string Cancion::getAutor(){
	return autor;
}
bool Cancion::getStatus(){
	bool stat;
	stat=reproductor.getStatus();
	return stat;
}
void Cancion::setAutor(string autor){
	this->autor=autor;
}
void Cancion::reproducir(bool continuar){
	if (continuar){
		reproductor.play();
	}
	else reproductor.play(titulo);
}
void Cancion::pausa(){
	reproductor.pausa();
}
void Cancion::parar(){
	reproductor.stop();
}

Cancion::~Cancion() {
	
}

