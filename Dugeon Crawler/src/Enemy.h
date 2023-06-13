#pragma once
#include "Actor.h"

class Enemy : public Actor
{
public:
	enum EnemySize
	{
		None = 0, Small = 1, Medium = 2, Big = 3, Boss = 4
	};

private:
	EnemySize enemySize;

public:
	Enemy();
	Enemy(const std::string&, const int&, const int&, const EnemySize&);

	const int& GetEnemySize()const;
	
	Enemy& operator=(const Enemy& other)
	{
		if (this != &other)
		{
			this->actorName = other.actorName;
			this->currentHealth = other.currentHealth;
			this->maxHealth = other.maxHealth;
			this->damage = other.damage;
			this->isDead = other.isDead;
			this->enemySize = other.enemySize;
		}
		return *this;
	}
};

