#include "Reproductor.h"

Reproductor::Reproductor() {
	Tema=new sf::Music;
}

void Reproductor::play(string titulo){
	Tema->openFromFile(titulo);
	Tema->play();
}
void Reproductor::play(){
	Tema->play();
}

void Reproductor::pausa(){
	Tema->pause();
}
void Reproductor::stop(){
	Tema->stop();
}
bool Reproductor::getStatus(){
	bool stat;
	if (Tema->getStatus() == sf::Music::Playing)
		stat =true;
	else stat=false;
	return stat;
}

Reproductor::~Reproductor() {
	
}

