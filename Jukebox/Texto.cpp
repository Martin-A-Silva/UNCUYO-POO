#include "Texto.h"

Texto::Texto(string fuente, string palabra, string color, int tamano, int posX, int posY) {
	this->fuente=fuente;
	cargarFuente();
	textos.setString(palabra);
	textos.setCharacterSize(tamano);
	this->color=color;
	traducirColor(color);
	textos.setPosition(posX,posY);
}
void Texto::mover(int x, int y){
	textos.setPosition(x,y);
}
void Texto::cargarFuente(){

font.loadFromFile(fuente);
textos.setFont(font);

}
void Texto::ponerString(string palabra){
	textos.setString(palabra);
}
void Texto::draw(sf::RenderWindow &window){
	window.draw(textos);
}
void Texto::traducirColor(string color){
	switch(color[0]){
	case 'R':
		textos.setColor(sf::Color::Red);
		break;
	case 'B':
		textos.setColor(sf::Color::Black);
		break;
	case 'G':
		textos.setColor(sf::Color(128,128,128));
		break;
	case 'V':
		textos.setColor(sf::Color::Green);
	}
}
Texto::~Texto() {
	
}

