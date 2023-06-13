#include <vector>
#include <ctime>
#include <random>
#include "Actor.h"
#include "Enemy.h"
#include "Character.h"

#include "Functions.h"

int main()
{
    std::cout << "Welcome to Dugeon Crawler!\n";
    
    std::string charName;
    Character player = Character(GetPlayerName(charName), 100, 10);

    std::vector<Enemy> enemies;
    CreateEnemies(enemies);

    Battle(player, enemies);
}