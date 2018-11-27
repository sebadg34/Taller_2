#pragma once
#include <iostream>
#include "pch.h"
#include <cctype>
using namespace std;

class NodoCasilla


{
public:
	NodoCasilla();
	NodoCasilla(int fila, int columna, string valor);
	~NodoCasilla();

	//Funciones basicas para facilitar la algoritmia.
	NodoCasilla* GetLeft();
	NodoCasilla* GetUp();
	void SetLeft(NodoCasilla*Left);
	void SetUp(NodoCasilla*Up);
	void SetEstado(bool booleano);
	int GetFila();
	int GetColumna();
	string getValor();
	bool getEstado();

private:
	
	NodoCasilla *Left;
	NodoCasilla *Up;
	int Fila;
	int Columna;
	string valor;
	bool revelado;
};

