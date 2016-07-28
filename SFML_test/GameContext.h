#pragma once
#include "Outerdef.h"
#include "Character.h"
#include "Shot.h"
#include "PlayerChar.h"
#include "EnemyChar.h"

class GameContext
{
private:
	//Character schiesst
	void shoot(const Character & charac, float speed = 1);
	//Schüsse weiterführen
	void refreshShots();
	//1, wenn Spieler getroffen, 0 sonst,
	//falls Gegner getroffen 0 und gelöscht
	bool shotHitDetect();
public:
	PlayerChar player;
	std::vector<EnemyChar> enemies;
	std::vector<Shot> shots;
	sf::Clock clock;
	int enemylvlInit = 5;
	int enemylvl = enemylvlInit;
	int sizex, sizey;
	float shotDamage = 100;
	float enemyShotSpeed = 2;
	float playerShotSpeed = 3;
	int enemyShotDelay = 10;
	int playerShotDelay = 2;
	float enemyHealth = 100;
	float playerHealth = 5000;
	int round = 1;

	GameContext(int sizex = 800, int sizey = 600);
	//gegner platzieren
	void enemiesSetup();
	//Spielbrett cyceln, BENUTZEN
	void refresh();
	//distanz zweier pkt
	float dist(const sf::Vector2f & v1, const sf::Vector2f & v2) const;
	//player attackieren
	void refreshEnemies();
	void refreshPlayer();
	//out of bound zeug löschen
	void scatterCleanup();
	//ist player auf Bildschirm
	void playerBoundaryCheck();
	//nächste Runde
	void nextRoundCheck();
};
