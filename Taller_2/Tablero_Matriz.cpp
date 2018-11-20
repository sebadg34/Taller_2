#include "pch.h"
#include "Tablero_Matriz.h"


Tablero_Matriz::Tablero_Matriz()
{
}

Tablero_Matriz::Tablero_Matriz(int filas, int columnas)
{
	//se crean las listas fila y columna
	this->Columnas = new NodoCasilla[columnas + 1];
	this->Filas = new NodoCasilla[filas + 1];

	//------------------------------------------------------
	//Ciclos para llenar las filas y columnas de nodos Base|
	//------------------------------------------------------

	//Ciclo para Filas
	for (int i = 1; i < filas; i++) {
		NodoCasilla Nodo =  NodoCasilla(i, 0, 0);
		Nodo.SetLeft(&Nodo);
		Filas[i] = Nodo;
	}

	//Ciclo para Columnas
	for (int i = 1; i < columnas; i++) {
		NodoCasilla Nodo = NodoCasilla(0, i, 0);
		Nodo.SetUp(&Nodo);
		Columnas[i] = Nodo;
	}


}


Tablero_Matriz::~Tablero_Matriz()
{
}
