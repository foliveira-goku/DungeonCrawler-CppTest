#pragma once
#include "Actor.h"

class Character : public Actor
{
private:
	int smallEnemiesKilled;
	int mediumEnemiesKilled;
	int bigEnemiesKilled;
	int bossEnemiesKilled;

public:
	Character(const std::string&, const int&, const int&);

	void AddEnemyKillCount(const int&);

	void ShowKills();
};