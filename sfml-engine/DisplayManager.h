#pragma once

#include "Manager.h"

#include <SFML/Graphics.hpp>
#include <string>

#define DM DisplayManager::getInstance()


enum class Justification
{
    Left,
    Center,
    Right
};

const std::string DEFAULT_FONT_FILE = "Ressources/Fonts/ARIAL.TTF";

const int WINDOW_FRAMERATE_DEFAULT = 60;
const bool WINDOW_VSYNC_DEFAULT = true;
const int WINDOW_WIDTH_DEFAULT = 1280;
const int WINDOW_HEIGHT_DEFAULT = 720;
const int WINDOW_STYLE_DEFAULT = sf::Style::Titlebar | sf::Style::Close;
const sf::Color WINDOW_BG_COLOR_DEFAULT = sf::Color::White;
const std::string WINDOW_TITLE_DEFAULT = "Alabaster";

class DisplayManager :
    public Manager
{
public:
    ~DisplayManager();

    static DisplayManager& getInstance();

    bool drawString(sf::Vector2f pos, std::string str, Justification just, sf::Color color) const;

    virtual void update();

    sf::RenderWindow* getWindow() const;
    int getWidth() const;
    int getHeight() const;
    sf::Color getBgColor() const;
    void setBgColor(sf::Color newColor);
    bool setDefaultFont(std::string fontFile);
private:
    DisplayManager(); //Singleton - Le constructeur est privé
    DisplayManager(const DisplayManager&) = delete; //Singleton - pas de copie
    DisplayManager& operator=(const DisplayManager&) = delete; //Singleton - pas d'assignation

    sf::RenderWindow* pWindow;
    int windowWidth;
    int windowHeight;
    sf::Color bgColor;
    sf::Font defaultFont;
};

