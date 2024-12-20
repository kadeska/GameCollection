/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
/**
** This is where the breakout game begins. Breakout contains all core
** game related state and functionality.
**/
#ifndef BREAKOUT_GAME_H
#define BREAKOUT_GAME_H

#include <iostream>
#include <filesystem>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "core.hpp"
#include "gameLevel.hpp"
#include "resourceManager.hpp"
#include "gameObject.hpp"
#include "ballObject.hpp"
#include "graphicsManager.hpp"


// Represents the current state of the game
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// Defines a Collision typedef that represents collision data
typedef std::tuple<bool, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

// The above constants can be set by construction or set by config file.


// Graphic manager.
//GraphicsManager gfcMan;

/**  BreakoutGame holds all game-related state and functionality.
* Combines all game-related data into a single class for
* easy access to each of the components and manageability.
*/
class BreakoutGame
{
public:
    //BreakoutGame();
    // game state
    GameState               State;
    bool                    Keys[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels; // Array of levels
    unsigned int            Level; // What Level are we on
    GameObject        *Player; // Make player object its own seperate oject instead of a GameObject.
    BallObject        *Ball;

    // constructor/destructor
    BreakoutGame(unsigned int width, unsigned int height);
    ~BreakoutGame();

    // initialize game state (load all shaders/textures/levels)
    void Init(std::string _gamePath, std::string _shaderPath);
    // game loop
    void ProcessInput(float dt);
    void Update(float dt);
    void Render();

    void DoCollisions();
    // reset
    void ResetLevel();
    void ResetPlayer();
    void LoadLevels();
    void ConfigureGameObjects();
};

#endif

