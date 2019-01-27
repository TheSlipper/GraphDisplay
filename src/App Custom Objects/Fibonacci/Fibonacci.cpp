////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "Fibonacci.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	Fibonacci::Fibonacci(GameDataRef data) :FunctionGraph(data)
	{
		this->elapsedTimes = new float[ARRAY_SIZE+1];
		this->vertexArray = sf::VertexArray(sf::Lines, ARRAY_SIZE+1);
		// this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void Fibonacci::ArrayInit(bool usingCpp)
	{
		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds();
		for (int i = 1; i <= ARRAY_SIZE; i++)
		{
			float helper = this->_data->gameClock.getElapsedTime().asSeconds();
			if (usingCpp)
				this->FibonacciFunc(i);
			else
				this->FibonacciFuncMASM(i);
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
	int Fibonacci::FibonacciFunc(int n)
	{
		if (n < 0)
		{
			std::cerr << "Negative value in Fibonacci" << std::endl;
			exit(0);
		}
		if (n == 0)
			return 0;
		else if (n == 1)
			return 1;
		else
			return this->FibonacciFunc(n - 1) + this->FibonacciFunc(n - 2);
	}

	////////////////////////////////////////////////////////////
	int Fibonacci::FibonacciFuncMASM(int n)
	{
		int ebxCopy, ecxCopy, edxCopy;
		_asm
		{
			mov  ecx, n
			sub ecx, 1
			mov  eax, 0; a = 0
			mov  ebx, 1; b = 1
			
			_fib:
				mov  edx, eax
				add  edx, ebx; sum = a + b
				mov  eax, ebx; a = b
				mov  ebx, edx; b = sum
			loop _fib
			mov eax, ebx
		}
	}
}