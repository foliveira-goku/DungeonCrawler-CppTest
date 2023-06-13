#pragma once
#include <iostream>
#include <string>

class Actor
{
protected:
	std::string actorName;
	int currentHealth;
	int maxHealth;
	int damage;
	bool isDead = false;

public:
	Actor();
	Actor(const std::string&, const int&, const int&);
	~Actor();

	void TakeDamage(const int&);
	const std::string GetActorName()const;
	const int& GetActorDamage() const;
	const int& GetActorCurrentHealth() const;
	const bool& IsDead() const;
};