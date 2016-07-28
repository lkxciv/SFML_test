#include "Outerdef.h"
#include "Character.h"
#include "PlayerChar.h"
#include "EnemyChar.h"

float EnemyChar::gradientAngle(const sf::Vector2f & v) const
{
	return (atan2(v.y, v.x) / PI) * 180;
}

float EnemyChar::dist(const sf::Vector2f & v1, const sf::Vector2f & v2) const
{
	return sqrt((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}
bool EnemyChar::engagePlayer(const PlayerChar & player)
{
	//speed als richtungsvektor
	speed.y = engspeed * (-1)*cos((getRotation() / 180) * PI);
	speed.x = engspeed * sin((getRotation() / 180) * PI);
	//winkel vektor Gegner->Spieler auf y-achse
	float diffAngle = 180 - (atan2((-1)*(getPosition().x - player.getPosition().x), (-1)*(getPosition().y - player.getPosition().y)) / PI * 180);
	//Winkel zu Player
	diffAngle = this->getRotation() - diffAngle;
	if (diffAngle > 5 && diffAngle <= 180)
	{
		rotate((-1) * rotplus);
	}
	else if (diffAngle > 180 || diffAngle < -5)
	{
		rotate(rotplus);
	}
	if (diffAngle < 90 || diffAngle > -90)
	{
		move(speed);
	}
	if (diffAngle <= shootAngle || diffAngle >= (-1) * shootAngle)
	{
		return 1;
	}
	return 0;
}