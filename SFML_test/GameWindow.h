#pragma once
#include "Outerdef.h"
#include "GameContext.h"

class GameWindow
{
public:
	sf::Clock clock;
	sf::RenderWindow window;
	sf::Event event;

	GameWindow(sf::VideoMode vmode = sf::VideoMode(800, 600), sf::String title = "Game", unsigned int fps = 60);
	//Fenstergröße von GameContext vorgegeben
	GameWindow(const GameContext & gc, sf::String title = "Game", unsigned int fps = 60);
	GameWindow(const GameWindow & gw) = default;
	GameWindow & operator=(const GameWindow & gw) = default;
	bool isOpen() const;
	void refreshEvents();
	//entfernen, alt
	void drawDisp(const PlayerChar & player);
	void drawDisp(const GameContext & gc);

};
