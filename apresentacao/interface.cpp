#include <iostream>
#include <string>
#include "../entidade.h"
#include
#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

class START_SCEEN {
public:
    void run() {
        std::string command;
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, command);
            if (command == "exit") {
                clearScreen();
                break;
            } else {
                std::cout << "You entered: " << command << std::endl;
            }
        }
    }

private:
    void clearScreen() {
#ifdef _WIN32
        // Windows
        system("cls");
#else
        // Linux and macOS
        system("clear");
#endif
    }
};

class CONFIG_VIAGEM
{
private:
    std::string Filepath;
    VIAGEM viagem;
    void clearScreen() {
#ifdef _WIN32
        // Windows
        system("cls");
#else
        // Linux and macOS
        system("clear");
#endif
    }
public:
    CONFIG_VIAGEM(string nome);
    void run();
    ~CONFIG_VIAGEM();
};

CONFIG_VIAGEM::CONFIG_VIAGEM(/* args */)
{
    db=dataBase.get(Filepath);
    viagem=db.get_viagem(nome);
}
void CONFIG_VIAGEM::run(){
    std::string command;
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, command);
        if (command == "exit") {
            clearScreen();
            break;
        } else {
            std::cout << "You entered: " << command << std::endl;
        }
    }
}
CONFIG_VIAGEM::~CONFIG_VIAGEM()
{
}

