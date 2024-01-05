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
        std::cout << "Enemy: " << enemy.GetDamage() << ", " << enemy.GetHealth() << ", " << GetEnumName(enemy.GetSize()) << std::endl;
        enemies.push_back(enemy);
    }
    return enemies;
}

bool CharacterAttacksEnemy(Enemy& enemy, Character& character) {
    enemy.TakeDamage(character.GetDamage());
    std::cout << "[" << character.GetName() << "] attacks [enemy]" << std::endl;
    std::cout << "[enemy] Health: " << enemy.GetHealth() << std::endl;
    if (enemy.GetHealth() <= 0) {
        return true;
    }
    return false;
}

bool EnemyAttacksCharacter(Character& character, int damage) {
    character.TakeDamage(damage);
    std::cout << "[Enemy] attacks [" << character.GetName() << "]" << std::endl;
    std::cout << "[" << character.GetName() << "] Health: " << character.GetHealth() << std::endl;
    if (character.GetHealth() <= 0) {
        return true;
    }
    return false;
}

void Battle(Character& character, Enemy& enemy) {
    int startingTurn = RandomizeMinMax(0, 1);

    while (enemy.GetHealth() > 0) {
        std::cout << std::endl;
        if (startingTurn == 0) {
            if (CharacterAttacksEnemy(enemy, character)) {
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
            if (CharacterAttacksEnemy(enemy, character)) {
                return;
            }
        }
    }
}

void FinishCombat(bool win, std::map<Sizes, int>& enemiesKilled) {
    std::cout << std::endl;
    if (win) {
        std::cout << "You Win!" << std::endl;
    }
    else {
        std::cout << "You Lose!" << std::endl;
    }
    std::cout << "Enemies Slain:" << std::endl;
    std::map<Sizes, int>::iterator it;
    for (it = enemiesKilled.begin(); it != enemiesKilled.end(); it++)
    {
        std::cout << GetEnumName(it->first)   // string (key)
            << ':'
            << it->second   // string's value 
            << std::endl;
    }
}

void StartDungeon(Character& character, std::vector<Enemy>& enemies) {
    std::map<Sizes, int> enemiesKilled{{Sizes::Small, 0}, {Sizes::Medium, 0}, {Sizes::Big, 0} };
    for (int i = 0; i < enemies.size(); i++)
    {
        std::cout << std::endl << "Enemy " << i << " ---VS--- " << character.GetName() << std::endl;
        Battle(character, enemies[i]);
        if (character.GetHealth() <= 0) {
            FinishCombat(false, enemiesKilled);
            return;
        }
        enemiesKilled[enemies[i].GetSize()]++;
    }
    FinishCombat(true, enemiesKilled);
}




int main()
{
    std::string userName;
    int numberOfEnemies;
    
    std::cout << "Type your name: ";
    std::cin >> userName;

    std::cout << "Hello " << userName << "!" << std::endl << "How many enemies you want to face?" << std::endl;
    std::cin >> numberOfEnemies;

    srand(time(0));

    Character character = Character(userName);

    std::vector<Enemy> enemies = CreateEnemies(numberOfEnemies);

    StartDungeon(character, enemies);
}

