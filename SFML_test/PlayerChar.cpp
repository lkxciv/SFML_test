#include "Outerdef.h"
#include "Character.h"
#include "PlayerChar.h"

void PlayerChar::refreshPos()
{
	speed.x *= speeddecay;
	speed.y *= speeddecay;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		rotate((-1) * rotplus);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		rotate(rotplus);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		speed.y += speedplus * (-1)*cos((getRotation() / 180) * PI);
		speed.x += speedplus * sin((getRotation() / 180) * PI);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		speed.y -= speedplus * (-1)*cos((getRotation() / 180) * PI);
		speed.x -= speedplus * sin((getRotation() / 180) * PI);
	}
	move(speed);
}