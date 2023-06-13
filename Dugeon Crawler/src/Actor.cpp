#include "Actor.h"

Actor::Actor(): 
actorName("Nameless"), maxHealth(100), currentHealth(100), damage(10)
{
}

Actor::Actor(const std::string& Name, const int& MaxHealth, const int& Damage):
	actorName(Name), maxHealth(MaxHealth), currentHealth(MaxHealth), damage(Damage)
{
	std::cout << "An actor has been created: " << actorName << " HP: " << maxHealth << " Damage: " << damage << "\n";
}

Actor::~Actor(){}

void Actor::TakeDamage(const int& amount)
{
	currentHealth -= amount;
	
	std::cout << actorName << " toke " << amount << " of damage. HP: " << currentHealth << "/" << maxHealth << "\n";

	if (currentHealth <= 0)
	{
		std::cout << actorName << " has died. \n";
		isDead = true;
	}
}

const int& Actor::GetActorDamage() const { return damage; }

const std::string Actor::GetActorName() const { return actorName; }

const int& Actor::GetActorCurrentHealth() const { return currentHealth; }

const bool& Actor::IsDead() const { return isDead; }