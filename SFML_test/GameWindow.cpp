#include "Outerdef.h"
#include "GameContext.h"
#include "GameWindow.h"

GameWindow::GameWindow(sf::VideoMode vmode, sf::String title, unsigned int fps)
{
	window.create(vmode, title);
	window.setFramerateLimit(fps);
}

GameWindow::GameWindow(const GameContext & gc, sf::String title, unsigned int fps)
{
	window.create(sf::VideoMode(gc.sizex, gc.sizey), title);
	window.setFramerateLimit(fps);
}

bool GameWindow::isOpen() const
{
	return window.isOpen();
}

void GameWindow::refreshEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}
	}
}

void GameWindow::drawDisp(const PlayerChar & player)
{
	window.clear();
	window.draw(player);
	window.display();
}

void GameWindow::drawDisp(const GameContext & gc)
{
	sf::Font font;
	font.loadFromFile("arial.ttf");
	if (gc.player.hp >= 0)
	{
		sf::Text screentxt = sf::Text("Runde: " + std::to_string(gc.round) + " Leben: " + std::to_string((int)gc.player.hp), font);
		window.clear();
		window.draw(screentxt);
		for (int i = 0; i < gc.enemies.size(); i++)
		{
			window.draw(gc.enemies.at(i));
		}
		for (int i = 0; i < gc.shots.size(); i++)
		{
			window.draw(gc.shots.at(i));
		}
		window.draw(gc.player);
	}
	else
	{
		sf::Text deathtxt = sf::Text("Tot. Neustarten (R)", font);
		deathtxt.setPosition(gc.sizex / 2 - 100, gc.sizey / 2);
		window.clear();
		window.draw(deathtxt);
	}
	window.display();
}