/** @class Vector2 Abstacci�n de un vector con sus operaci�nes principales.
*   �sta clase es utilizada para especificar un punto(un pixel) en la pantalla, como
*	la pantalla inicia en la posici�n (0, 0) un vector funciona bi�n.
*/

#pragma once
#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>

class Vector2 {

	/** Funci�n amiga que sobrecarga el operador de extracci�n de flujo.
	*   Imprime la posici�n x e y en formato "(x, y)".*/
	friend	std::ostream& operator<<(std::ostream& stream, const Vector2& vec);

public:
	Vector2(const float& x = 0.0f, const float& y = 0.0f);

	/** Operaciones vectoriales, funci�nes con sobrecarga de operadores.  */
	Vector2 operator+(const Vector2& vec);
	Vector2 operator-(const Vector2& vec);

	Vector2 operator*(const Vector2& vec);

	// Multiplicaci�n de un vector por un escalar
	Vector2 operator*(const float& scalar);
	Vector2 operator/(const Vector2& vec);


	const Vector2& operator=(const Vector2& vec);
	Vector2& operator+=(const Vector2& vec);

	float X() const;
	float Y() const;

	void setPosition(const float& x, const float& y);
	void setX(const float& x);
	void setY(const float& y);
private:
	float x;
	float y;
};

#endif // !VECTOR2_HPP