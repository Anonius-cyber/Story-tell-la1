#include "Renderer.hpp"
#include <iostream>
#include <cstdlib>

namespace TextAdventure {

    void Renderer::renderScene(const StoryNode& node) const {
        std::cout << "\n----------------------------------------\n";
        std::cout << node.description << "\n\n";

        for (size_t i = 0; i < node.choices.size(); ++i) {
            std::cout << i + 1 << ". " << node.choices[i].optionText << "\n";
        }
        std::cout << "----------------------------------------\n";
    }

    void Renderer::renderMessage(const std::string& message) const {
        std::cout << message << std::endl;
    }

    void Renderer::clearScreen() const {
        system("cls");
    }

    void Renderer::renderGameOver() const {
        std::cout << "\n=== THE END ===\n";
    }

}