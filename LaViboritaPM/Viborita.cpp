#include "Viborita.h"
#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <ctime>
#include <deque>
#include "Pelota.h"
using namespace std;


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
			Sleep(25);//para que se mueva arriba un poco más lento y más cercano a como se mueve para izq y der.
			
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
			Sleep(25);//para que se mueva abajo un poco más lento y más cercano a como se mueve para izq y der.
			
		}
	}

}

void Viborita :: dibujar ()
{
	for (int i = 1; i < largodecola-1; i++)
	{
		gotoxy(posicionCuerpo[i][0], posicionCuerpo[i][1]);
		cout << (char)79;
	}
}
void Viborita::guardarPosicion() //guarda la posicion del cuerpo y hace crecer el cuerpo de la viborita
{
	posicionCuerpo[indiceParaMovimiento][0] = x; 
	posicionCuerpo[indiceParaMovimiento][1] = y;
	indiceParaMovimiento++;              
	if (indiceParaMovimiento == largodecola)
	{
		indiceParaMovimiento = 1; 
	}
}
bool Viborita :: chocaContraSi()
{
	for (int i = largodecola - 1; i > 0; i--)
	{
		if (direccionX == 0 && direccionY == 0){return false;}
		if (posicionCuerpo[i][0] == x && posicionCuerpo[i][1] == y)
		{
			return true;
		}
	}
	return false;
}
void Viborita :: start()
{
	textcolor(col);
	
	if(tempo+paso<clock())
	{   
		borrar();
		guardarPosicion();				
		dibujar();
		
		cambiarDireccion();
		cambiarDireccion();//duplicación del método para doblar más ágilmente
		mover();
		
		int newtempo2 = tempo;
		newtempo2 = clock();	
	}
}
