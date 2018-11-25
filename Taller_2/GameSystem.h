#pragma once
#include <iostream>
#include <string>
#include "pch.h"
using namespace std;
class GameSystem
{
	
public:

	GameSystem();
	~GameSystem();

	//*************************************************
	//Funciones de Requerimientos Funcionales
	//*************************************************
	void MenuPrincipal(); //Menu principal del juego.
	void MenuPartida(); //Menu de seleccion de dificultad.
	void MenuEstadisticas();//Menu de estadisticas del juego.
	void Partida(int dificultad); //Funcion que inicia la partida dependiendo de la dificultad
	void LecturaDificultades(); //Funcion que lee archivo de tableros con sus dificultades e Ids, se ejecuta al iniciar el programa.
	
	

private: 

	string* Facil;
	string* Medio;
	string* Dificil;
	
	int contFacil;
	int contMedio;
	int contDificil;






};





