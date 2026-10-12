#include "Engine.hpp"
#include <iostream>

namespace TextAdventure {

    Engine::Engine() : m_isRunning(false), m_currentNodeId("") {
    }

    void Engine::initialize() {
        m_isRunning = true;
        m_currentNodeId = "";
    }

    void Engine::loadStory(const std::string& filepath) {
    }

    void Engine::update() {
    }

    void Engine::processInput(int choiceIndex) {
    }

}