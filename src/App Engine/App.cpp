﻿////////////////////////////////////////////////////////////
// Created by Kornel Domeradzki.
// Copyright © 2018 Kornel Domeradzki. All rights reserved.
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include "App.hpp"
#include "../App States/Diagram State/DiagramState.hpp"

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    App::App(std::string title, int fromX, int fromY, GraphType graphType)
    {
        this->LoadGamesSettings("game_settings.conf");
		this->_data->graphType = graphType;

        this->_data->window.create(sf::VideoMode(this->_data->settings.width,
                    this->_data->settings.height), title, sf::Style::Close
                                                        | sf::Style::Titlebar);
		this->_data->window.setPosition(sf::Vector2i(fromX, fromY));
        this->_data->machine.AddState(StateRef(new DiagramState(this->_data)));

        this->Run();
    }

    ////////////////////////////////////////////////////////////
    void App::LoadGamesSettings(std::string settingsFilePath)
    {

        std::fstream fileReader(settingsFilePath, std::ios::in);
        unsigned short int settIterator = 0;  // 0 = width, 1 = height;
        std::string readLine;
        unsigned int width, height, master_vol, sfx_vol, music_vol;

        if (!fileReader.good())
          exit(-255); // TODO: Show some info on no settings file

        while(!fileReader.eof())
        {
          getline(fileReader, readLine);
          if (isdigit(readLine[0]) || isalpha(readLine[0]))
          {
            switch (settIterator)
            {
              case 0:
                width = std::stoi(readLine);
                break;
              case 1:
                height = std::stoi(readLine);
                break;
              case 2:
                master_vol = std::stoi(readLine);
                break;
              case 3:
                sfx_vol = std::stoi(readLine);
                break;
              case 4:
                music_vol = std::stoi(readLine);
                break;
              default:
                break;
            }
            settIterator++;
          }
        }
        fileReader.clear();
        fileReader.close();
        this->_data->settings.width = width;
        this->_data->settings.height = height;
        this->_data->settings.master_vol = master_vol;
        this->_data->settings.sfx_vol = sfx_vol;
        this->_data->settings.music_vol = music_vol;
    }

    ////////////////////////////////////////////////////////////
    void App::Run()
    {
        float newTime, frameTime, interpolation;

        float currentTime = this->_clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while (this->_data->window.isOpen())
        {
            this->_data->machine.ProcessStateChanges();

            newTime = this->_clock.getElapsedTime().asSeconds();
            frameTime = newTime - currentTime;

            if (frameTime > 0.25f)
                frameTime = 0.25f;

            currentTime = newTime;
            accumulator += frameTime;

            while (accumulator >= dt)
            {
                this->_data->machine.GetActiveState()->HandleInput();
                this->_data->machine.GetActiveState()->Update(dt);

                accumulator -= dt;
            }

            interpolation = accumulator / dt;
            this->_data->machine.GetActiveState()->Draw(interpolation);
        }
    }
}
