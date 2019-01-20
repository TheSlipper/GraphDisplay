////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
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
        this->_functionGraph = std::make_unique<Fibonacci>(this->_data);
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
