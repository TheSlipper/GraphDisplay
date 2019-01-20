////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki and Kamil Kwaśnik.
// Copyright © 2018 Kornel Domeradzki and Kamil Kwaśnik. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "DiagramGrid.hpp"

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    DiagramGrid::DiagramGrid(GameDataRef data) :_data(data)
    {
        // Horizontal line
        this->horizontalLine.setSize(sf::Vector2f(SCRWIDTH, 3.0f));
        this->horizontalLine.setFillColor(sf::Color::Black);

        // Vertical line
        this->verticalLine.setSize(sf::Vector2f(3.0f, SCRHEIGHT));
        this->verticalLine.setFillColor(sf::Color::Black);

        // Center lines
        this->centerObjects();

        // X Text
        this->x.setFont(this->_data->assets.GetFont("mainFont"));
        this->x.setString("x");
        this->x.setPosition(SCRWIDTH - this->x.getLocalBounds().width - 20,
                this->horizontalLine.getPosition().y - this->x.getGlobalBounds().height - 30);
        this->x.setFillColor(sf::Color::Black);

        // Y text
        this->y.setString("y");
        this->y.setFont(this->_data->assets.GetFont("mainFont"));
        this->y.setPosition(this->verticalLine.getPosition().x + this->verticalLine.getGlobalBounds().width + 10, 2);
        this->y.setFillColor(sf::Color::Black);
    }

    ////////////////////////////////////////////////////////////
    void DiagramGrid::centerObjects()
    {
        // Horizontal line
        sf::FloatRect horizontalBounds = this->horizontalLine.getLocalBounds();
        this->horizontalLine.setOrigin(horizontalBounds.left + horizontalBounds.width/2.0f, 0);
        this->horizontalLine.setPosition(sf::Vector2f(SCRWIDTH/2.0f, SCRHEIGHT/2.0f));

        // Vertical line
        sf::FloatRect verticalBounds = this->verticalLine.getGlobalBounds();
        this->verticalLine.setOrigin(0,
                                        verticalBounds.top + verticalBounds.height/2.0f);
        this->verticalLine.setPosition(sf::Vector2f(SCRWIDTH/2.0f, SCRHEIGHT/2.0f));
    }

    ////////////////////////////////////////////////////////////
    void DiagramGrid::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        target.draw(this->horizontalLine);
        target.draw(this->verticalLine);
        target.draw(this->x);
        target.draw(this->y);
    }
}