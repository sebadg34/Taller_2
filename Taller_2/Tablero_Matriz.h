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
	void EliminarNodo(int posX, int posY);
	void AgregarNodo(NodoCasilla*Nodo,int posX,int posY);
	NodoCasilla* BuscarNodo(int x, int y);

	NodoCasilla*Filas;
	NodoCasilla*Columnas;
};

