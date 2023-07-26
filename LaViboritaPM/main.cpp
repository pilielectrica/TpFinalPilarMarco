#include <iostream>
#include <conio2.h>
#include <ctime>

using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;

class Pelota{
	
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
	if (_kbhit())
	{
	int tecla = getch();
	while (x <= bordeDer && x >= bordeIzq && y >= bordeSup && y <= bordeInf)
	{
	if (tecla == 72 ) { //arriba
		direccionX = 0;
		direccionY = 1;
	}
	
	if (tecla == 80) { //abajo
		direccionX = 0;
		direccionY = -1;
	}
	if ( tecla == 75) { //izquierda
		direccionX = -1;
		direccionY = 0;		
	}
	if ( tecla == 77) {//derecha
		direccionX = 1;
		direccionY = 0;
	}
	x = x + (1 * direccionX);
	y = y + (1 * direccionY);
    }
}
}






int main(int argc, char *argv[]) {
	
	Pelota *p1 = new Pelota(50,1);
	Pelota *p2 = new Pelota(80,14);
	
	while(true){
		p1->start();
		p2->start();
	}
	
	
	
	return 0;
}
