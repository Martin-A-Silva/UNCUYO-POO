#include "Cancion.h"
#include "Lista.h"
#include "Grafico.h"
#include "Texto.h"
#include "Windows.h"
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> ventana(Lista &menu){
	srand(time(NULL));
	sf::RenderWindow ventanaLista(sf::VideoMode(800,670), "Lista",sf::Style::Titlebar); // Creo una ventana
	ventanaLista.setVerticalSyncEnabled(true); //Actualizacion en conjunto con el monitor
	vector<string> cancion=menu.getLista();
	vector<string> list;
	
	Grafico *aceptar;
	aceptar= new Grafico("boton.png",650,620);
	Grafico *azar;
	azar= new Grafico("boton.png",500,620);
	//Boton aleatorio//
	Texto aleatorio("arial.ttf","Aleatorio","Black",17,542,629);
	//Boton aceptar//
	Texto taceptar("arial.ttf","Aceptar","Gris",17,692,629);
	
	Texto instruccion("sevenseg.ttf","Seleccione con flecha derecha o boton aleatorio","Gris",20,200,0);
	//texto lista original//
	vector<Texto*> lstO;
	for(int i=0;i<cancion.size();i++){
		Texto *text;
		text=new Texto("sevenseg.ttf",cancion[i],"Verde",20,0,20*i+20);
		lstO.push_back(text);	
	}
	int k=0;
	//texto lista modificada//
	lstO[k]->traducirColor("Red");
	vector<Texto*> lstM;
	for(int i=0;i<cancion.size();i++){
		Texto *text1;
		text1=new Texto("sevenseg.ttf","","Verde",20,400,20*i+20);
		lstM.push_back(text1);	
	}
	int t=0;
	int aux=0;
	bool ficha=false;
	while (ventanaLista.isOpen())
		{
		if (t==30) taceptar.traducirColor("Black");
		else taceptar.traducirColor("Gris");
		if (t>29||t<1&&ficha==false) aleatorio.traducirColor("Black");
		else aleatorio.traducirColor("Gris");
			sf::Event event;
			while (ventanaLista.pollEvent(event))
			{
				if (event.type == sf::Event::KeyReleased){
					switch (event.key.code){
					case sf::Keyboard::Up:
						if (k>=1){
							k--;
						menu.moveUp(*lstO[k],*lstO[k+1]);
						}
						cout<<k<<";"<<t<<endl;
						break;
					case sf::Keyboard::Down:
						if (k<cancion.size()-1){
							k++;
							menu.moveDown(*lstO[k],*lstO[k-1]);
						}
						cout<<k<<";"<<t<<endl;
						break;
					case sf::Keyboard::Right:
						if (t<cancion.size()){
							if(cancion[k]!="EN LISTA"){
								list.push_back(cancion[k]);
								lstM[t]->ponerString(list[t]);
								t++;
								aux=k;
								ficha=true;
							}
							
							cancion[k].assign("EN LISTA");
						lstO[k]->ponerString(cancion[k]);
						}
						break;
					case sf::Keyboard::Left:
						if (ficha){
								cancion[aux].assign(list[t-1]);
								list.pop_back();
								t--;
								lstO[aux]->ponerString(cancion[aux]);
								ficha=false;
							}

						break;
					}
				}

					if (event.type == sf::Event::MouseButtonPressed){
					
					switch (event.key.code)
					{
					case sf::Mouse::Left:
						if(t==30){
						if(sf::Mouse::getPosition(ventanaLista).x>650&&
						sf::Mouse::getPosition(ventanaLista).x<793&&
						sf::Mouse::getPosition(ventanaLista).y>620&&
						sf::Mouse::getPosition(ventanaLista).y<658){
					ventanaLista.close();
						}
						}
						if(t==0||t==30&&ficha==false){
						   if(sf::Mouse::getPosition(ventanaLista).x>500&&
							sf::Mouse::getPosition(ventanaLista).x<643&&
							sf::Mouse::getPosition(ventanaLista).y>620&&
							sf::Mouse::getPosition(ventanaLista).y<658){
							if(t==30){
							   for(int i=0;i<cancion.size();i++){
							   list.pop_back();
							}
							}
							for(int i=0;i<cancion.size();i++){
								cancion[i].swap(cancion[rand()%30]);
							}
							for (int i=0;i<cancion.size();i++){
								list.push_back(cancion[i]);
								lstM[i]->ponerString(cancion[i]);
							}
							t=30;
						}
						}
						break;
				}
				}
			}

			ventanaLista.clear();
			instruccion.draw(ventanaLista);
			for(int i=0;i<list.size();i++){
			lstM[i]->draw(ventanaLista);
			}
			for(int i=0;i<cancion.size();i++){
			lstO[i]->draw(ventanaLista);
			}
			aceptar->draw(ventanaLista);
			azar->draw(ventanaLista);
			aleatorio.draw(ventanaLista);
			taceptar.draw(ventanaLista);
			ventanaLista.display();
		}
	return list;
}

int main () {
	vector<Cancion> canciones;
	vector<string> listadecanciones;
	Lista lista;
	lista.leerLista(); //llamado a la funcion para leer archivo
	vector<Grafico*> graph;
	listadecanciones=ventana(lista);
	for (int j=0;j<listadecanciones.size();j++){
		Cancion tema(listadecanciones[j]);
		canciones.push_back(tema);
	}
	string tok;
	char delim='-';
	bool marcador=true;
	for (int j=0;j<listadecanciones.size();j++){
		istringstream ss(listadecanciones[j]);
		while(getline(ss,tok,delim)){
			if(marcador) 
			{
				canciones[j].setAutor(tok);
				marcador=false;
			}
			else{
				canciones[j].setNombre(tok);
				marcador=true;
			}
		}
	}
	for (int j=0;j<canciones.size();j++){
		cout<<canciones[j].getAutor()<<"-"<<canciones[j].getNombre()<<endl;
	}
	
	ofstream fout("ListaTemas.txt");
		for (int i=0;i<listadecanciones.size();i++){
			fout<<listadecanciones[i]<<endl;
		}
	//Rockola//
	sf::RenderWindow window(sf::VideoMode(500,570), "Jukebox",sf::Style::Titlebar | sf::Style::Close); // Creo una ventana
	window.setVerticalSyncEnabled(true); //Actualizacion en conjunto con el monitor
	
	Grafico *jukebox;
	jukebox= new Grafico("jukebox.png",0,0);
	bool play=false;
	//Disco//
	for(int i=0;i<4;i++){
	int r=i*90;
	Grafico *disco;
	disco = new Grafico("disco.png",r,249,162);
	graph.push_back(disco);
	}
	//Banner
	sf::RectangleShape rectangle(sf::Vector2f(500, 70));
	
	rectangle.setFillColor(sf::Color::Transparent);
	
	rectangle.setOutlineColor(sf::Color::Red);
	
	rectangle.setOutlineThickness(-10);
	
	rectangle.setPosition(0,500);
	
	Texto banner("sevenseg.ttf","","Verde",45,0,500);
	
	//Botones
	Grafico *playP;
	playP=new Grafico("play.gif",243,371);
	
	Grafico *pause;
	pause=new Grafico("pause.gif",243,371);
	
	Grafico *stop;
	stop=new Grafico("stop.gif",243,421);

	Grafico *siguiente;
	siguiente=new Grafico("siguiente.gif",301,343);
	
	Grafico *anterior;
	anterior=new Grafico("anterior.gif",183,343);
	bool status;
	bool algo=false;
	bool pauseB=false;
	int i=0; //Indice de tema;
	int x=0;
	bool continuar=false;
	//Main Loop
	while (window.isOpen())
	{
		
		if (play){
		status=canciones[i].getStatus();
		if(!status) {
			i++;
			if (i==30) i=0;
			continuar=false;
			canciones[i].reproducir(continuar);
			banner.ponerString(listadecanciones[i]);
		}
		for(int j=0;j<4;j++){
			graph[j]->rotar();
		}
			if (x>500) x=-720;
			x+=2;
			banner.mover(x,500);
			//banner.traducirColor("Verde");
		}
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if(event.type == sf::Event::KeyReleased){
			
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
//				if(sf::Mouse::getPosition(window).x>243&&
//					sf::Mouse::getPosition(window).x<258&&
//					sf::Mouse::getPosition(window).y>371&&
//					sf::Mouse::getPosition(window).y<386){
					system("cls");
					if (play==false){
						canciones[i].reproducir(continuar);
						banner.ponerString(listadecanciones[i]);
						play=true;
						pauseB=true;
					}
					else{
						play=false;
						pauseB=false;
						canciones[i].pausa();
						continuar=true;
					}
					std::cout<<"PLAY"<<endl; 
			//}
			break;
			case sf::Keyboard::Down:
//				if(sf::Mouse::getPosition(window).x>243&&
//					sf::Mouse::getPosition(window).x<258&&
//					sf::Mouse::getPosition(window).y>421&&
//					sf::Mouse::getPosition(window).y<436){
					system("cls");
					if (play==true){
						canciones[i].parar();
						play=false;
						pauseB=false;
						continuar=false;
					}
					std::cout<<"STOP"<<endl; 
			break;
case sf::Keyboard::Right:
//				if(sf::Mouse::getPosition(window).x>301&&
//					sf::Mouse::getPosition(window).x<316&&
//					sf::Mouse::getPosition(window).y>343&&
//					sf::Mouse::getPosition(window).y<358){
					system("cls");
					std::cout<<"SIGUIENTE"<<endl; //reemplazar por funcion SIGUIENTE tema
					if (i<30){
					canciones[i].parar();
					i++;
					if (i==30) i=0;
					continuar=false;
					canciones[i].reproducir(continuar);
					banner.ponerString(listadecanciones[i]);
					play=true;
					}
					//}
				break;
case sf::Keyboard::Left:
//				if(sf::Mouse::getPosition(window).x>183&&
//					sf::Mouse::getPosition(window).x<198&&
//					sf::Mouse::getPosition(window).y>343&&
//					sf::Mouse::getPosition(window).y<358){
					system("cls");
					std::cout<<"ANTERIOR"<<endl; //reemplazar por funcion ANTERIOR tema
					if(i>=0){
					canciones[i].parar();
					i--;
					if (i==-1) i=29;
					continuar=false;
					canciones[i].reproducir(continuar);
					banner.ponerString(listadecanciones[i]);
					play=true;
					}
					
				//}
			
			break;
			
			}
		}
		}
		//std::cout << sf::Mouse::getPosition(window).x << ";";
		//std::cout << sf::Mouse::getPosition(window).y << std::endl;
		
		window.clear();

		jukebox->draw(window);
		stop->draw(window);

		playP->draw(window);
		if (pauseB) pause->draw(window);
		siguiente->draw(window);
		anterior->draw(window);
		for(int i=0;i<4;i++){
			graph[i]->draw(window);
		}
		
		if (play) banner.draw(window);
		else{
			if (algo){
				banner.draw(window);
				algo=false;
			}
			else algo=true;
			Sleep(200);
		}

		window.draw(rectangle);
		
		window.display();
	}
	return 0;
}
