////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki and Kamil Kwaśnik.
// Copyright © 2018 Kornel Domeradzki and Kamil Kwaśnik. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "DiagramState.hpp"

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    DiagramState::DiagramState(GameDataRef data) : _data(data)
    {

    }

    ////////////////////////////////////////////////////////////
    void DiagramState::Init()
    {
        this->_data->assets.LoadFont("mainFont", "assets/fonts/SF Pro/SF-Pro-Display-Light.otf");
        this->_diagramGrid = std::make_unique<DiagramGrid>(this->_data);
        this->_functionGraph = std::make_unique<FunctionGraph>(this->_data, -20, 20);
    }

    ////////////////////////////////////////////////////////////
    void DiagramState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                this->_data->window.close();

        }
    }

    ////////////////////////////////////////////////////////////
    void DiagramState::Update(float dt)
    {
    }

    ////////////////////////////////////////////////////////////
    void DiagramState::Draw(float dt)
    {
        this->_data->window.clear(sf::Color::White);

        this->_data->window.draw(*this->_diagramGrid);

        this->_data->window.draw(*this->_functionGraph);

        this->_data->window.display();
    }
}
