#ifndef LISTA_H
#define LISTA_H
#include <fstream>
#include "Texto.h"
using namespace std;

class Lista {
private:
	vector<string> listaO;
protected:
public:
	Lista();
	vector<string> getLista();
	void leerLista();
	void moveUp(Texto&,Texto&);
	void moveDown(Texto&,Texto&);
	~Lista();
};

#endif

