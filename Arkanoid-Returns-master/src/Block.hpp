#pragma once

#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <allegro5/allegro.h>

#include "Actor.hpp"
#include "Vector2.hpp"
#include "Bonus.hpp"

// Constantes para identificar a los tipos de bloques.
enum class BlockType : int { WHITE = 1, ORANGE, LIGTH_BLUE, GREEN, RED, BLUE, PINK, YELLOW, SILVER, GOLD };
static int BlockValue[] = { 0, 50, 60, 70, 80, 90, 100, 110, 120, 50 };

class Sprite;

class Block : public Actor {
public:
	explicit Block(const float& coorX = 0.0f, const float& coordY = 0.0f, BlockType type = BlockType::WHITE);

	virtual void draw() const override;
	virtual void update() override;

	//Establece y retorna las vidas. 
	void setLives(short lives);
	short getLives() const;

	// Retorna el tipo.
	BlockType getType() const;

	// Ancho y alto del bloque.
	float getWidth() const;
	float getHeight() const;

	// Bonus
	void setBonusType(BonusType bonus);
	BonusType getBonusType() const;

	/*Retorna el valor que se a�adira al puntaje cuando el bloque sea destruido.*/
	int getValue() const;

	void setCoord(int x, int y);

	/*El bloque pierde una vida si es que es del tipo Silver, de lo contrario desapar�ce porque
	las vidas del bloque es 0. */
	void die();

	/* Posici�n desde la que se iniciara a pintar, es el mismo para todos.*/
	static Vector2 referencePosition;

	~Block();
private:
	void initType();

	Sprite* sprite;/* Animaci�n cuando la pelota choca con un bloque de tipo gold o silver.*/

				   // Posici�nes en el BITMAP para tomar s�lo una parte.
	Vector2 initPos; // Posici�n inicial
	Vector2 dimen; /* Ancho y alto, esto es igual para todos, los valores son diferentes
					que al llamar a las funci�nes getWidth y getHeight de esta clase,
					ya que al pintar se muestra tambi�n la sombra. */

	short lives; // Vidas del bloque.- Es 2 para el tipo Silver y 1 para el resto, a excepci�n de Gold(Este nunca muere).
	BlockType type;
	BonusType bonusType; // Bonus si es que tiene

};

#endif // !BLOCK_HPP
