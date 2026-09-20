#pragma once

#include <string>
#include <vector>
#include <map>

// ============================================================
//  Structuri de date de baza pentru "Insula Uitata"
// ============================================================

// Un obiect pe care jucatorul il poate gasi si folosi in poveste.
struct Item {
    int id = -1;
    std::string name;
    std::string description;
};

// O optiune de alegere disponibila intr-o scena.
// targetSceneId indica spre ce scena duce alegerea.
// requiredItemId / givesItemId permit conditionarea si recompensarea
// alegerilor cu obiecte din inventar (-1 = nu se aplica).
struct Choice {
    std::string text;
    int targetSceneId = -1;
    int requiredItemId = -1;
    int givesItemId = -1;
    std::string setFlag;   // daca nu e gol, se seteaza acest flag pe true
};

// O scena (nod) din graful povestii.
struct Scene {
    int id = -1;
    std::string title;
    std::string description;
    std::vector<Choice> choices;
    bool isEnding = false;
};

// Starea curenta a partidei jucatorului.
struct GameState {
    int currentSceneId = 0;
    std::vector<int> inventory;
    std::map<std::string, bool> flags;
    int turnCount = 0;
    bool isRunning = true;
};
