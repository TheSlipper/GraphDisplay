////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../../App Engine/App.hpp"
#include "../../DEFINITIONS.h"
#include <SFML/Graphics.hpp>

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    /// \brief DiagramState class
    ///
    ////////////////////////////////////////////////////////////
    class DiagramGrid : public sf::Drawable
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief DiagramState constructor
        ///
        ////////////////////////////////////////////////////////////
        DiagramGrid(GameDataRef data);

    private:
        void centerObjects();

        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

        sf::RectangleShape verticalLine;

        sf::RectangleShape horizontalLine;

		sf::RectangleShape verticalIndicator;

		sf::RectangleShape horizontalIndicator;

        sf::Text x;

        sf::Text y;

        GameDataRef _data;
    };
}