#pragma once
#include "Outerdef.h"

class Character : public sf::CircleShape
{
public:
	using CircleShape::CircleShape;
	float hp;
	sf::Vector2f speed;
	int shootDelay;
	int shootDelayTimer = 0;
	//! Radius ändern
	Character(std::size_t pointCount, float hp = 100, int shootDelay = 0, sf::Vector2f speed = sf::Vector2f(0, 0), sf::Vector2f position = sf::Vector2f(400, 200), float radius = 15)
		: hp(hp), speed(speed), shootDelay(shootDelay), CircleShape(radius, pointCount)
	{
		setPosition(position);
	}

	float getDistance(const Character & c2) const;
	bool isCollided(const Character & c2) const;
	float absSpeed();
	//return 1, wenn geschossen werden, also Zeit gekommen ist
	bool delayedShotReady();
};