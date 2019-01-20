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
#include <iostream>


namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    /// \brief DiagramState class
    ///
    ////////////////////////////////////////////////////////////
    class FunctionGraph : public sf::Drawable
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief DiagramState constructor
        ///
        ////////////////////////////////////////////////////////////
		FunctionGraph(GameDataRef data);

		////////////////////////////////////////////////////////////
		/// \brief Sets the vertexArray arguments' coordinates
		///
		////////////////////////////////////////////////////////////
		virtual void ArrayInit(bool usingCpp) = 0;

    protected:
        ////////////////////////////////////////////////////////////
        /// \brief Draws the graph
        ///
        ////////////////////////////////////////////////////////////
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		int amplitude;

        sf::VertexArray vertexArray;

        GameDataRef _data;
    };
}