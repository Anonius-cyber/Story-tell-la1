#pragma once

#include <string>

namespace TextAdventure {

    class Listener {
    public:
        Listener() = default;
        ~Listener() = default;

        int getChoiceInput(int maxChoices) const;
        std::string getCommandInput() const;
    };

}