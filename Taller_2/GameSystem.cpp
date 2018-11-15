#include "pch.h"

#include "GameSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

using namespace std;

GameSystem::GameSystem()
{
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
	//Logo Alternativo
	//cout << "██████╗ ██╗   ██╗███████╗ ██████╗ █████╗ ███╗   ███╗██╗███╗   ██╗ █████╗ ███████╗" << endl;
	//cout << "██╔══██╗██║   ██║██╔════╝██╔════╝██╔══██╗████╗ ████║██║████╗  ██║██╔══██╗██╔════╝" << endl;
	//cout << "██████╔╝██║   ██║███████╗██║     ███████║██╔████╔██║██║██╔██╗ ██║███████║███████╗" << endl;
	//cout << "██╔══██╗██║   ██║╚════██║██║     ██╔══██║██║╚██╔╝██║██║██║╚██╗██║██╔══██║╚════██║" << endl;
	//cout << "██████╔╝╚██████╔╝███████║╚██████╗██║  ██║██║ ╚═╝ ██║██║██║ ╚████║██║  ██║███████║" << endl;
	//cout << "╚═════╝  ╚═════╝ ╚══════╝ ╚═════╝╚═╝  ╚═╝╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝╚══════╝" << endl;
	

	//cout << "______                          ___  ___ _                    " << endl;
	//cout << "| ___ \                         |  \/  |(_)                   " << endl;
	//cout << "| |_/ / _   _  ___   ___   __ _ | .  . | _  _ __    __ _  ___ " << endl;
	//cout << "| ___ \| | | |/ __| / __| / _` || |\/| || || '_ \  / _` |/ __|" << endl;
	//cout << "| |_/ /| |_| |\__ \| (__ | (_| || |  | || || | | || (_| |\__ \" << endl;
	//cout << "\____/  \__,_||___/ \___| \__,_|\_|  |_/|_||_| |_| \__,_||___/" << endl;
	


	cout << "BuscaMinas" << endl;
	cout << "*************************************************************************************" 
		<< endl;
	
		

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
			cout << "Porfavor escriba un numero" << endl;
			cout << "*************************************************************************************" << endl;
			
			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {

		case 1:
			MenuPartida();
			break;


		case 2:
			MenuEstadisticas();
			break;


		case 3:
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
			cout << "Porfavor escriba una opcion valida (1,2,etc)" << endl;
			cout << "*************************************************************************************" << endl;

			continue;
		}
		int opcionVerificada = std::stoi(opcion);

		switch (opcionVerificada) {

		case 1:
			
			break;
		case 2:
			
			break;
		case 3:
			
			break;
		case 4://Vuelvo al menu Principal
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
