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
//	x = x + (1 * direccionX);
////	gotoxy(x,y);
////	y = y + (1 * direccionY);
}

void Viborita :: dibujar ()
{
	for (int i = 1; i < largodecola-1; i++)
	{
		gotoxy(posicionCuerpo[i][0], posicionCuerpo[i][1]);
		cout << "O";
	}
}
void Viborita::guardarPosicion() // funcion que guarda la posicion de la serpiente en la matriz
{
	posicionCuerpo[indiceParaMovimiento][0] = x; // guardamos la posicion posicionX en la matriz
	posicionCuerpo[indiceParaMovimiento][1] = y; // guardamos la posicion posicionY en la matriz
	indiceParaMovimiento++;              // incrementamos el numero de partes del cuerpo de la serpiente
	if (indiceParaMovimiento == largodecola) // si el numero de partes del cuerpo es igual al tamaño de la serpiente
	{
		indiceParaMovimiento = 1; // reiniciamos el numero de partes del cuerpo de la serpiente
	}
}
bool Viborita :: chocaContraSi()
{
	for (int i = largodecola - 1; i > 0; i--)
	{
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
		mover();
		int newtempo2 = tempo;
		newtempo2 = clock();	
	}
}
