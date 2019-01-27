////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <fstream>
#include <memory>
#include <string>
#include <SFML/Graphics.hpp>
#include "StateMachine.hpp"
#include "AssetManager.hpp"
#include "User Input Module/InputManager.hpp"
#include "../DEFINITIONS.h"

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    /// \brief Contains all of the important game settings
    ///
    ////////////////////////////////////////////////////////////
    struct GameSettings
    {
        unsigned int width, height;
        unsigned int master_vol, sfx_vol, music_vol;
    };

    ////////////////////////////////////////////////////////////
    /// \brief Contains the game essentials
    ///
    ////////////////////////////////////////////////////////////
    struct GameData
    {
        StateMachine machine;
        sf::RenderWindow window;
        sf::Clock gameClock;
        AssetManager assets;
        InputManager input;
        GameSettings settings;
		GraphType graphType;
    };

    typedef std::shared_ptr<GameData> GameDataRef;  ///< Definition of shared pointer to the GameData struct

    ////////////////////////////////////////////////////////////
    /// \brief The whole game runs inside of this class
    ///
    ////////////////////////////////////////////////////////////
    class App
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param std::string title of the window
        ///
        ////////////////////////////////////////////////////////////
        App(std::string title, int fromX, int fromY, GraphType graphType);

        ////////////////////////////////////////////////////////////
        /// \brief Loads the settings from the given file
        ///
        /// \param std::string settingsFilePath path to the file
        ///
        ////////////////////////////////////////////////////////////
        void LoadGamesSettings(std::string settingsFilePath);

    private:
        ////////////////////////////////////////////////////////////
        /// \brief Runs the game
        ///
        ////////////////////////////////////////////////////////////
        void Run();

        ////////////////////////////////////////////////////////////
        // Member data
        ////////////////////////////////////////////////////////////
        const float dt = 1.0f / 60.0f;  ///< Delta time

        // TODO: Is this clock redundant due to the clock in GameDataRef?
        sf::Clock _clock;   ///< Game's clock

        GameDataRef _data = std::make_shared<GameData>();   ///< Pointer to the GameData
    };
}
