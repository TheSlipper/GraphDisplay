////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "BubbleSorting.hpp"

namespace ArktisProductions
{
	////////////////////////////////////////////////////////////
	BubbleSorting::BubbleSorting(GameDataRef data) :FunctionGraph(data)
	{
		this->elapsedTimes = new float[ARRAY_MAX_SIZE];
		this->vertexArray = sf::VertexArray(sf::Lines, ARRAY_MAX_SIZE);
		// this->ArrayInit();
	}

	////////////////////////////////////////////////////////////
	void BubbleSorting::ArrayInit(bool usingCpp)
	{
		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds();
		srand(69);

		for (int i = 2; i < ARRAY_MAX_SIZE; i++)
		{
			// clock_t time = clock();
			float time = this->_data->gameClock.getElapsedTime().asMicroseconds();
			int *tempArray;
			if (usingCpp)
			{
				tempArray = this->GetRandomNumArrayCpp(i);
				this->SortArrayCpp(tempArray);
			}
			this->elapsedTimes[i] = this->_data->gameClock.getElapsedTime().asMicroseconds() - time;
			std::cout << "Sorted an array with " << i << " elements, took " << this->elapsedTimes[i] << "ms" << std::endl;

			this->vertexArray[i] = sf::Vector2f((SCRWIDTH / 2.0f) + (i * WIDTH_MULTIPLIER),
				(SCRHEIGHT / 2.0f) - (this->elapsedTimes[i - 1] * HEIGHT_MULTIPLIER));
			if (usingCpp) this->vertexArray[i].color = sf::Color::Blue;
			else this->vertexArray[i].color = sf::Color::Green;
		}

		this->calcTime = this->_data->gameClock.getElapsedTime().asSeconds() - this->calcTime;
		std::cout << "\r\nFinished calculating! \r\nTook " << this->calcTime << "s to finish" << std::endl;
		std::cout << '\a' << std::endl;
	}

	////////////////////////////////////////////////////////////
	void BubbleSorting::swap(int *xp, int *yp)
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}

	////////////////////////////////////////////////////////////
	int* BubbleSorting::GetRandomNumArrayCpp(int n)
	{
		int *array = new int[n];
		for (int i = 0; i < sizeof(int)/sizeof(array); i++)
			array[i] = rand();
		return array;
	}

	////////////////////////////////////////////////////////////
	int* BubbleSorting::GetRandomNumArrayMASM(int n)
	{
		// TODO: 
		return nullptr;
	}

	////////////////////////////////////////////////////////////
	void BubbleSorting::SortArrayCpp(int *array)
	{
		int i, j;
		for (i = 0; i < (sizeof(int) / sizeof(array)) - 1; i++)
		{
			for (unsigned int j = 0; j < (sizeof(int) / sizeof(array)) - i - 1; j++)
				if (array[j] > array[j + 1])
					swap(&array[j], &array[j + 1]);
		}
	}

	////////////////////////////////////////////////////////////
	void BubbleSorting::SortArrayMASM(int *array)
	{
		__asm {
		mov ecx, 0
		mov edx, 0
			lea esi, array
			innerloop:

		inc ecx
			cmp ecx, 5
			je outerloop
			mov eax, [esi]
			cmp eax, [esi + 4]
			Jbe noexchange         // <=============== ASCENDING ORDER.

			; exchange values
			xchg eax, [esi + 4]
			mov[esi], eax
			noexchange :
		add esi, 4
			jmp innerloop

			outerloop :
		lea esi, array        // <=====================

			; inner loop counter
			mov ecx, 0

			; outer loop counter
			inc edx

			cmp edx, 5
			jne innerloop

			; loop 3 counter
			mov edx, 0

			; load array offset
			lea esi, array        // <=====================

			loop3:

		mov eax, [esi]
			push edx
			// invoke printf, addr fmtmsg1, eax
			pop edx

			add esi, 4
			inc edx
			cmp edx, 5
			jne loop3

			// invoke printf, addr fmtmsg2
		}
	}
}