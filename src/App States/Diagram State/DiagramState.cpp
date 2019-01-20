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
        this->_functionGraphCpp = std::make_unique<Fibonacci>(this->_data);
		this->_functionGraphMASM = std::make_unique<Fibonacci>(this->_data);
		this->_functionGraphCpp->ArrayInit(true);
		this->_functionGraphMASM->ArrayInit(false);
    }

    ////////////////////////////////////////////////////////////
    void DiagramState::HandleInput()
    {
        sf::Event event;

        while (this->_data->window.pollEvent(event))
        {
            if (sf::Event::Closed == event.type)
                this->_data->window.close();
			else if (event.type == sf::Event::KeyPressed && this->_data->window.hasFocus())
			{
				this->_functionGraphCpp = std::make_unique<BubbleSorting>(this->_data);
				this->_functionGraphMASM = std::make_unique<BubbleSorting>(this->_data);
				this->_functionGraphCpp->ArrayInit(true);
			}
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

        this->_data->window.draw(*this->_functionGraphCpp);

		this->_data->window.draw(*this->_functionGraphMASM);

        this->_data->window.display();
    }
}
