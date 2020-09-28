#ifndef REPRODUCTOR_H
#define REPRODUCTOR_H
#include <SFML/Audio.hpp>


using namespace std;

class Reproductor {
private:
	sf::Music *Tema;
protected:
public:
	Reproductor();
	bool getStatus();
	void play(string);
	void play();
	void pausa();
	void stop();
	~Reproductor();
};

#endif

