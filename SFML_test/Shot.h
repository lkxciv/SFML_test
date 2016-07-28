#pragma once
#include "Outerdef.h"
#include "Character.h"

class Shot : public sf::RectangleShape
{
	float speedfactor = 1;
	sf::Vector2f speed;

public:
	//! passts?
	Shot(const Character & charac, float speedfactor = 1)
		: speedfactor(speedfactor), RectangleShape(sf::Vector2f(charac.getRadius() / 3, charac.getRadius() / 4))
	{
		setOrigin(this->getSize().x / 2, this->getSize().y / 2);
		this->setPosition(charac.getPosition());
		this->setRotation(charac.getRotation());
		speed.y = speedfactor * (-1)*cos((getRotation() / 180) * PI);
		speed.x = speedfactor * sin((getRotation() / 180) * PI);
		speed += charac.speed;
		//!
		//this->move(charac.getRadius() * speed / speedfactor);
		this->setFillColor(charac.getFillColor());
		this->setOutlineColor(charac.getOutlineColor());
	}

	void refresh();
};