#include "Options.hpp"

#include <iostream>

#include "Application.hpp"
#include "ActorManager.hpp"
#include "StageManager.hpp"
#include "ControlManager.hpp"
#include "Gallery.hpp"
#include "Button.hpp"
#include "Mouse.hpp"
#include "Keyboard.hpp"

Options::Options(Application*const app) : Interface(app),
controlManager(nullptr),
actorManager(nullptr),
stageManager(nullptr) {



	/*Botones que tendr� esta interface. */
	buttons.push_back(new Button(89, 50, "BACK", ButtonType::SMALL));

	controlManager = new ControlManager;
	actorManager = new ActorManager;
	stageManager = new StageManager(actorManager);

	Control* control = new Control;
	/* Asigna acci�nes a las que respondera esta interface. */
	control->addActionName(ActionMenu::DOWN, "Bajar");
	control->addActionName(ActionMenu::UP, "Subir");
	control->addActionName(ActionMenu::ENTER, "Enter");
	control->addActionName(ActionMenu::LEFT, "Izquierda");
	control->addActionName(ActionMenu::RIGHT, "Derecha");
	control->addActionName(ActionMenu::BACKSPACE, "Atras");
	control->addActionName(ActionMenu::MOUSE_MICKEY_LEFT, "Raton Izquierdo");
	control->setActionPeripheral(ActionMenu::DOWN, app->getKeyboard(), ALLEGRO_KEY_DOWN, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::UP, app->getKeyboard(), ALLEGRO_KEY_UP, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::ENTER, app->getKeyboard(), ALLEGRO_KEY_ENTER, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::LEFT, app->getKeyboard(), ALLEGRO_KEY_LEFT, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::RIGHT, app->getKeyboard(), ALLEGRO_KEY_RIGHT, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::BACKSPACE, app->getKeyboard(), ALLEGRO_KEY_BACKSPACE, Peripheral::ON_PRESS);
	control->setActionPeripheral(ActionMenu::MOUSE_MICKEY_LEFT, app->getMouse(), Mouse::buttons::MICKEY_LEFT, Peripheral::ON_PRESS);


	/** Esta clase sera controlada por este control*/
	control->setOwner(this);
	controlManager->addControl(control);
	controlManager->addPeripheral(app->getKeyboard());
	controlManager->addPeripheral(app->getMouse());

	/* Agrega los botons al actorManager, ya no es necesario eliminar la memoria reservada por
	estos ya que actorManager se encarga de eso. */
	for (auto it = buttons.begin(); it != buttons.end(); it++) {
		actorManager->add(*it);
	}
	index = 0; // Inicialmente el foco estar� en el primer boton que se agrego al vector buttons.
	buttons.at(index)->isFocused(true);

	useMouse = true;
}

void Options::draw() const {
	static Gallery& gallery = Gallery::getSingleton();
	al_draw_bitmap(gallery.getImage(R::Image::BACKGROUND1), 0, 0, 0);

	static auto fSmall = gallery.getFont(R::Font::VENUS_SMALL);
	static auto f = gallery.getFont(R::Font::VENUS_20);
	static auto fBig = gallery.getFont(R::Font::VENUS_TITLES);

	al_draw_text(fBig, R::Color::SHADOWN_TITLE, 404, 24, ALLEGRO_ALIGN_CENTER, R::String::OPTIONS.c_str());
	al_draw_text(fBig, R::Color::WHITE, 400, 20, ALLEGRO_ALIGN_CENTER, R::String::OPTIONS.c_str());

	// Llama a la funci�n draw() de cad� bot�n.
	for (auto it = buttons.begin(); it != buttons.end(); it++) {
		(*it)->draw();
	}

}

void Options::update() {
	stageManager->update();
	controlManager->update();
	stageManager->update();

	if (app->getMouse()->changedPosition()) {
		al_show_mouse_cursor(app->getDisplay());
		useMouse = true;
		app->getMouse()->updateLastPosition();
	}

	if (useMouse) {
		insideIndex = insideButton();
		if (insideIndex != -1 && insideIndex != index) {
			buttons.at(index)->isFocused(false);
			index = insideIndex;
			buttons.at(index)->isFocused(true);
		}
	}
}

void Options::doAction(action_t action, int magnitute) {
	buttons.at(index)->isFocused(false);
	switch (action) {
	case ActionMenu::UP:
		//al_hide_mouse_cursor(app->getDisplay());
		index = (index + buttons.size() - 1) % buttons.size();
		useMouse = false;
		break;
	case ActionMenu::DOWN:
		//al_hide_mouse_cursor(app->getDisplay());
		index = (index + 1) % buttons.size();
		useMouse = false;
		break;
	case ActionMenu::LEFT:
		//al_hide_mouse_cursor(app->getDisplay());
		index = (index + buttons.size() - 1) % buttons.size();
		useMouse = false;
		break;
	case ActionMenu::RIGHT:
		//al_hide_mouse_cursor(app->getDisplay());
		index = (index + 1) % buttons.size();
		useMouse = false;
		break;
	case ActionMenu::ENTER:
		switch (index) {
		case 0: /* BACK */
			app->setInterface(Application::INTERFACE_SCREEN::MAIN_MENU);
			break;

		default:
			break;
		}

		break;
	case ActionMenu::BACKSPACE:
		app->setInterface(Application::INTERFACE_SCREEN::MAIN_MENU);
		break;

	case ActionMenu::MOUSE_MICKEY_LEFT:
		if (useMouse) {
			insideIndex = insideButton();
			switch (insideIndex) {
			case 0: /* BACK */
				app->setInterface(Application::INTERFACE_SCREEN::MAIN_MENU);
				break;

			default:
				break;
			}
		}

		break;

	}
	buttons.at(index)->isFocused(true);
}

int Options::insideButton() const {
	for (size_t i = 0; i < buttons.size(); i++) {
		if (app->getMouse()->inside(buttons.at(i)->getXInit(), buttons.at(i)->getYInit(), buttons.at(i)->getXEnd(), buttons.at(i)->getYEnd())) {
			return i;
		}
	}
	return -1;
}

Options::~Options() {
	delete controlManager;
	delete actorManager;
	delete stageManager;
    std::cout << "Sali de options" << std::endl;
}
