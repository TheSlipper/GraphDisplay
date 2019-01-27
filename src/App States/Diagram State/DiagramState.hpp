////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics.hpp>
#include <cmath>
#include "../State.hpp"
#include "../../App Engine/App.hpp"
#include "../../DEFINITIONS.h"
#include "../../App Custom Objects/DiagramGrid/DiagramGrid.hpp"
#include "../../App Custom Objects/FunctionGraph/FunctionGraph.hpp"
#include "../../App Custom Objects/Fibonacci/Fibonacci.hpp"
#include "../../App Custom Objects/NWD/NWD.hpp"
#include "../../App Custom Objects/SineGraph/SineGraph.hpp"
#include "../../App Custom Objects/TanGraph/TanGraph.hpp"

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    /// \brief DiagramState class
    ///
    ////////////////////////////////////////////////////////////
    class DiagramState : public State
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Default constructor
        ///
        /// \param GameDataRef data pointer to the game's crucial data
        ///
        ////////////////////////////////////////////////////////////
        DiagramState(GameDataRef data);

        ////////////////////////////////////////////////////////////
        /// \brief Initialization of the state
        ///
        ////////////////////////////////////////////////////////////
        void Init();

        ////////////////////////////////////////////////////////////
        /// \brief Handles scene-specific user input
        ///
        ////////////////////////////////////////////////////////////
        void HandleInput();

        ////////////////////////////////////////////////////////////
        /// \brief Updates the scene (call the animation or physics
        ///         methods here)
        ///
        ////////////////////////////////////////////////////////////
        void Update(float dt);

        ////////////////////////////////////////////////////////////
        /// \brief Draws to the screen
        ///
        ////////////////////////////////////////////////////////////
        void Draw(float dt);

    private:
        std::unique_ptr<DiagramGrid> _diagramGrid;

        std::unique_ptr<FunctionGraph> _functionGraphCpp;

		std::unique_ptr<FunctionGraph> _functionGraphMASM;

        GameDataRef _data;
    };
}
