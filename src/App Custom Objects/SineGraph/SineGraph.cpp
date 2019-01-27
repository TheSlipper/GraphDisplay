////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "SineGraph.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	SineGraph::SineGraph(GameDataRef data) :FunctionGraph(data)
	{
		this->elapsedTimes = new float[ARRAY_SIZE + 1];
		this->vertexArray = sf::VertexArray(sf::Lines, ARRAY_SIZE + 1);
		// this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void SineGraph::ArrayInit(bool usingCpp)
	{
		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds();
		int j = 1;
		for (int i = -300; i <= ARRAY_SIZE-300; i++)
		{
			float helper = this->_data->gameClock.getElapsedTime().asSeconds();
			if (usingCpp)
				this->SineFunc(i);
			else
				this->SineFuncMASM(i);
			float end_t = this->_data->gameClock.getElapsedTime().asSeconds() - helper;
			this->elapsedTimes[j - 1] = end_t;

			std::cout << "Calculated f(" << i << "), took " << end_t << "s" << std::endl;

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
			this->time.setString("[C++] Time spent to calculate: " + std::to_string(this->calcTime) + "s");
			this->time.setPosition(10, 30);
		}
		else
		{
			this->time.setString("[ASM] Time spent to calculate: " + std::to_string(this->calcTime) + "s");
			this->time.setPosition(10, 80);
		}
	}

	////////////////////////////////////////////////////////////
	float SineGraph::SineFunc(int n)
	{
		return sin(n);
	}

	////////////////////////////////////////////////////////////
	float SineGraph::SineFuncMASM(int n)
	{
		float placeholder;
		_asm 
		{
			fld n
			fsin
			fstp placeholder
		}
		return placeholder;
	}
}