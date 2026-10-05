#pragma once
#include "Engine.hpp"
#include <string>

namespace TextAdventure {

    class Renderer {
    public:
        Renderer() = default;
        ~Renderer() = default;

        void renderScene(const StoryNode& node) const;
        void renderMessage(const std::string& message) const;
        void clearScreen() const;
        void renderGameOver() const;
    };

}