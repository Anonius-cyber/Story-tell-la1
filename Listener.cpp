#include "Listener.hpp"
#include <iostream>

namespace TextAdventure {

    int Listener::getChoiceInput(int maxChoices) const {
        int choice = 0;
        std::cout << "Choose an option (1 - " << maxChoices << "): ";
        std::cin >> choice;
        return choice;
    }

    std::string Listener::getCommandInput() const {
        std::string command;
        std::cin >> command;
        return command;
    }

}