#include "Lista.h"


Lista::Lista() {
	
}

void Lista::leerLista(){
	ifstream fin;
	string nombreArchivo="ListaTemas.txt";
	fin.open(nombreArchivo.c_str());
	if(fin.is_open()){
		cout<<"Archivo abierto con exito!"<<endl;
		string algo;
		while(!fin.eof()){
			getline(fin,algo);
			listaO.push_back(algo);
		}
		listaO.pop_back();
	}
}

vector<string> Lista::getLista(){
	return listaO;
}

void Lista::moveUp(Texto &text1,Texto &text2){
	text1.traducirColor("Red");
	text2.traducirColor("Verde");
}
void Lista::moveDown(Texto &text1,Texto &text2){
	text1.traducirColor("Red");
	text2.traducirColor("Verde");
}
//void Lista::moveDown(sf::Text &text){
//	text.setColor(sf::Color::Red);
//}

Lista::~Lista() {
	
}

