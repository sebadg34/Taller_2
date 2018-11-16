#pragma once
#include "NodoCasilla.h"
#include <iostream>
#include "pch.h"

class Tablero_Matriz
{
public:
	Tablero_Matriz();
	Tablero_Matriz(int filas, int columnas);
	~Tablero_Matriz();


	NodoCasilla*Filas;
	NodoCasilla*Columnas;
};

