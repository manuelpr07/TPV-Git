#pragma once

#ifndef ABOUT_HPP
#define ABOUT_HPP

#include <vector>

#include "Interface.hpp"
#include "ControllableObject.hpp"

class Application;
class ControlManager;
class ActorManager;
class StageManager;
class Button;

class About : public Interface, public ControllableObject {
public:
	explicit About(Application* const app);

	virtual void draw() const override;
	virtual void update() override;
	virtual void doAction(action_t action, int magnitute) override;

	/*Si el mouse se encuentra dentro de una regi�n ocupado por un bot�n del vector buttons
	entonces retorna el indice del bot�n en el vector, de lo contrario retorna (-1). */
	int insideButton() const;

	~About();
private:
	ControlManager* controlManager;
	ActorManager* actorManager;
	StageManager* stageManager;
	std::vector<Button*> buttons; // Botones para el men� de la interface.
	bool useMouse;
	int index; // Indice del bot�n en el que se encuentra actualmente el foco.
	int insideIndex; // Indice del bot�n que esta debajo del mouse.
};

#endif // !ABOUT_HPP
