#ifndef TEXTO_H
#define TEXTO_H
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

class Texto {
private:
	string fuente;
	string palabra;
	string color;
	sf::Font font;
	sf::Text textos;
protected:
public:
	Texto(string,string,string,int,int,int);
	void cargarFuente();
	void mover(int,int);
	void draw(sf::RenderWindow&);
	void traducirColor(string);
	void ponerString(string);
	~Texto();
};

#endif

