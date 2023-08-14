#include <iostream>
#include <conio2.h>
#include <ctime>
#include "Pelota.h"
using namespace std;

const int bordeSup = 1;
const int bordeIzq = 1;
const int bordeDer = 80;
const int bordeInf = 20;

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
	cout<<figura;
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

int Pelota :: getx()
{
	return x;
}
int Pelota :: gety()
{
	return y;
}
void Pelota :: setx(int posx)
{
	x = posx;
}
void Pelota :: sety(int posy)
{
	y = posy;
}

