#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace TextAdventure {

    struct Choice {
        std::string optionText; 
        std::string nextNodeId; 
    };

    struct StoryNode {
        std::string id;                  
        std::string description;      
        std::vector<Choice> choices;   
        bool isEnding = false;          
    };

    class Engine {
    public:
        Engine();
        ~Engine() = default;

        void initialize();
        void loadStory(const std::string& filepath);
        void update();
        void processInput(int choiceIndex);

        bool isRunning() const { return m_isRunning; }
        const StoryNode& getCurrentNode() const { return m_nodes.at(m_currentNodeId); }

    private:
        std::unordered_map<std::string, StoryNode> m_nodes;
        std::string m_currentNodeId;
        bool m_isRunning;
    };

}