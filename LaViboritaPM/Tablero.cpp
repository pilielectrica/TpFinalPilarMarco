#include <iostream>
#include <windows.h>
#include <conio2.h>
#include "Tablero.h"
#include <string>

using namespace std;

void Tablero :: dibujarTablero()//tablero rudimentario, porque no me daba tanto flickering que haciendolo con arrays.
{  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),{0,0});// para congelar pantalla y parar el flickering
	
textcolor(BLUE);

cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "+                                                                              +"<<endl;
cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}



