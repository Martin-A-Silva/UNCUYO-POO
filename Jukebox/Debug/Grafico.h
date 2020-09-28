#ifndef GRAFICO_H
#define GRAFICO_H
#include<SFML/Graphics.hpp>

using namespace std;

class Grafico {
private:
	sf::Texture textura;
	sf::Sprite sprite;
protected:
public:
	Grafico();
	Grafico(string,int,int,int);
	Grafico(string,int,int);
	void draw(sf::RenderWindow&);
	void rotar();
	~Grafico();
};

#endif

