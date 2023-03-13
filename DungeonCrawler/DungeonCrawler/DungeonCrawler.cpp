// DungeonCrawler.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Character.h"
#include "Enemy.h"

//identificadores
void SetPlayerName(std::string& playerName);
void SetEnemyAmount(int& enemiesQuantity);
void Battle(Character& player, std::vector<Enemy>& enemiesList);
int GetRandom(int min, int max);
bool Contains(int enemyId, std::vector<int>& deadEnemiesList);
void GameOver(Character& player, std::vector<Enemy>& enemiesList, int deadEnemis, std::vector<int>& deadEnemiesList);

int main()
{
    //initializing 
    std::string playerName;
    int enemiesQuantity = 0;
    std::vector<Enemy> enemiesList;

    SetPlayerName(playerName);

    //creating player object
    Character player;
    player.name = playerName;
    player.health = static_cast<float>(100); //static_cast converts types safely 
    player.damage = static_cast<float>(GetRandom(2, 10));

    std::cout << "\nCreating player..." << std::endl;
    std::cout << "Player: " << player.name << " | Health: " << player.health << " | Damage: " << player.damage << std::endl;

    //creating enemies
    SetEnemyAmount(enemiesQuantity);

    std::cout << "\nCreated enemies..." << std::endl;
    
    for (int i = 0; i < enemiesQuantity; i++) {
        std::string enemyName = "Enemy " + std::to_string(i);
        float enemyHealth = static_cast<float>(GetRandom(30, 100));
        float enemyDamage = static_cast<float>(GetRandom(2, 10));
        Sizes enemySize = static_cast<Sizes>(GetRandom(0, 3));

        Enemy enemy(i, enemyName, enemyHealth, enemyDamage, enemySize);
        enemiesList.push_back(enemy);

        std::cout << "Enemy: " << enemyName << " | Health: " << enemyHealth << " | Damage: " << enemyDamage << " | Size: " << GetSizeAsString(enemySize) << std::endl;
    }

    Battle(player, enemiesList);
}

void Battle(Character& player, std::vector<Enemy>& enemiesList) {
    int deadEnemies = 0;
    std::vector<int> deadEnemiesList;

    std::cout << "\nLet the games begin!" << std::endl;
    do
    {
        for (Enemy& enemy : enemiesList) {
            if (player.health <= 0) break;
            if (enemy.health <= 0) continue;

            player.Attack(enemy);

            if (enemy.health <= 0 && !Contains(enemy.id, deadEnemiesList)) {
                std::cout << enemy.name << "killed!" << std::endl;
                deadEnemiesList.push_back(enemy.id);
                deadEnemies++;
            }
            else {
                enemy.Attack(player);
            }
        }

    } while (player.health > 0 && deadEnemies != enemiesList.size());

    GameOver(player, enemiesList, deadEnemies, deadEnemiesList);
}

void GameOver(Character& player, std::vector<Enemy>& enemiesList, int deadEnemis, std::vector<int>& deadEnemiesList) {
    std::cout << "\nBattle results...\n" << std::endl;
    if (player.health <= 0) {std::cout << "You lose!" << std::endl;} else {std::cout << "You win!" << std::endl;}

    int smallEnemiesDefeated = 0;
    int mediumEnemiesDefeated = 0;
    int bigEnemiesDefeated = 0;
    int totalSmallEnemies = 0;
    int totalMediumEnemies = 0;
    int totalBigEnemies = 0;

    for (Enemy& enemy : enemiesList) {
        if (enemy.size == Sizes::Small) totalSmallEnemies++;
        if (enemy.size == Sizes::Medium) totalMediumEnemies++;
        if (enemy.size == Sizes::Big) totalBigEnemies++;

        if (enemy.health <= 0 && enemy.size == Sizes::Small) smallEnemiesDefeated++;
        if (enemy.health <= 0 && enemy.size == Sizes::Medium) mediumEnemiesDefeated++;
        if (enemy.health <= 0 && enemy.size == Sizes::Big) bigEnemiesDefeated++;
    }

    std::cout << "Enemies slain:" << std::endl;
    std::cout << "Big:" << smallEnemiesDefeated << "/" << totalBigEnemies << std::endl;
    std::cout << "Medium:" << mediumEnemiesDefeated << "/" << totalMediumEnemies << std::endl;
    std::cout << "Small:" << bigEnemiesDefeated << "/" << totalSmallEnemies << std::endl;
}

// Utils 
int GetRandom(int min, int max) { return (rand() % max) + min; }

bool Contains(int enemyId, std::vector<int>& deadEnemiesList) {
    for (int& id : deadEnemiesList) { if (id == enemyId) return true; }
    return false;
}

void SetPlayerName(std::string& playerName) {
    std::cout << "What's your name? \n";
    std::getline(std::cin, playerName);

    if (playerName.empty()) {
        //Name typed is empty, keep trying a valid name
        std::cout << "Please try a valid name." << std::endl;
        SetPlayerName(playerName);
    }
}

void SetEnemyAmount(int& enemiesQuantity) {
    std::string quantityEntry;

    std::cout << "How many enemies do you wanna face?\n";
    std::getline(std::cin, quantityEntry);

    //entendi porra nenhuma
    std::istringstream entry(quantityEntry);

    if (entry >> enemiesQuantity) {
        std::cout << enemiesQuantity << " enemies will spawn." << std::endl;
    } else {
        //Quantity typed is empty/invalid, keep trying
        std::cout << "Your entry is invalid, please try a integer number." << std::endl;
        SetEnemyAmount(enemiesQuantity);
    }
}