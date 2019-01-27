////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "TanGraph.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	TanGraph::TanGraph(GameDataRef data) :FunctionGraph(data)
	{
		this->elapsedTimes = new float[ARRAY_SIZE + 1];
		this->vertexArray = sf::VertexArray(sf::Lines, ARRAY_SIZE + 1);
		// this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void TanGraph::ArrayInit(bool usingCpp)
	{
		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds();
		int j = 1;
		for (int i = -300; i <= ARRAY_SIZE - 300; i++)
		{
			float helper = this->_data->gameClock.getElapsedTime().asSeconds();
			if (usingCpp && i % 90 != 0)
				this->TanFunc(i);
			else if (i % 90 != 0)
				this->TanFuncMASM(i);
			float end_t = this->_data->gameClock.getElapsedTime().asSeconds() - helper;
			this->elapsedTimes[j - 1] = end_t;

			this->vertexArray[j - 1] = sf::Vector2f((SCRWIDTH / 2.0f) + (i * WIDTH_MULTIPLIER),
				(SCRHEIGHT / 2.0f) - (this->elapsedTimes[j - 1] * HEIGHT_MULTIPLIER));
			if (usingCpp) this->vertexArray[j - 1].color = sf::Color::Blue;
			else this->vertexArray[j - 1].color = sf::Color::Green;
			j++;
		}
		this->vertexArray[this->vertexArray.getVertexCount() - 1] = this->vertexArray[this->vertexArray.getVertexCount() - 2];
		this->vertexArray[this->vertexArray.getVertexCount() - 1].color = sf::Color::White;

		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds() - this->calcTime;
		if (usingCpp)
		{
			this->time.setFillColor(sf::Color::Blue);
			this->time.setString("[C++] Time spent to calculate: " + std::to_string(this->calcTime) + "s");
			this->time.setPosition(10, 30);
		}
		else
		{
			this->time.setFillColor(sf::Color::Green);
			this->time.setString("[ASM] Time spent to calculate: " + std::to_string(this->calcTime) + "s");
			this->time.setPosition(10, 80);
		}
	}

	////////////////////////////////////////////////////////////
	float TanGraph::TanFunc(int n)
	{
		return tan(n);
	}

	////////////////////////////////////////////////////////////
	float TanGraph::TanFuncMASM(int n)
	{
		float placeholder;
		_asm
		{
			fld n
			fptan
			fstp placeholder
		}
		return placeholder;
	}
}