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
	void dibujar();
	void mover();
	
public:
	
	Pelota(int velocidad,int color);
	void start();
	void cambiarDireccion(int dx, int dy);
	
	
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
	cout<<'O';
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
	void cambiarDireccion(int dx, int dy);
	Viborita();
};

void Viborita :: cambiarDireccion (int dx, int dy)
{
	direccionX = dx;
	direccionY = dy;
}
Viborita :: Viborita()
{
	
}
int main(int argc, char *argv[]) {
	
	Pelota *pelotita = new Pelota(50,1);
	Viborita *viborita = new Viborita(80,14);
	
	while(true){
		pelotita->start();
		viborita->start();
	}
	
	
	
	return 0;
}
