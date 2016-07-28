#pragma once
#include "Outerdef.h"
#include "Character.h"

class PlayerChar : public Character
{
	using Character::Character;
	//! Stimmt 1?
	float speedplus = 1;
	float rotplus = 5;
	float speeddecay = 0.95f;
public:
	PlayerChar(float hp = 1000, int shotDelay = 0, std::size_t pointCount = 3, sf::Color color = sf::Color(0, 100, 255))
		: Character(pointCount, hp, shotDelay)
	{
		setFillColor(color);
		setOutlineColor(color);
		setOrigin(getRadius(), 0);
	}

	void refreshPos();
};