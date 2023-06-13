#include "Enemy.h"

Enemy::Enemy():	enemySize(Enemy::Small){}

Enemy::Enemy(const std::string& Name, const int& MaxHealth, const int& Damage, const EnemySize& Size) :
	Actor(Name, MaxHealth, Damage), enemySize(Size) 
{
	std::cout << " Size: " << enemySize << "\n";
}

const int& Enemy::GetEnemySize()const {	return enemySize; }