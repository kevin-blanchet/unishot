#include "InputManager.h"

#include "GameManager.h"
#include "LogManager.h"
#include "DisplayManager.h"
#include "KeyboardEvent.h"
#include "MouseEvent.h"


InputManager::~InputManager()
{
	DM.getWindow()->setKeyRepeatEnabled(true);
}

InputManager& InputManager::getInstance()
{
	static InputManager* inputManager = new InputManager();
	return *inputManager;
}

void InputManager::update()
{
	sf::Event event;
	KeyboardEvent kEvent;
	MouseEvent mEvent;

	while (DM.getWindow()->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			DM.getWindow()->close();
			GM.setRunning(false);
			break;
		case sf::Event::EventType::KeyPressed:
			kEvent.setKey(event.key.code);
			kEvent.setKeyboardAction(event.type);
			onEvent(&kEvent);
			break;
		case sf::Event::EventType::KeyReleased:
			kEvent.setKey(event.key.code);
			kEvent.setKeyboardAction(event.type);
			onEvent(&kEvent);
			break;
		case sf::Event::EventType::MouseButtonPressed:
			mEvent.setMouseAction(event.type);
			mEvent.setButton(event.mouseButton.button);
			mEvent.setMousePosition({ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
			this->onEvent(&mEvent);
			break;
		case sf::Event::EventType::MouseButtonReleased:
			mEvent.setMouseAction(event.type);
			mEvent.setButton(event.mouseButton.button);
			mEvent.setMousePosition({ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
			this->onEvent(&mEvent);
			break;
		case sf::Event::EventType::MouseMoved:
			mEvent.setMouseAction(event.type);
			mEvent.setMousePosition({ static_cast<float>(event.mouseMove.x), static_cast<float>(event.mouseMove.y) });
			this->onEvent(&mEvent);
			break;
		default:
			break;
		}
	}
}

InputManager::InputManager()
{
	this->setType("InputManager");
	DM.getWindow()->setKeyRepeatEnabled(false);
}