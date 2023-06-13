#pragma once

std::string& GetPlayerName(std::string& charName)
{
    std::cout << "Please type your character's name:\n";

    std::cin >> charName;
    return charName;
}

int& GetNumberOfEnemies(int& numberOfEnemies)
{
    std::cout << "How many enemies do you wanna fight?\n";

    std::cin >> numberOfEnemies;
    return numberOfEnemies;
}

int GetRandomValue(const int& min, const int& max) { return min + (std::rand() % (max - min + 1)); }

int GetRandomHealth(const Enemy::EnemySize& enemySize)
{
    switch (enemySize)
    {
    case Enemy::Small:
        return GetRandomValue(1, 4);
    case Enemy::Medium:
        return GetRandomValue(4, 7);
    case Enemy::Big:
        return GetRandomValue(7, 15);
    case Enemy::Boss:
        return GetRandomValue(20, 40);
    default:
        break;
    }
}

int GetRandomDamage(const Enemy::EnemySize& enemySize)
{
    switch (enemySize)
    {
    case Enemy::Small:
        return GetRandomValue(1, 2);
    case Enemy::Medium:
        return GetRandomValue(2, 3);
    case Enemy::Big:
        return GetRandomValue(3, 4);
    case Enemy::Boss:
        return GetRandomValue(7, 15);
    default:
        break;
    }
}

void CreateEnemies(std::vector<Enemy>& enemies)
{
    int numberOfEnemyes;
    enemies.reserve(GetNumberOfEnemies(numberOfEnemyes));
    int currentAmount = 0;
    std::srand(std::time(0));

    for (int i = 0; i < numberOfEnemyes; i++)
    {
        int randomSize = std::rand() % 4 + 1;
        int randomHealth = GetRandomHealth((Enemy::EnemySize)randomSize);
        int randomDamage = GetRandomDamage((Enemy::EnemySize)randomSize);
        enemies.emplace_back("Enemy " + std::to_string(currentAmount), randomHealth, randomDamage, (Enemy::EnemySize)randomSize);
        currentAmount++;
    }
}

void AttackRandomEnemy(Character& player, std::vector<Enemy>& enemies)
{

    int randomEnemy = std::rand() % enemies.size();

    std::cout << "You have attacked " << enemies[randomEnemy].GetActorName() << "!\n";
    enemies[randomEnemy].TakeDamage(player.GetActorDamage());
    std::cout << "\n";

    if (enemies[randomEnemy].IsDead()) 
    {
        player.AddEnemyKillCount(enemies[randomEnemy].GetEnemySize());
        enemies.erase(enemies.begin() + randomEnemy);
    }
}

void Battle(Character& player, std::vector<Enemy>& enemies)
{
    std::cout << "\n\n\n";
    std::cout << "The battle has began!!!";
    std::cout << "\n\n\n";

    while (true)
    {
        AttackRandomEnemy(player, enemies);

        if (enemies.size() <= 0)
        {
            std::cout << "You won!\n";
            player.ShowKills();
            return;
        }

        for (Enemy enemy : enemies)
        {
            std::cout << "You have been attacked by " << enemy.GetActorName() << "!\n";
            player.TakeDamage(enemy.GetActorDamage());
            std::cout << "\n";

            if (player.IsDead())
            {
                std::cout << "You lost!\n";
                player.ShowKills();
                return;
            }
        }

        std::cout << "Press any key to continue...\n";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
        std::cin.get();
    }
}