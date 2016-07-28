#include "Outerdef.h"
#include "Character.h"

bool Character::delayedShotReady()
{
	if (shootDelayTimer < shootDelay)
	{
		shootDelayTimer++;
		return 0;
	}
	else
	{
		shootDelayTimer = 0;
		return 1;
	}
}

float Character::getDistance(const Character & c2) const
{
	return sqrt((this->getPosition().x - c2.getPosition().x) * (this->getPosition().x - c2.getPosition().x)
		+ (this->getPosition().y - c2.getPosition().y) * (this->getPosition().y - c2.getPosition().y));
}

bool Character::isCollided(const Character & c2) const
{
	if (this->getDistance(c2) < this->getRadius() || this->getDistance(c2) < c2.getRadius())
	{
		return true;
	}
	else
	{
		return false;
	}
}

float Character::absSpeed()
{
	return sqrt(speed.x * speed.x + speed.y * speed.y);
}