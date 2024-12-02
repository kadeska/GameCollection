/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
/**
** Core is responsible for the window and user input and entering into main game.
**
**/
#include "../include/core.hpp"
#include "../include/breakoutGame.hpp"
#include <filesystem>
#include <vector>

// GLFW function declarations
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// The Width of the screen
const unsigned int SCREEN_WIDTH = 800;
// The height of the screen
const unsigned int SCREEN_HEIGHT = 600;

// the same as BreakoutGame BreakoutGame = new BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);
//BreakoutGame BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);


//BreakoutGame BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);// BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);
//BreakoutGame BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);

/**
 * @brief - Breakout game object. Only one instance of this should exist.
 * 
 */
BreakoutGame* game;

/**
 * @brief - Initializes the window and start the main game loop.
 * 
 * @return int - std::int 
 */
int startGame() // Entery level 1
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    glfwWindowHint(GLFW_RESIZABLE, false);

    GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Breakout", nullptr, nullptr);
    glfwMakeContextCurrent(window);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSetKeyCallback(window, key_callback);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // OpenGL configuration
    // --------------------
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // initialize game
    // This is the first entry into game related code.
    // ---------------
    // The one and only Instance of BreakoutGame
    game = new BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);
    //game->BreakoutGame(SCREEN_WIDTH, SCREEN_HEIGHT);

    game->Init(/** pass game object for self referance? not needed **/);

    // deltaTime variables
    // -------------------
    float deltaTime = 0.0f;
    float lastFrame = 0.0f;

    while (!glfwWindowShouldClose(window)) // Core game loop
    {
        // calculate delta time
        // --------------------
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        glfwPollEvents();

        // manage user input
        // -----------------
        //BreakoutGame.ProcessInput(deltaTime);

        // update game state
        // -----------------
        //BreakoutGame.Update(deltaTime);

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        game->Render();
        //g.Render();

        glfwSwapBuffers(window);
    }

    // delete all resources as loaded using the resource manager
    // ---------------------------------------------------------
    ResourceManager::Clear();

    glfwTerminate();
    return 0;
}

/**
 * @brief - Get the Path object
 * 
 * @param path_string 
 * @return fs::path - boost filesystem::path
 */
bfs::path getPath(std::string path_string) {}

/**
 * @brief Gets all the files in the proveded folder path.
 * For debugging purposes this will also output all file in folder path
 * 
 * @param path 
 * @return std::vector<stdfs::path> 
 */
std::vector<stdfs::path> getFilesInFolder(stdfs::path path) 
{
    std::vector<stdfs::path> fileNamePaths;
    if(!exists(path)) {return fileNamePaths;}
    for(const auto& entry : stdfs::directory_iterator(path))
    {
        std::cout << entry.path().string() << '\n';
        fileNamePaths.push_back(entry);
    }
    return fileNamePaths;
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    // when a user presses the escape key, we set the WindowShouldClose property to true, closing the application
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
            game->Keys[key] = true;
        else if (action == GLFW_RELEASE)
            game->Keys[key] = false;
    }
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

