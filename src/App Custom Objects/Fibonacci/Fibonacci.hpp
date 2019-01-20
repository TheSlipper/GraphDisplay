#pragma once
////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright � 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "../../App Engine/App.hpp"
#include "../FunctionGraph/FunctionGraph.hpp"
#include "../../DEFINITIONS.h"
#include <SFML/Graphics.hpp>
#include <iostream>


namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	/// \brief DiagramState class
	///
	////////////////////////////////////////////////////////////
	class Fibonacci : public FunctionGraph
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief DiagramState constructor
		///
		////////////////////////////////////////////////////////////
		Fibonacci(GameDataRef data);

	private:
		////////////////////////////////////////////////////////////
		/// \brief Sets the vertexArray arguments' coordinates
		///
		////////////////////////////////////////////////////////////
		void ArrayInit();
		
		////////////////////////////////////////////////////////////
		/// \brief Calculates the x-th argument of fibonaccis formula
		///
		/// \param int x which argument do you want to calculate
		///
		////////////////////////////////////////////////////////////
		int FibonacciFunc(int n);
	};
}