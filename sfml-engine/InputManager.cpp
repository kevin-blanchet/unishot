#include "InputManager.h"

#include "GameManager.h"
#include "LogManager.h"
#include "DisplayManager.h"


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
	/*KeyboardEvent kEvent;
	MouseEvent mEvent;
	Keyboard::Key key;*/
	while (DM.getWindow()->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			DM.getWindow()->close();
			GM.setRunning(false);
			break;
			/*
		case sf::Event::EventType::KeyPressed:
			key = sfKeyToAeKey(event.key.code);
			kEvent.setKey(key);
			kEvent.setKeyboardAction(KeyboardEventAction::KeyPressed);
			this->onEvent(&kEvent);
			break;
		case sf::Event::EventType::KeyReleased:
			kEvent.setKey(sfKeyToAeKey(event.key.code));
			kEvent.setKeyboardAction(KeyboardEventAction::KeyReleased);
			this->onEvent(&kEvent);
			break;
		case sf::Event::EventType::MouseButtonPressed:
			mEvent.setMouseAction(MouseEventAction::Pressed);
			mEvent.setButton(sfButtonToAeButton(event.mouseButton.button));
			mEvent.setMousePosition({ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
			this->onEvent(&mEvent);
			break;
		case sf::Event::EventType::MouseButtonReleased:
			mEvent.setMouseAction(MouseEventAction::Released);
			mEvent.setButton(sfButtonToAeButton(event.mouseButton.button));
			mEvent.setMousePosition({ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
			this->onEvent(&mEvent);
			break;
		case sf::Event::EventType::MouseMoved:
			mEvent.setMouseAction(MouseEventAction::Moved);
			mEvent.setButton(sfButtonToAeButton(event.mouseButton.button));
			mEvent.setMousePosition({ static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y) });
			this->onEvent(&mEvent);
			break;
			*/
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