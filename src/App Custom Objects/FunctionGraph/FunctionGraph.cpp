////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "FunctionGraph.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	FunctionGraph::FunctionGraph(GameDataRef data) :_data(data)
    {
		this->time.setFont(this->_data->assets.GetFont(MAIN_FONT_NAME));
		this->time.setFillColor(sf::Color::Black);
    }

	////////////////////////////////////////////////////////////
	void FunctionGraph::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
		target.draw(this->time);
        for (unsigned int i = 0; i < vertexArray.getVertexCount(); i++)
            target.draw(&vertexArray[i], 4, sf::Lines);
    }
}