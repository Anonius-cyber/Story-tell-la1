#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "GameTypes.hpp"

// ============================================================
//  Desenatorul (Renderer)
// ============================================================
// Responsabilitate unica: afiseaza pe ecran (consola) scenele,
// optiunile, inventarul si mesajele jocului. Nu modifica starea
// jocului si nu citeste input de la jucator.
class Renderer {
public:
    void drawTitle(const std::string& gameTitle) const {
        std::cout << "==============================================\n";
        std::cout << "   " << gameTitle << "\n";
        std::cout << "==============================================\n\n";
    }

    void drawScene(const Scene& scene) const {
        std::cout << "\n--- " << scene.title << " ---\n";
        std::cout << scene.description << "\n\n";

        if (!scene.isEnding) {
            for (size_t i = 0; i < scene.choices.size(); ++i) {
                std::cout << "  " << (i + 1) << ". " << scene.choices[i].text << "\n";
            }
        }
    }

    void drawInventory(const std::vector<Item>& items) const {
        std::cout << "\n[Inventar]\n";
        if (items.empty()) {
            std::cout << "  (gol)\n";
            return;
        }
        for (const auto& item : items) {
            std::cout << "  - " << item.name << ": " << item.description << "\n";
        }
    }

    void drawHelp() const {
        std::cout << "\n[Ajutor]\n"
                  << "  - Scrie numarul optiunii dorite si apasa Enter.\n"
                  << "  - 'inv'  -> afiseaza inventarul curent\n"
                  << "  - 'help' -> afiseaza acest mesaj\n"
                  << "  - 'quit' -> iese din joc\n";
    }

    void drawMessage(const std::string& message) const {
        std::cout << "\n" << message << "\n";
    }

    void drawGameOver(const std::string& endingText) const {
        std::cout << "\n==============================================\n";
        std::cout << endingText << "\n";
        std::cout << "==============================================\n";
        std::cout << "Multumim ca ai jucat!\n";
    }
};
