#include <iostream>
#include <string>
#include <vector>
#include "Enemy.h"
#include "Character.h"

std::vector<Enemy> CreateEnemies(int numberOfEnemies) {
    std::vector<Enemy> enemies = std::vector<Enemy>();
    for (int i = 0; i < numberOfEnemies; i++)
    {
        Enemy enemy = CreateEnemy();
        std::cout << "Enemy: " << enemy.GetDamage() << ", " << enemy.GetHealth() << ", " << enemy.GetSize() << std::endl;
        enemies.push_back(enemy);
    }
    return enemies;
}

int main()
{
    std::string userName;
    int numberOfEnemies;

    std::cout << "Type your name: ";
    std::cin >> userName;

    std::cout << "Hello " << userName << "!" << std::endl << "How many enemies you want to face?" << std::endl;
    std::cin >> numberOfEnemies;

    Character character = Character(userName);

    std::vector<Enemy> enemies = CreateEnemies(numberOfEnemies);
}