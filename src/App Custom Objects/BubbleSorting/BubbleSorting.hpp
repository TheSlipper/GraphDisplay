#pragma once
////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright � 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////
#pragma once

////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////
#define ARRAY_MAX_SIZE 30238
#define WIDTH_MULTIPLIER ((SCRWIDTH*3.0f)/1920.0f)
#define HEIGHT_MULTIPLIER ((SCRHEIGHT*5.0f)/1080.0f)

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
	class BubbleSorting : public FunctionGraph
	{
	public:
		////////////////////////////////////////////////////////////
		/// \brief DiagramState constructor
		///
		////////////////////////////////////////////////////////////
		BubbleSorting(GameDataRef data);

		////////////////////////////////////////////////////////////
		/// \brief Sets the vertexArray arguments' coordinates
		///
		////////////////////////////////////////////////////////////
		void ArrayInit(bool usingCpp);

		////////////////////////////////////////////////////////////
		/// \brief Swaps two values
		///
		////////////////////////////////////////////////////////////
		void swap(int *xp, int *yp);

		////////////////////////////////////////////////////////////
		/// \brief Returns a dynamic array initialized with random numbers
		///
		/// \param int n length
		///
		/// \returns array
		///
		////////////////////////////////////////////////////////////
		int* GetRandomNumArrayCpp(int n);

		////////////////////////////////////////////////////////////
		/// \brief Returns a dynamic array initialized with random numbers
		///
		/// \param int n length
		///
		/// \returns array
		///
		////////////////////////////////////////////////////////////
		int* GetRandomNumArrayMASM(int n);

		////////////////////////////////////////////////////////////
		/// \brief Bubble sorts an array with C++
		///
		/// \param int* array array
		///
		////////////////////////////////////////////////////////////
		void SortArrayCpp(int *array);

		////////////////////////////////////////////////////////////
		/// \brief Bubble sorts an array with MASM
		///
		/// \param int* array array
		///
		////////////////////////////////////////////////////////////
		void SortArrayMASM(int *array);

	private:
		float *elapsedTimes, calcTime;
	};
}