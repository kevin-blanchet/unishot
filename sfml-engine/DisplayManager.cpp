#include "DisplayManager.h"
#include "GameManager.h"
#include "LogManager.h"

DisplayManager::~DisplayManager()
{
	this->pWindow->close();
	delete this->pWindow;
}

DisplayManager& DisplayManager::getInstance()
{
	static DisplayManager displayManager;
	return displayManager;
}

bool DisplayManager::drawString(sf::Vector2f pos, std::string str, Justification just, sf::Color color) const
{
	if (pWindow == NULL) return false;

	sf::Text text(str, this->defaultFont);
	text.setFillColor(color);

	sf::Vector2f startingPos = pos;
	switch (just)
	{
	case Justification::Center:
		startingPos.x = pos.x - text.getGlobalBounds().width / 2;
		break;
	case Justification::Right:
		startingPos.x = pos.x - text.getGlobalBounds().width;
		break;
	case Justification::Left:
	default:
		break;
	}
	text.setPosition(startingPos);
	this->pWindow->draw(text);
	return true;
}

void DisplayManager::update()
{
	pWindow->draw(testCircle);






	if (this->pWindow == NULL) LM.consoleLog("Err: No Window");
	pWindow->display();
	pWindow->clear(this->bgColor);
}

int DisplayManager::getWidth() const
{
	return this->windowWidth;
}

int DisplayManager::getHeight() const
{
	return this->windowHeight;
}

sf::Color DisplayManager::getBgColor() const
{
	return this->bgColor;
}

void DisplayManager::setBgColor(sf::Color newColor)
{
	this->bgColor = newColor;
}

bool DisplayManager::setDefaultFont(std::string fontFile)
{
	return this->defaultFont.loadFromFile(fontFile);
}

sf::RenderWindow* DisplayManager::getWindow() const
{
	return this->pWindow;
}

DisplayManager::DisplayManager()
{
	this->setType("DisplayManager");
	this->windowWidth = WINDOW_WIDTH_DEFAULT;
	this->windowHeight = WINDOW_HEIGHT_DEFAULT;
	this->bgColor = WINDOW_BG_COLOR_DEFAULT;

	this->pWindow = new sf::RenderWindow(sf::VideoMode(this->windowWidth, this->windowHeight), WINDOW_TITLE_DEFAULT, WINDOW_STYLE_DEFAULT);
	this->pWindow->setVerticalSyncEnabled(WINDOW_VSYNC_DEFAULT);
	this->pWindow->setFramerateLimit(WINDOW_FRAMERATE_DEFAULT);

	if (!this->defaultFont.loadFromFile(DEFAULT_FONT_FILE)) {
		LM.errorLog("failed to load font");
	}

	this->update();

	this->testCircle = sf::CircleShape(100.f);
	this->testCircle.setFillColor(sf::Color::Green);
}