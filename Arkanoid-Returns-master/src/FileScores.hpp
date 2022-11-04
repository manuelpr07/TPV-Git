#pragma once

#ifndef FILESCORES_HPP
#define FILESCORES_HPP

#include <string>
#include <list>

#include "Actor.hpp"

struct ScorePlayer {
	int score; /*El puntaje que obtuvo hasta que termin� el juego*/
	int level; /* El nivel al que lleg� el jugador. */
	std::string name; /*Nombre del jugador.*/
};



class FileScores : public Actor {
public:
	FileScores(const float& x, const float& y);

	virtual void draw() const override;
	virtual void update() override;

	/* Carga los puntajes del archivo, solo se ejecut� al iniciar el programa. */
	void loadScores();

	/*Guarda los puntajes en el archivo.*/
	void saveScores();

	// A�ade un nuevo score.
	static void pushScore(int score, int level, std::string name);

	/*Borra todos los datos de la lista de puntajes, normalmente es llamado
	desde  Options->clear scores */
	static void clearScores();

	~FileScores();
private:
	static const int maxPlayers; // M�ximo de puntajes que se guardar�n y mostrar�n en la pantalla.
	static const std::string filename; // Nombre del archivo donde se guardar�n los puntajes.
	static std::list<ScorePlayer> listScores;
};
#endif // !FILESCORES_HPP
