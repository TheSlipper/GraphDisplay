////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "NWD.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	NWD::NWD(GameDataRef data) :FunctionGraph(data)
	{
		this->elapsedTimes = new float[ARRAY_SIZE + 1];
		this->vertexArray = sf::VertexArray(sf::Lines, ARRAY_SIZE + 1);
		// this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void NWD::ArrayInit(bool usingCpp)
	{
		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds();
		srand(69);
		for (int i = 1; i <= ARRAY_SIZE; i++)
		{
			int a = abs(rand()), b = abs(rand());
			float helper = this->_data->gameClock.getElapsedTime().asSeconds();
			if (usingCpp)
				this->NWDFunc(a,b);
			else
				this->NWDFuncMasm(a,b);
			float end_t = this->_data->gameClock.getElapsedTime().asSeconds() - helper;
			this->elapsedTimes[i - 1] = end_t;

			std::cout << "Calculated f(" << i << "), took " << end_t << "s" << std::endl;

			this->vertexArray[i - 1] = sf::Vector2f((SCRWIDTH / 2.0f) + (i * WIDTH_MULTIPLIER),
				(SCRHEIGHT / 2.0f) - (this->elapsedTimes[i - 1] * HEIGHT_MULTIPLIER));
			if (usingCpp) this->vertexArray[i - 1].color = sf::Color::Blue;
			else this->vertexArray[i - 1].color = sf::Color::Green;
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
	int NWD::NWDFunc(int a, int b)
	{
		if (a != b)
			return this->NWDFunc(a > b ? a - b : a, b > a ? b - a : b);
		return a;
	}

	////////////////////////////////////////////////////////////
	int NWD::NWDFuncMasm(int a, int b)
	{
		_asm 
		{
			MOV EAX, a
			MOV EBX, b
			algorithm:
				CMP EAX, EBX
				JE end
				JA delBfromA
					SUB EBX, EAX
					JMP algorithm
				delBFromA:
					SUB EAX, EBX
					jmp algorithm
			end:
		}
	}
}