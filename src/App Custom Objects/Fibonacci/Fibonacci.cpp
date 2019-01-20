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
		this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void Fibonacci::ArrayInit()
	{
		// this is for fibonacci sequence
		// from  to 2147483647
		this->vertexArray = sf::VertexArray(sf::LineStrip, 34);
		for (int i = 1; i <= 34; i++)
		{
			// Remember to do something about * 50 - maybe delete
			this->vertexArray[i - 1] = sf::Vector2f((SCRWIDTH / 2.0f) + i * 10, 
									(SCRHEIGHT / 2.0f) - this->FibonacciFunc(i) * 10);
			this->vertexArray[i - 1].color = sf::Color::Red;
			std::cout << "Coords: " << vertexArray[i - 1].position.x << ", " << vertexArray[i - 1].position.y << std::endl;
			std::cout << "Calculated for [" << i << "]" << std::endl;
		}
		std::cout << "Finished calculating!" << std::endl;
		std::cout << '\a' << std::endl;
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
}