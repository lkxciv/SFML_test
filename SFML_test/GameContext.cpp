#include "Outerdef.h"
#include "Character.h"
#include "Shot.h"
#include "PlayerChar.h"
#include "EnemyChar.h"
#include "GameContext.h"

void GameContext::shoot(const Character & charac, float speed)
{
	shots.push_back(Shot(charac, speed));
}

void GameContext::refreshShots()
{
	for (int i = 0; i < shots.size(); i++)
	{
		shots.at(i).refresh();
	}
}

bool GameContext::shotHitDetect()
{
	bool isPlayerHit = 0;
	auto e_it = enemies.begin();
	while (e_it != enemies.end())
	{
		auto s_it = shots.begin();
		while (s_it != shots.end())
		{
			//ist Schuss im Radius
			//! Radius änderbar
			if (dist(e_it->getPosition(), s_it->getPosition()) <= e_it->getRadius() && s_it->getFillColor() != e_it->getFillColor())
			{
				s_it = shots.erase(s_it);
				e_it->hp -= shotDamage;
			}
			else
			{
				s_it++;
			}
		}
		if (e_it->hp <= 0)
		{
			e_it = enemies.erase(e_it);
		}
		else
		{
			e_it++;
		}
	}
	for (auto s_it = shots.begin(); s_it != shots.end(); )
	{
		if (dist(player.getPosition(), s_it->getPosition()) < player.getRadius() && s_it->getFillColor() != player.getFillColor())
		{
			s_it = shots.erase(s_it);
			player.hp -= 100;
			if (player.hp <= 0)
			{
				isPlayerHit = 1;
			}
		}
		else
		{
			s_it++;
		}
	}
	return isPlayerHit;
}

GameContext::GameContext(int sizex, int sizey) : sizex(sizex), sizey(sizey)
{
	//enemy setup
	for (int i = 0; i < enemylvl; i++)
	{
		enemies.push_back(EnemyChar(enemyHealth, enemyShotDelay));
	}
	player = PlayerChar(playerHealth, playerShotDelay);
	player.setPosition(sf::Vector2f(sizex / 2, sizey / 2));
	//Todo
	//Gegner auf Spielfeld platzieren
	enemiesSetup();
}

void GameContext::enemiesSetup()
{
	//distanz zu spieler
	float distPlayer;
	if (sizex <= sizey)
	{
		distPlayer = 0.8 * sizex / 2;
	}
	else
	{
		distPlayer = 0.8 * sizey / 2;
	}
	float radIncr = (2 * PI) / enemylvl;
	//radial um spieler, durch offset erzielt
	for (int i = 0; i < enemylvl; i++)
	{
		enemies.at(i).setPosition(sf::Vector2f(cos(radIncr * i) * distPlayer + player.getPosition().x
			, sin(radIncr * i) * distPlayer + player.getPosition().y));
	}
}

void GameContext::refresh()
{
	playerBoundaryCheck();
	scatterCleanup();
	shotHitDetect();
	refreshPlayer();
	refreshShots();
	refreshEnemies();
	nextRoundCheck();
}

float GameContext::dist(const sf::Vector2f & v1, const sf::Vector2f & v2) const
{
	return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

void GameContext::refreshEnemies()
{
	for (int i = 0; i < enemies.size(); i++)
	{
		//schauen en's auf player?
		if (enemies.at(i).engagePlayer(player) == 1 && enemies.at(i).delayedShotReady() == 1)
		{
			shoot(enemies.at(i), enemyShotSpeed);
		}
	}
}

void GameContext::refreshPlayer()
{
	player.refreshPos();
	//Schuss abfragen
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Return)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		&& player.delayedShotReady() == 1)
	{
		shoot(player, playerShotSpeed);
	}
	//Reset, falls r gedrückt wurde
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		round = 0;
		enemies.clear();
		nextRoundCheck();
	}
}

void GameContext::scatterCleanup()
{
	for (auto s_it = shots.begin(); s_it != shots.end(); )
	{
		sf::Vector2f pos = s_it->getPosition();
		if (pos.x < 0 || pos.y < 0 || pos.x > sizex || pos.y > sizey)
		{
			s_it = shots.erase(s_it);
		}
		else
		{
			s_it++;
		}
	}
}

void GameContext::playerBoundaryCheck()
{
	if (player.getPosition().x > sizex)
	{
		player.setPosition(0, player.getPosition().y);
	}
	if (player.getPosition().y > sizey)
	{
		player.setPosition(player.getPosition().x, 0);
	}
	if (player.getPosition().x < 0)
	{
		player.setPosition(sizex, player.getPosition().y);
	}
	if (player.getPosition().y < 0)
	{
		player.setPosition(player.getPosition().x, sizey);
	}
}

void GameContext::nextRoundCheck()
{
	if (enemies.size() == 0)
	{
		round++;
		shots.clear();
		player.setRotation(0);
		enemylvl = enemylvlInit * round;
		for (int i = 0; i < enemylvl; i++)
		{
			enemies.push_back(EnemyChar(enemyHealth, enemyShotDelay));
		}
		player.hp = playerHealth;
		player.setPosition(sf::Vector2f(sizex / 2, sizey / 2));
		enemiesSetup();
	}
}