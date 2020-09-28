#include "Grafico.h"

Grafico::Grafico() {
	
}
Grafico::Grafico(string name, int rotacion, int posX, int posY){
	textura.loadFromFile(name);
	sprite.setTexture(textura);
	sprite.setRotation(rotacion);
	sprite.setPosition(sf::Vector2f(posX, posY));
}
Grafico::Grafico(string name, int posX, int posY){
	textura.loadFromFile(name);
	sprite.setTexture(textura);
	sprite.setPosition(sf::Vector2f(posX, posY));
}
void Grafico::draw(sf::RenderWindow &window){
	window.draw(sprite);
}
void Grafico::rotar(){
	sprite.rotate(2);
}
Grafico::~Grafico() {
	
}

