#include "pch.h"
#include "NodoCasilla.h"
#include <iostream>
#include <cctype>
using namespace std;

NodoCasilla::NodoCasilla()
{

}
//Constructor del NodoCasilla para el tablero del buscaMinas
NodoCasilla::NodoCasilla(int fila, int columna, string valor)
{
	this->Fila = fila;
	this->Columna = columna;
	this->valor = valor;


}

NodoCasilla::~NodoCasilla()
{
}

NodoCasilla * NodoCasilla::GetLeft()
{
	return this->Left;
}

NodoCasilla * NodoCasilla::GetUp()
{
	return this->Up;
}

void NodoCasilla::SetLeft(NodoCasilla*Left)
{
	this->Left = Left;
}

void NodoCasilla::SetUp(NodoCasilla*Up)
{
	this->Up = Up;
}
