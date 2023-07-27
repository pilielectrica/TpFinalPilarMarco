#include <iostream>
#include <conio2.h>
#include <ctime>

using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;

class Pelota{
	
protected:	
	clock_t tempo;
	clock_t paso;
	int direccionX;
	int direccionY;
	int col;
	int x,y;
	void borrar();
	virtual void dibujar();
	void mover();
	
public:
	
	Pelota(int velocidad,int color);
	virtual void start();
	void cambiarDireccion(int dx, int dy);
	char figurapelotita = 'O';
	
};

Pelota::Pelota(int velocidad, int color=WHITE){
	
	paso=CLOCKS_PER_SEC/velocidad;
	tempo=clock();
	col=color;
	direccionX = 1;
	direccionY = 1;
	x=rand()%20+1;
	y=rand()%20+1;
	
}

void Pelota::start(){
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();
		mover();
		dibujar();
		tempo=clock();
	}
}

void Pelota::borrar(){
	gotoxy(x,y);
	textcolor(7);
	cout<<' ';
	textcolor(col);
}

void Pelota::dibujar(){
	gotoxy(x,y);
	cout<<figurapelotita;
}

void Pelota::mover(){
	
	
	if (x >= bordeDer) {
		direccionX = -1;
	}
	if (x <= bordeIzq) {
		direccionX = 1;
	}
	if (y <= bordeSup) {
		direccionY = 1;
	}
	if (y >= bordeInf) {
		direccionY = -1;
	}
	x = x + (1 * direccionX);
	gotoxy(x,y);
	y = y + (1 * direccionY);    

}

class Viborita : public Pelota
{
public: 
	Viborita(int vel, int col) : Pelota (vel, col){};
	void cambiarDireccion();
	Viborita();
	void start();
	char figuraviborita = 'O';
	void dibujar();
};
void Viborita :: dibujar()
{
	gotoxy(x,y);
	cout<<figuraviborita;
}
void Viborita :: cambiarDireccion ()
{
		if (_kbhit())
		{
			int tecla = _getch();
			
			switch(tecla)
			{
			case 72: //arriba
				direccionX = 0;
				direccionY = -1;
			    break;	
			case 75: //izquierda
				direccionX = -1;
				direccionY = 0;
			    break;
			case 77: //derecha
				direccionX = 1;
				direccionY = 0;
				break;
			case 80: //abajo
			    direccionX = 0;
				direccionY = 1;
				
				
			}
		}
}
void Viborita :: start()
{
	textcolor(col);
	
	
	if(tempo+paso<clock()){
		borrar();		
		mover();
		cambiarDireccion();
		dibujar();
		tempo=clock();
	}
}
int main(int argc, char *argv[]) {
	
	Pelota *pelotita = new Pelota(30,1);
	Pelota *viborita = new Viborita(20,14);
	
	while(true){
		pelotita->start();
		viborita->start();
	}
	
	
	
	return 0;
}
