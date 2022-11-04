#pragma once
#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <allegro5/allegro.h>

class Interface;
class Menu;
class Peripheral;
class Keyboard;
class Mouse;
class About;
class Help;
class Options;
class HighScores;
class Game;

class Application {
public:
	enum class INTERFACE_SCREEN : unsigned int {
		MAIN_MENU,
		GAME,
		ABOUT,
		OPTIONS,
		HELP,
		HIGHSCORES };

	Application();

	/**
	*	Inicia todos los recursos e inicia las fuci�nes de Allegro.
	*/
	void init(int argc, char** arv);

	/**
	*  Ac� se ejecuta el bucle principal del juego( main loop ).
	*/
	void loop();

	void setInterface(INTERFACE_SCREEN appInterface, bool reinit = false);

	/** Termina el bucle principal. */
	void quit();

	///** Getters para los perif�ricos.*/
	Keyboard* getKeyboard() const;
	Mouse* getMouse() const;
	ALLEGRO_DISPLAY* getDisplay() const;

	~Application();
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* eventQueue;
	ALLEGRO_TIMER* timer;
	ALLEGRO_EVENT event;
	Interface* actualInterface;

	// Interfaces :
	Menu* menu;	 // Menu Principal
	Options* options; // Menu de opciones.
	HighScores* highScores;	// Muestra los puntajes m�s altos.
	Game* game; // Juego.
	About* about; // Informaci�n acerca del juego.
	Help* help; // Ayuda acerca del juego.

				// Clases que abstraen a los perif�ricos mouse y teclado.
	Mouse* mouse;
	Keyboard* keyboard;

	bool exit;
};

#endif // !APPLICATION_HPP
