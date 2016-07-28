#pragma once
#include "Outerdef.h"
#include "Character.h"
#include "PlayerChar.h"

class EnemyChar : public Character
{
	float engspeed = 1;
	float rotplus = 10;
	float shootAngle = 5;
	//Winkel zur x-achse (wie steigungswinkel)
	float gradientAngle(const sf::Vector2f & v) const;
	float EnemyChar::dist(const sf::Vector2f & v1, const sf::Vector2f & v2) const;
public:
	EnemyChar(float hp = 100, int shootDelay = 10, std::size_t pointCount = 7, sf::Color color = sf::Color(255, 0, 0), float shootAngle = 5)
		: shootAngle(shootAngle), Character(pointCount, hp, shootDelay)
	{
		setOrigin(getRadius(), getRadius());
		setFillColor(color);
		setOutlineColor(color);
	}

	//returnt 1, wenn Spieler anvisiert
	bool engagePlayer(const PlayerChar & player);
};