
#include "pch.h"
#include "GameSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include "Tablero_Matriz.h"



using namespace std;



GameSystem::GameSystem()
{
	Facil = new string[10];
	Medio = new string[10];
	Dificil = new string[10];
	
	static int contFacil = 0;
	static int contMedio = 0;
	static int contDificil = 0;

	static int dif = 0;//Variable auxiliar que determina la dificultad del juego en curso.
	LecturaDificultades();
	MenuPrincipal();
}


GameSystem::~GameSystem()
{
}

void GameSystem::MenuPrincipal()
{

	
	cout << "***********************************" << endl;
	cout << "FunGame-indieGames presenta....." << endl;
	cout << "***********************************" << endl;
	PlaySound(TEXT("intro.wav"), NULL, SND_SYNC);
	Sleep(1000);//Añade un retraso de 1 segundo antes de que la ejecucion continue.















	//Texto Ascii
	cout <<"****______******************************______***_**************************" << endl;
	cout << "***(____  \\***************************|  ___ \\ (_)**************************" << endl;
	cout << "****____)  )*_***_***___***____**____*| | _ | |*_**____****____***___*******" << endl;
	cout << "***|  __  ( | | | | /___) / ___)/ _  || || || || ||  _ \\  / _  | /___)******" << endl;
	cout << "***| |__)  )| |_| ||___ |( (___( ( | || || || || || | | |( ( | ||___ |******" << endl;
	cout << "***|______/**\\____|(___/**\\____)\\_||_||_||_||_||_||_| |_|*\\_||_|(___/*******" << endl;
	cout << "****************************************************************************" << endl;
		
			

	
	PlaySound(TEXT("intro.wav"), NULL, SND_SYNC);
	
	Sleep(1000);//Añade un retraso de 1 segundo antes de que la ejecucion continue.

	PlaySound(TEXT("intro.wav"), NULL, SND_SYNC);


	//Arreglos para almacenar ids de los tableros respectivos
	

	bool menu = true;
	string opcion; //Auxiliar para menu
	string pause;
	
	while (menu) {
		cout << "*************************************************************************************" << endl;
		cout << "Selecione una opcion" << endl;
		cout << "Menu principal:" << endl;
		cout << "*************************************************************************************" << endl;
		cout << "[1] Iniciar Partida" << endl;
		cout << "[2] Estadisticas del Jugador" << endl;
		cout << "[3] Salir" << endl;
		getline(cin, opcion);
		try { //Validar respuesta del menu
			std::stoi(opcion);
		}
		catch (const std::exception) {
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
			cout << "Porfavor escriba una opcion valida ([1],[2],etc)" << endl;
			cout << "*************************************************************************************" << endl;
			
			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {

		case 1:
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			MenuPartida();
			break;


		case 2:
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			MenuEstadisticas();
			break;


		case 3:
			PlaySound(TEXT("return.wav"), NULL, SND_ASYNC);
			cout << "Gracias por usar el programa" << endl;
			menu = false;
			getline(cin, pause);
			break;

		}
	}

}

void GameSystem::MenuPartida()
{
	system("CLS");//Limpiar consola
	string opcion; //Auxiliar para menu
	string pause;
	bool menu = true;

	while (menu) {
		
		cout << "*************************************************************************************" << endl;
		cout << "Selecione una dificultada para su juego:" << endl;
		cout << "*************************************************************************************" << endl;
		cout << "[1] Dificultad Facil"<< endl;
		cout << "[2] Dificultad Medio"<< endl;
		cout << "[3] Dificultad Dificil"<< endl;
		cout << "[4] Volver al Menu Principal" << endl;

		getline(cin, opcion);
		try { //Validar respuesta del menu
			std::stoi(opcion);
		}
		catch (const std::exception) {
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
			cout << "Porfavor escriba una opcion valida ([1],[2],etc)" << endl;
			cout << "*************************************************************************************" << endl;

			continue;
		}
		int opcionVerificada = std::stoi(opcion);
		
		switch (opcionVerificada) {
		
		case 1:
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			dif = 1;
			SelectorPartida(1);
			break;
		case 2:
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			dif = 2;
			SelectorPartida(2);
			break;
		case 3:
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			dif = 3;
			SelectorPartida(3);
			break;

		case 4://Vuelvo al menu Principal
			PlaySound(TEXT("return.wav"), NULL, SND_ASYNC);
			system("CLS");//Limpiar consola
			menu = false;
			break;
			

		}

		
	}


	

}

void GameSystem::MenuEstadisticas()
{
	system("CLS");//Limpiar consola

}

void GameSystem::LecturaDificultades()
{
	std::ifstream archivoCampos;
	archivoCampos.open("Campos.txt", ifstream::in);
	string id;
	string dificultad;
	string linea;

	if (archivoCampos.is_open()) {

		

		while (getline(archivoCampos, linea)) {
			


			stringstream ss(linea);
			getline(ss, id, ',');
			getline(ss, dificultad, ',');

			if (dificultad == "facil") {
				Facil[contFacil] = id;
				contFacil++;
			}
			else if (dificultad == "medio") {
				Medio[contMedio] = id;
				contMedio++;
			}
			else if (dificultad == "dificil") {
				Dificil[contDificil] = id;
				contDificil++;
			}


			//cout << id << "," << dificultad << endl; //funcion de prueba (BORRAR)

			

		}

	}
}

void GameSystem::DesplegarTablero(Tablero_Matriz tablero,Tablero_Matriz tablero2)
{
	int columnas = 0;
	int filas = 0;
	string linea = "";
	if (dif == 1) {
		columnas = 9;
		filas = 9;
		linea = "    C01 C02 C03 C04 C05 C06 C07 C08 C09";
	}
	else if (dif == 2) {
		columnas = 16;
		filas = 16;
		linea = "    C01 C02 C03 C04 C05 C06 C07 C08 C09 C10 C11 C12 C13 C14 C15 C16";
	}
	else if (dif == 3) {
		columnas = 30;
		filas = 16;
		linea = "    C01 C02 C03 C04 C05 C06 C07 C08 C09 C10 C11 C12 C13 C14 C15 C16 C17 C18 C19 C20 C21 C22 C23 C24 C25 C26 C27 C28 C29 C30";
	}
	cout <<linea<< endl;

	for (int x = 1; x < filas + 1; x++) {

		//condicion para que las filas sean de doble digito y permita una impresion ordenada en consola
		if (x <= 9) {
			cout << "F0" + to_string(x) << " ";
		}
		else {
			cout << "F" + to_string(x) << " ";
		}
		
		for (int y = 1; y < columnas + 1; y++) {

			NodoCasilla* nodoBuscado = tablero2.BuscarNodo(x, y);
			
			
			if (nodoBuscado == nullptr) { 
				cout << " H  "; 
				
			}
			else { 
				//if (nodoBuscado->getEstado() == true) { // si el nodo ya fue revelado, se desplega su valor por consola.

					cout << " "<< nodoBuscado->getValor() << "  ";
					
				//}
				
			}
		}
		cout << endl;
	}


	cout << "\n" << endl;
}

void GameSystem::SelectorPartida(int dificultad)

{
	
	/**
	Dependiendo de la dificultad, se genera un numero random para seleccionar un campo de forma aleatoria entre las dificultades.
	1 = facil, 2 = medio, 3 = dificil.
	**/
	if (dificultad == 1) {

		
		int opcion = rand() % contFacil;
		string campo = Facil[opcion];
		cout << "Cargando el campo " << campo << endl;

		//Se crea la matriz poco poblada de 9x9
		Tablero_Matriz tablero = Tablero_Matriz(9, 9);
		Tablero_Matriz tableroGuia = Tablero_Matriz(9, 9);
		Partida(tablero, tableroGuia, campo);
	}
	else if (dificultad == 2) {

		int opcion = rand() % contMedio;
		string campo = Medio[opcion];
		cout << "Cargando el campo " << campo << endl;

		//Se crea la matriz poco poblada de 16x16
		Tablero_Matriz tablero = Tablero_Matriz(16, 16);
		Tablero_Matriz tableroGuia = Tablero_Matriz(16, 16);
		Partida(tablero, tableroGuia, campo);
	}
	else if (dificultad == 3) {
		
		int opcion = rand() % contDificil;
		string campo = Dificil[opcion];
		cout << "Cargando el campo " << campo << endl;

		//Se crea la matriz poco poblada de 30x16
		Tablero_Matriz tablero = Tablero_Matriz(16, 30);
		Tablero_Matriz tableroGuia = Tablero_Matriz(16, 30);
		Partida(tablero, tableroGuia, campo);
	}
}


void GameSystem::Partida(Tablero_Matriz tablero, Tablero_Matriz tablero2, string IdArchivo)
{
	cout << "****______****************" << endl;
	cout << "PARTIDA INICIADA" << endl;
	cout << "****______****************" << endl;
	bool partida = true;
	std::ifstream campo;
	string linea;
	string casilla;
	campo.open(IdArchivo, ifstream::in);

	int posX = 1;
	int posY = 1;


	//Ciclo para llenar matriz de acuerdo al campo que carga la partida.
	getline(campo, linea);//creo un salto para ignorar los 9x9, 16x16, etc del txt.
	while (getline(campo, linea)) { //Avanzar por fila
		stringstream ss(linea);
		while (!ss.eof()) {//Avanzar por columna o commas (,).

			getline(ss, casilla, ',');

			//la primera matriz obtiene las bombas
			if (casilla == "X") {

				NodoCasilla*nuevoNodo = new NodoCasilla(posX, posY, casilla);
				tablero.AgregarNodo(nuevoNodo, posX, posY);

			}
			else if (casilla != "0") {

				NodoCasilla*nuevoNodo = new NodoCasilla(posX, posY, casilla);
				tablero.AgregarNodo(nuevoNodo, posX, posY);

			}


			posY++;

		}

		posX++;
		posY = 1;
	}


	//Ciclo que determina la partida en si, al terminar el ciclo se declara si gana o pierde la partida.
	while (partida == true) {


		DesplegarTablero(tablero, tablero2);
		//variables auxiliares para los valores que ingresa el usuario
		string tipo;
		string fila;

		int x;
		int y;
		string columna;
		cout << "Ingrese una opcion para la casilla (B = bandera, ? = sospechoso, A = destapado)" << endl;
		cout << "[B] Colocar Bandera" << endl;
		cout << "[?] Marcar como sospechoso" << endl;
		cout << "[A] Destapar celda" << endl;
		cout << "digite 'salir' para terminar la partida" << endl;
		getline(cin, tipo);


		tipo[0] = toupper(tipo[0]);


		//se verifica si el usuario ingresa una jugada valida
		if (tipo == "B" || tipo == "?" || tipo == "A") {
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			cout << "indique la fila a buscar" << endl;
			getline(cin, fila);
			try { //Validar respuesta del menu

				PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
				cout << "indique la columna a buscar" << endl;
				getline(cin, columna);
				try {


					system("CLS");//Limpiar consola

					//se setean las variables a estas otras para facilitar sintaxis de los algoritmos.
					x = std::stoi(fila); //y = columna
					y = std::stoi(columna); //x = fila





					if ((x < 0 || y < 0) || (dif == 1 && (y>9 || x > 9)) || (dif==2 && (y > 16 || x > 16) || (dif == 3 && (y > 32 || x > 16)))) {
						cout << "Columna/fila invalida, debe ser de valores positivos y dentro del rango del tablero" << endl;
						PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
						continue;
					}
					PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);


					//algoritmo para realizar la accion solicitada

					if (tipo == "B") {
						if (tablero2.BuscarNodo(x, y) == nullptr) { //se agrega bandera en caso de que no exista una en su lugar.
							NodoCasilla*nodoBandera = new NodoCasilla(x, y, "B");
							nodoBandera->SetEstado(true);
							cout << x << ";" << y << endl;
							tablero2.AgregarNodo(nodoBandera, x, y);
						}
						else {//en caso de marcar con bandera en una casilla que ya tenga bandera
							//se llama funcion eliminar nodo.
							tablero2.EliminarNodo(x, y);
						}

					}

					if (tipo == "?") {
						if (tablero2.BuscarNodo(x, y) == nullptr) { //se agrega un ? en caso de que no exista una en su lugar.

							NodoCasilla*nodoDudoso = new NodoCasilla(x, y, "?");
							nodoDudoso->SetEstado(true);
							tablero2.AgregarNodo(nodoDudoso, x, y);
						}
						else {//en caso de marcar con un ? en una casilla que ya tenga un ?
							  //se llama funcion eliminar nodo.
							tablero2.EliminarNodo(x, y);
						}
					}

					if (tipo == "A") {

						if (tablero.BuscarNodo(x, y) == nullptr) {
							//un 0 encontrado.
							
							if (tablero2.BuscarNodo(x, y) == nullptr) { //se checkea si el 0 no esta en el tablero2, en caso de enviar denuevo la misma coordenada.
							//Comienza recursion de 0s
								
								PlaySound(TEXT("Recursion.wav"), NULL, SND_ASYNC);
								RecursionCeros(x, y, tablero, tablero2);
							}

						}

						else if (tablero.BuscarNodo(x, y)->getValor() == "X") { //JUGADOR PIERDE

							PlaySound(TEXT("Explosion.wav"), NULL, SND_ASYNC);
							tablero2.AgregarNodo(tablero.BuscarNodo(x, y), x, y);
							tablero.BuscarNodo(x, y)->SetEstado(true);//Se marca que el nodo fue revelado.
						}
						else {

							//Se verifica si el numero encontrado ya fue encontrado anteriormente.
							if (tablero.BuscarNodo(x, y)->getEstado() == false) {

								//SE ENCUENTRA UN NUMERO
								//se descubre un numero, y se agrega al 2ndo tablero

								tablero2.AgregarNodo(tablero.BuscarNodo(x, y), x, y);
								tablero2.BuscarNodo(x, y)->SetEstado(true);//Se marca que el nodo fue revelado.
								tablero.BuscarNodo(x, y)->SetEstado(true);//Se marca que el nodo fue revelado.
							}


						}

					}


					//Realiza accion.




				}
				catch (const std::exception) {
					system("CLS");//Limpiar consola
					PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
					cout << "ERROR, columna invalida." << endl;
					cout << "**********************************************************************************" << endl;
					continue;
				}
			}
			catch (const std::exception) {
				system("CLS");//Limpiar consola
				PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
				cout << "ERROR, fila invalida." << endl;
				cout << "*************************************************************************************" << endl;

				continue;
			}

		}
		//condicion de termino en caso de que el jugador no quiera seguir con la partida.
		else if (tipo == "Salir") {
			PlaySound(TEXT("return.wav"), NULL, SND_ASYNC);
			system("CLS");//Limpiar consola
			partida = false;
			return;
		}
		else {
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Error.wav"), NULL, SND_ASYNC);
			cout << "ERROR, ingrese un movimiento valido" << endl;
			cout << "***************************************" << endl;
		}


	}
}




void GameSystem::RecursionCeros(int fila, int columna, Tablero_Matriz tablero, Tablero_Matriz tablero2)
{
	if (fila <= 0 || columna <= 0) {
	
		return;
	}
	else {

		if (fila <= 0 || columna <= 0) { //en caso de que se desborde hacia los nodos bases de las filas y columnas
			return;
		}

		if (dif == 1) {
			if (fila > 9 || columna > 9) { //en caso de que se salga de la matriz la recursion
				return;
			}
		}
		else if (dif == 2) {
			if (fila > 16 || columna > 16) { //en caso de que se salga de la matriz la recursion
				return;
			}
		}
		else if (dif == 3) {
			if (fila > 16 || columna > 30) { //en caso de que se salga de la matriz la recursion
				return;
			}
		}


		if (tablero.BuscarNodo(fila, columna) == nullptr) { //revisa si es un cero en el tablero 1

			if (tablero2.BuscarNodo(fila, columna) == nullptr) {//se verifica si no existe el cero en el tablero 2
				NodoCasilla* NodoCero = new NodoCasilla(fila, columna, "0");
				NodoCero->SetEstado(true); //se setea su estado revelado a true, para evitar que la recursion la tome.
				tablero2.AgregarNodo(NodoCero, fila, columna);

				
				

				return RecursionCeros(fila + 1, columna, tablero, tablero2), RecursionCeros(fila - 1, columna, tablero, tablero2), RecursionCeros(fila, columna + 1, tablero, tablero2), RecursionCeros(fila, columna - 1, tablero, tablero2);



			}
			else {
				if (tablero2.BuscarNodo(fila, columna)->getEstado() == true) { //detiene recursion si avanza a un 0 en tablero 2 y ya fue revelado (con el booleano).
					return;
				}

			}
		}
		else if (tablero.BuscarNodo(fila, columna)->getValor() != "X") {
			NodoCasilla* NodoNumero = new NodoCasilla(fila, columna, tablero.BuscarNodo(fila, columna)->getValor());
			NodoNumero->SetEstado(true);
			tablero2.AgregarNodo(NodoNumero, fila, columna);

			
			return;
		}


	}
}

