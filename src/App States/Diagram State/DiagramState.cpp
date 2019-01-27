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
        this->_data->assets.LoadFont(MAIN_FONT_NAME, MAIN_FONT_PATH);

		this->_diagramGrid = std::make_unique<DiagramGrid>(this->_data);

		switch (this->_data->graphType)
		{
		case GraphType::Fibonacci:
			this->_functionGraphCpp = std::make_unique<Fibonacci>(this->_data);
			this->_functionGraphMASM = std::make_unique<Fibonacci>(this->_data);
			this->_functionGraphCpp->ArrayInit(true);
			this->_functionGraphMASM->ArrayInit(false);
			break;
		case GraphType::NWD:
			this->_functionGraphCpp = std::make_unique<NWD>(this->_data);
			this->_functionGraphMASM = std::make_unique<NWD>(this->_data);
			this->_functionGraphCpp->ArrayInit(true);
			this->_functionGraphMASM->ArrayInit(false);
			break;
		case GraphType::Sine:
			this->_functionGraphCpp = std::make_unique<SineGraph>(this->_data);
			this->_functionGraphMASM = std::make_unique<SineGraph>(this->_data);
			this->_functionGraphCpp->ArrayInit(true);
			this->_functionGraphMASM->ArrayInit(false);
			break;
		case GraphType::Tan:
			this->_functionGraphCpp = std::make_unique<TanGraph>(this->_data);
			this->_functionGraphMASM = std::make_unique<TanGraph>(this->_data);
			this->_functionGraphCpp->ArrayInit(true);
			this->_functionGraphMASM->ArrayInit(false);
		default:
			this->_functionGraphCpp = std::make_unique<Fibonacci>(this->_data);
			this->_functionGraphMASM = std::make_unique<Fibonacci>(this->_data);
			break;
		}

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

        this->_data->window.draw(*this->_functionGraphCpp);

		this->_data->window.draw(*this->_functionGraphMASM);

        this->_data->window.display();
    }
}
