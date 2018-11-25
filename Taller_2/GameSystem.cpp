
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


	//Logo Alternativo
	//cout << "██████╗ ██╗   ██╗███████╗ ██████╗ █████╗ ███╗   ███╗██╗███╗   ██╗ █████╗ ███████╗" << endl;
	//cout << "██╔══██╗██║   ██║██╔════╝██╔════╝██╔══██╗████╗ ████║██║████╗  ██║██╔══██╗██╔════╝" << endl;
	//cout << "██████╔╝██║   ██║███████╗██║     ███████║██╔████╔██║██║██╔██╗ ██║███████║███████╗" << endl;
	//cout << "██╔══██╗██║   ██║╚════██║██║     ██╔══██║██║╚██╔╝██║██║██║╚██╗██║██╔══██║╚════██║" << endl;
	//cout << "██████╔╝╚██████╔╝███████║╚██████╗██║  ██║██║ ╚═╝ ██║██║██║ ╚████║██║  ██║███████║" << endl;
	//cout << "╚═════╝  ╚═════╝ ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝" << endl;
	



	//cout <<	"    C1 C2 C3 C4 C5 C6 C7 C8 C9 "<< endl;
	//cout << " F1 [1][X][1][0][0][0][1][X][2]" << endl;
	//cout << " F2 [2][2][1][0][0][1][3][4][X]" << endl;
	//cout << " F3 [X][1][0][0][0][1][X][X][2]" << endl;
	//cout << " F4 [2][2][0][0][0][1][2][2][1]" << endl;
	//cout << " F5 [X][2][1][0][0][0][0][0][0]" << endl;
	//cout << " F6 [2][X][1][0][0][0][0][0][0]" << endl;
	//cout << " F7 [1][1][1][1][1][2][1][1][0]" << endl;
	//cout << " F8 [0][0][0][1][X][2][X][1][0]" << endl;
	//cout << " F9 [0][0][0][1][1][2][1][1][0]" << endl;
		













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
			Partida(1);
			break;
		case 2:
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			Partida(2);
			break;
		case 3:
			system("CLS");//Limpiar consola
			PlaySound(TEXT("Boton.wav"), NULL, SND_ASYNC);
			Partida(3);
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

void GameSystem::Partida(int dificultad)

{

	//Dependiendo de la dificultad, se genera un numero random para seleccionar un campo de forma aleatoria entre las dificultades.
	//1 = facil, 2 = medio, 3 = dificil.
	if (dificultad == 1) {
		int opcion = rand() % contFacil;
		string campo = Facil[opcion];
		cout << "Cargando el campo " << campo << endl;
		Tablero_Matriz tablero = Tablero_Matriz(9, 9);


	}
	else if (dificultad == 2) {
		int opcion = rand() % contMedio;
		string campo = Medio[opcion];
		cout << "Cargando el campo " << campo << endl;
		Tablero_Matriz tablero = Tablero_Matriz(16, 16);


	}
	else if (dificultad == 3) {
		int opcion = rand() % contDificil;
		string campo = Dificil[opcion];
		cout << "Cargando el campo " << campo << endl;
		Tablero_Matriz tablero = Tablero_Matriz(30, 16);


	}
}

void GameSystem::LecturaDificultades()
{
	std::ifstream archivoCampos;
	archivoCampos.open("Campos.txt", ifstream::in);
	string id;
	string dificultad;
	string linea;

	if (archivoCampos.is_open()) {

		cout << "***************************************************" << endl;
		while (getline(archivoCampos, linea)) {
			//crear cliente


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


			cout << id << "," << dificultad << endl;

			cout << "***************************************************" << endl;

		}

	}
}




