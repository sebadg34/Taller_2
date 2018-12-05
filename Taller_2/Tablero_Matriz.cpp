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
	for (int i = 1; i < filas+1; i++) { //1 -> 9
		NodoCasilla*Nodo = new NodoCasilla(i, 0, "");
		Nodo->SetLeft(Nodo);
		Filas[i] = *Nodo;
		
	}

	//Ciclo para Columnas
	for (int i = 1; i < columnas +1; i++) { //1->9
		NodoCasilla*Nodo = new NodoCasilla(0, i, "");
		Nodo->SetUp(Nodo);
		Columnas[i] = *Nodo;
		
	}


}


Tablero_Matriz::~Tablero_Matriz()
{
}

void Tablero_Matriz::AgregarNodo(NodoCasilla* Nodo, int fila, int columna)
{
	//verifica las posiciones si son realistas
	NodoCasilla* Aux = &Filas[fila];
	int cont = 0;
	while (Aux->GetLeft()->GetColumna() > columna)
	{
		if (Aux->GetLeft()->GetColumna() == columna) {  //comprueba si el lugar esta ocupado
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
		NodoCasilla* Aux2 = &Columnas[columna];

		while (Aux2->GetUp()->GetFila() > fila)
		{
			Aux2 = Aux2->GetUp();
		}
		Nodo->SetUp(Aux2->GetUp());
		Aux2->SetUp(Nodo);

	}
}



NodoCasilla* Tablero_Matriz::BuscarNodo(int fila, int columna)
{
	NodoCasilla* aux = &Filas[fila];


	//Ciclo que avanza hasta verificar que se llege denuevo a los nodos base.
	while (aux->GetLeft()->GetColumna() != 0) {


		if (aux->GetLeft()->GetColumna() == columna) {

			return aux->GetLeft();

		}
		else {//Si no es el mismo en el valor de columna, se setea para el Left siguiente, y el ciclo sigue.
			aux = aux->GetLeft();
		}
	}
	return nullptr;
}

void Tablero_Matriz::EliminarNodo(int fila, int columna)
{
	NodoCasilla* Aux = &Filas[fila];

	while (Aux->GetLeft()->GetColumna() > columna) //Avanza hacia la posicion desde fila
	{
		Aux = Aux->GetLeft();

	}

	NodoCasilla* Eliminar = Aux->GetLeft(); //Se guarda el nodo a eliminar

	Aux->SetLeft(Aux->GetLeft()->GetLeft());

	Aux = &Columnas[columna];

	while (Aux->GetUp()->GetFila() > fila) //Avanza hacia la posicion desde columnas
	{
		Aux = Aux->GetUp();
	}
	Aux->SetUp(Aux->GetUp()->GetUp());
	delete(Eliminar);
}