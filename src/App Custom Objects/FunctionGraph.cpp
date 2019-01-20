////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "FunctionGraph.hpp"
#include <cmath>

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    FunctionGraph::FunctionGraph(GameDataRef data, float xMin, float xMax, float precision) :_data(data)
    {
        this->precision = precision;
        this->xMin = &xMin;
        this->xMax = &xMax;
        this->calculateArgs();
    }

    ////////////////////////////////////////////////////////////
    sf::Vertex FunctionGraph::valueToCoordinate(float x, float y)
    {

    }

    ////////////////////////////////////////////////////////////
    void FunctionGraph::calculateArgs()
    {
        // f(x) = sin((5x^2 - 8x - 13)/(x^2 - 5))
        // TODO: Finish this calculation of coordinates
        float distBetweenPoints;
        if (*this->xMin > 0) // TODO: Make the y axis disappear in that case
            distBetweenPoints = *this->xMax - *this->xMin;
        else if (*this->xMax < 0)
            distBetweenPoints = abs(*this->xMax) - abs(*this->xMin);
        else
            distBetweenPoints = abs(*this->xMin) + *this->xMax;


        for (float currentXVal = *xMin; currentXVal < *xMax; currentXVal += this->precision)
        {

        }

#ifdef __OS_X__
        __asm__("");
#endif
#ifdef __WIN__

#endif

    }

    ////////////////////////////////////////////////////////////
    void FunctionGraph::draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        for (int i = 0; i < vertexArray.getVertexCount(); i++)
            target.draw(&vertexArray[i], 4, sf::Lines);
    }
}