#ifndef TABLERO_H
#define TABLERO_H
#include <iostream>
#include <conio2.h>
#include <string>

using namespace std;
class Tablero {

private:
	string tablero [20][80];
public:
	void dibujarTablero();
	Tablero(){};
};

#endif

