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
		NodoCasilla Nodo =  NodoCasilla(i, 0, "");
		Nodo.SetLeft(&Nodo);
		Filas[i] = Nodo;
	}

	//Ciclo para Columnas
	for (int i = 1; i < columnas; i++) {
		NodoCasilla Nodo = NodoCasilla(0, i, "");
		Nodo.SetUp(&Nodo);
		Columnas[i] = Nodo;
	}


}


Tablero_Matriz::~Tablero_Matriz()
{
}

void Tablero_Matriz::AgregarNodo(NodoCasilla* Nodo, int posX, int posY)
{
	/**
	
	//verifica las posiciones si son realistas
	NodoCasilla* Aux = &Filas[posY];
	int cont = 0;
	while (Aux->GetLeft()->GetColumna() > posX)
	{
		if (Aux->GetLeft()->GetColumna() == posX) {  //comprueba si el lugar esta ocupado
			cout << "Ya existe un nodo en esta posicion" << endl;
			int cont = 1;
		}
		else {
			Aux = Aux->GetLeft();
		}
	}
	if (cont == 0) {
		Nodo->SetLeft(Aux->GetLeft());
		Aux->SetLeft(Nodo);
		NodoCasilla* Aux2 = &Columnas[posX];

		while (Aux2->GetUp()->GetFila() > posY)
		{
			Aux2 = Aux2->GetUp();
		}
		Nodo->SetUp(Aux2->GetUp());
		Aux2->SetUp(Nodo);

	}
	**/
} 



NodoCasilla* Tablero_Matriz::BuscarNodo(int x, int y)
{
	return nullptr;
}
