#include "Character.h"

Character::Character(const std::string& Name, const int& MaxHealth, const int& Damage) :
	Actor(Name, MaxHealth, Damage)
{
    smallEnemiesKilled = 0;
    mediumEnemiesKilled = 0;
    bigEnemiesKilled = 0;
    bossEnemiesKilled = 0;
}

void Character::AddEnemyKillCount(const int& enemySize)
{
    switch (enemySize)
    {
    case 1:
        smallEnemiesKilled++;
        break;
    case 2:
        mediumEnemiesKilled++;
        break;
    case 3:
        bigEnemiesKilled++;
        break;
    case 4:
        bossEnemiesKilled++;
        break;
    default:
        break;
    }
}

void Character::ShowKills()
{
    std::cout << "Enemies Slain :\n"; 
    std::cout << "Small: " << smallEnemiesKilled <<"\n";
    std::cout << "Medium: " << mediumEnemiesKilled <<"\n";
    std::cout << "Big: " << bigEnemiesKilled <<"\n";
    std::cout << "Boss: " << bossEnemiesKilled <<"\n";
}