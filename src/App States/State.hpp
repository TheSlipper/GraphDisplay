#pragma once

namespace ArktisProductions
{
    ////////////////////////////////////////////////////////////
    /// \brief State class
    ///
    ////////////////////////////////////////////////////////////
    class State
    {
    public:
        ////////////////////////////////////////////////////////////
        /// \brief Initializes a state
        ///
        ////////////////////////////////////////////////////////////
        virtual void Init() = 0;

        ////////////////////////////////////////////////////////////
        /// \brief Handles state's input
        ///
        ////////////////////////////////////////////////////////////
        virtual void HandleInput() = 0;

        ////////////////////////////////////////////////////////////
        /// \brief Updates the state
        ///
        ////////////////////////////////////////////////////////////
        virtual void Update(float dt) = 0;

        ////////////////////////////////////////////////////////////
        /// \brief Draws to the screen
        ///
        ////////////////////////////////////////////////////////////
        virtual void Draw(float dt) = 0;

        ////////////////////////////////////////////////////////////
        /// \brief Pauses the state
        ///
        ////////////////////////////////////////////////////////////
        virtual void Pause() { }

        ////////////////////////////////////////////////////////////
        /// \brief Resumes the state
        ///
        ////////////////////////////////////////////////////////////
        virtual void Resume() { }
    };
}