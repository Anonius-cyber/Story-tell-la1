#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "GameTypes.hpp"
#include "Renderer.hpp"
#include "Listener.hpp"

// ============================================================
//  Motorul de joc (GameEngine)
// ============================================================
// Responsabilitate: detine povestea (scenele + obiectele),
// detine starea curenta a jucatorului si coordoneaza bucla
// principala a jocului, folosind Renderer pentru afisare si
// Listener pentru citirea alegerilor jucatorului.
class GameEngine {
public:
    GameEngine() {
        buildStory();
    }

    void run() {
        renderer.drawTitle("Insula Uitata - Text Adventure");

        while (state.isRunning) {
            const Scene& scene = currentScene();
            renderer.drawScene(scene);

            if (scene.isEnding) {
                renderer.drawGameOver(scene.description);
                state.isRunning = false;
                break;
            }

            PlayerCommand cmd = listener.getPlayerInput(
                static_cast<int>(scene.choices.size()));

            switch (cmd.type) {
                case CommandType::Choice:
                    handleChoice(scene.choices[cmd.choiceIndex - 1]);
                    break;
                case CommandType::ShowInventory:
                    renderer.drawInventory(getInventoryItems());
                    break;
                case CommandType::ShowHelp:
                    renderer.drawHelp();
                    break;
                case CommandType::Quit:
                    renderer.drawMessage("Ai iesit din joc. La revedere!");
                    state.isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }

private:
    std::map<int, Scene> scenes;
    std::map<int, Item> items;
    GameState state;
    Renderer renderer;
    Listener listener;

    const Scene& currentScene() const {
        return scenes.at(state.currentSceneId);
    }

    bool hasItem(int itemId) const {
        for (int id : state.inventory) {
            if (id == itemId) return true;
        }
        return false;
    }

    std::vector<Item> getInventoryItems() const {
        std::vector<Item> result;
        for (int id : state.inventory) {
            auto it = items.find(id);
            if (it != items.end()) result.push_back(it->second);
        }
        return result;
    }

    void handleChoice(const Choice& choice) {
        if (choice.requiredItemId != -1 && !hasItem(choice.requiredItemId)) {
            renderer.drawMessage("Ai nevoie de \"" +
                items.at(choice.requiredItemId).name +
                "\" pentru aceasta alegere.");
            return;
        }

        if (choice.givesItemId != -1 && !hasItem(choice.givesItemId)) {
            state.inventory.push_back(choice.givesItemId);
            renderer.drawMessage("Ai primit: " + items.at(choice.givesItemId).name);
        }

        if (!choice.setFlag.empty()) {
            state.flags[choice.setFlag] = true;
        }

        state.currentSceneId = choice.targetSceneId;
        state.turnCount++;
    }

    // Contine toata povestea, hardcodata pentru acest laborator.
    // Poate fi usor mutata intr-un fisier extern (JSON/txt) intr-o
    // versiune ulterioara a proiectului.
    void buildStory() {
        items[1] = { 1, "Cutit ruginit", "Un cutit vechi, dar inca ascutit." };
        items[2] = { 2, "Harta insulei", "O harta rupta, cu o zona marcata cu X." };
        items[3] = { 3, "Oglinda de semnalizare", "Poate fi folosita pentru a semnaliza o nava." };

        scenes[0] = {
            0, "Naufragiul",
            "Te trezesti pe o plaja necunoscuta. Corabia ta a fost distrusa de furtuna. "
            "In fata ta se intinde o padure deasa, iar la stanga vezi niste stanci abrupte.",
            {
                { "Intra in padure", 1 },
                { "Exploreaza stancile", 2 }
            }
        };

        scenes[1] = {
            1, "Padurea",
            "Padurea este linistita. Gasesti un cutit ruginit langa un copac cazut.",
            {
                { "Ia cutitul si mergi mai departe", 3, -1, 1 },
                { "Ignora cutitul si mergi mai departe", 3 }
            }
        };

        scenes[2] = {
            2, "Stancile",
            "Printre pietre gasesti o harta veche a insulei, pe jumatate distrusa de apa.",
            {
                { "Ia harta si intoarce-te pe plaja", 3, -1, 2 },
                { "Continua sa cauti printre stanci", 4 }
            }
        };

        scenes[3] = {
            3, "Rascruce",
            "Ajungi la o rascruce: un drum duce spre munte, altul spre o pestera intunecata.",
            {
                { "Mergi spre munte", 5 },
                { "Intra in pestera", 6 }
            }
        };

        scenes[4] = {
            4, "Grota ascunsa",
            "Gasesti o grota ascunsa cu o oglinda veche de semnalizare.",
            {
                { "Ia oglinda si intoarce-te la rascruce", 3, -1, 3 }
            }
        };

        scenes[5] = {
            5, "Varful muntelui",
            "De pe varf poti semnaliza spre orizont, daca ai o oglinda de semnalizare.",
            {
                { "Semnalizeaza spre o nava indepartata", 7, 3 },
                { "Coboara inapoi la rascruce", 3 }
            }
        };

        scenes[6] = {
            6, "Pestera intunecata",
            "In pestera, lumina slaba scoate la iveala niste simboluri stravechi pe perete. "
            "Fara harta insulei, e greu sa intelegi ce inseamna.",
            {
                { "Foloseste harta pentru a descifra simbolurile", 8, 2 },
                { "Iesi din pestera inapoi la rascruce", 3 }
            }
        };

        scenes[7] = {
            7, "Final: Salvare",
            "O nava iti observa semnalul si se apropie de tarm. Esti salvat! FINAL BUN.",
            {},
            true
        };

        scenes[8] = {
            8, "Final: Comoara ascunsa",
            "Simbolurile dezvaluie locul unei comori vechi, ascunse de un cautator de comori "
            "naufragiat cu mult timp in urma. Ai gasit un tezaur... dar tot esti blocat pe insula. "
            "FINAL SECRET.",
            {},
            true
        };

        state.currentSceneId = 0;
    }
};
