#include <iostream>
#include <string>

int main()
{
    std::string userName;
    int numberOfEnemies;

    std::cout << "Type your name: ";
    std::cin >> userName;

    std::cout << "Hello " << userName << "!" << std::endl << "How many enemies you want to face?" << std::endl;
    std::cin >> numberOfEnemies;
}