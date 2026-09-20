#pragma once

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

// Tipurile de comenzi pe care Listener-ul le poate recunoaste
// din ce tasteaza jucatorul.
enum class CommandType {
    Choice,        // jucatorul a ales un numar valid de optiune
    ShowInventory, // comanda "inv" / "inventar"
    ShowHelp,      // comanda "help" / "ajutor"
    Quit,          // comanda "quit" / "exit" / "iesire"
    Invalid        // input nerecunoscut sau in afara intervalului
};

// Rezultatul interpretarii unui input al jucatorului.
struct PlayerCommand {
    CommandType type = CommandType::Invalid;
    int choiceIndex = -1; // valid doar cand type == Choice (indexare de la 1)
};

// ============================================================
//  Ascultatorul de intrare (Listener)
// ============================================================
// Responsabilitate unica: citeste ce tasteaza jucatorul de la
// consola si il transforma intr-o comanda pe care GameEngine
// stie sa o interpreteze. Nu stie nimic despre poveste in sine.
class Listener {
public:
    // maxChoice = numarul de optiuni disponibile in scena curenta
    PlayerCommand getPlayerInput(int maxChoice) const {
        while (true) {
            std::cout << "\n> ";
            std::string raw;
            if (!std::getline(std::cin, raw)) {
                return { CommandType::Quit, -1 };
            }

            std::string normalized = toLower(trim(raw));

            if (normalized == "quit" || normalized == "exit" || normalized == "iesire") {
                return { CommandType::Quit, -1 };
            }
            if (normalized == "inv" || normalized == "inventar" || normalized == "inventory") {
                return { CommandType::ShowInventory, -1 };
            }
            if (normalized == "help" || normalized == "ajutor") {
                return { CommandType::ShowHelp, -1 };
            }

            int value = 0;
            if (parseInt(normalized, value) && value >= 1 && value <= maxChoice) {
                return { CommandType::Choice, value };
            }

            std::cout << "Comanda nu este recunoscuta. Scrie un numar de optiune, "
                      << "'inv', 'help' sau 'quit'.\n";
        }
    }

private:
    static std::string trim(const std::string& s) {
        size_t start = s.find_first_not_of(" \t\r\n");
        size_t end = s.find_last_not_of(" \t\r\n");
        if (start == std::string::npos) return "";
        return s.substr(start, end - start + 1);
    }

    static std::string toLower(std::string s) {
        for (auto& c : s) c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        return s;
    }

    static bool parseInt(const std::string& s, int& out) {
        if (s.empty()) return false;
        std::istringstream iss(s);
        iss >> out;
        return !iss.fail() && iss.eof();
    }
};
