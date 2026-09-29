#include <iostream>
#include "Engine.hpp"
#include "Renderer.hpp"
#include "Listener.hpp"

int main() {
    TextAdventure::Engine gameEngine;
    TextAdventure::Renderer renderer;
    TextAdventure::Listener listener;

    std::cout << "Story Tale Game Initialized successfully!\n";

    return 0;
}