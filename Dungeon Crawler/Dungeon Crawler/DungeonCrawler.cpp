#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "RandomizerUtils.h"
#include "Enemy.h"
#include "Character.h"

std::vector<Enemy> CreateEnemies(int numberOfEnemies) {
    std::vector<Enemy> enemies = std::vector<Enemy>();
    for (int i = 0; i < numberOfEnemies; i++)
    {
        Enemy enemy = CreateEnemy();
        //std::cout << "Enemy: " << enemy.GetDamage() << ", " << enemy.GetHealth() << ", " << enemy.GetSize() << std::endl;
        enemies.push_back(enemy);
    }
    return enemies;
}

bool CharacterAttacksEnemy(Enemy& enemy, int damage) {
    enemy.TakeDamage(damage);
    std::cout << "[Character] attacks [enemy], now has health: " << enemy.GetHealth() << std::endl;
    if (enemy.GetHealth() <= 0) {
        return true;
    }
    return false;
}

bool EnemyAttacksCharacter(Character& character, int damage) {
    character.TakeDamage(damage);
    std::cout << "[Enemy] attacks [" << character.GetName() << "], now has health :" << character.GetHealth() << std::endl;
    if (character.GetHealth() <= 0) {
        return true;
    }
    return false;
}

void Battle(Character& character, Enemy& enemy) {
    int startingTurn = RandomizeMinMax(0, 1);

    while (enemy.GetHealth() > 0) {
        if (startingTurn == 0) {
            if (CharacterAttacksEnemy(enemy, character.GetDamage())) {
                return;
            }
            if (EnemyAttacksCharacter(character, enemy.GetDamage())) {
                return;
            }
        }
        else {
            if (EnemyAttacksCharacter(character, enemy.GetDamage())) {
                return;
            }
            if (CharacterAttacksEnemy(enemy, character.GetDamage())) {
                return;
            }
        }
    }
}



void FinishCombat(bool win) {
    if (win) {
        std::cout << "You Win!" << std::endl;
    }
    else {
        std::cout << "You Lose!" << std::endl;
    }
}

void StartDungeon(Character& character, std::vector<Enemy>& enemies) {
    for (int i = 0; i < enemies.size(); i++)
    {
        std::cout << "Enemy " << i << " ---VS--- " << character.GetName() << std::endl;
        Battle(character, enemies[i]);
        if (character.GetHealth() <= 0) {
            FinishCombat(false);
            return;
        }
    }
    FinishCombat(true);
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

    StartDungeon(character, enemies);
}

