#include "../include/graphicsManager.hpp"
//#include "breakoutGame.h"
//#include "core.h"
GraphicsManager::GraphicsManager()
{
    //ctor

}

void GraphicsManager::init(float _width, float _height)
{
    std::cout << "Hello!!";

    sprite_vs = "/shaders/breakout/sprite_vertex.vs";
    sprite_fs = "/shaders/breakout/sprite_fragment.fs";

    particle_vs = "/shaders/breakout/particle_vertex.vs";
    particle_fs = "/shaders/breakout/particle_fragment.fs";

    
    std::cout << helper.combineStrings(helper.currentDir.c_str(), sprite_vs.c_str());

    sprite_vs_dir = helper.combineStrings(helper.currentDir.c_str(), sprite_vs.c_str());
    sprite_fs_dir = helper.combineStrings(helper.currentDir.c_str(), sprite_fs.c_str());

    particle_vs_dir = helper.combineStrings(helper.currentDir.c_str(), particle_vs.c_str());
    particle_fs_dir = helper.combineStrings(helper.currentDir.c_str(), particle_fs.c_str());
    
    width = _width;
    height = _height;
}

void GraphicsManager::LoadShaders()
{
    //ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");

//    const char *vs_sprite = sprite_vs_dir;
//    const char *fs_sprite = sprite_fs_dir;
//    const char *gs_sprite = nullptr;

//    const char *vs_particle = particle_vs_dir;
//    const char *fs_particle = particle_fs_dir;
//    const char *gs_particle = nullptr;


    //std::cout << sprite_vs_dir << "\n";
    //std::cout << sprite_fs_dir << "\n";
    //std::cout << particle_fs_dir << "\n";
    //std::cout << particle_vs_dir << "\n";

    //std::cout << vs;

    // The above code could be moved into a helper class or some sort of data management class

    ResourceManager::LoadShader(sprite_vs_dir.c_str(), sprite_fs_dir.c_str(), nullptr, "sprite");
    ResourceManager::LoadShader(particle_vs_dir.c_str(), particle_fs_dir.c_str(), nullptr, "particle");
}

void GraphicsManager::ConfigureShaders()
{
    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("image", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    ResourceManager::GetShader("particle").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("particle").SetMatrix4("projection", projection);
}
void GraphicsManager::LoadTextures()
{
    ResourceManager::LoadTexture("textures/background.jpg", false, "background");
    ResourceManager::LoadTexture("textures/awesomeface.png", true, "face");
    ResourceManager::LoadTexture("textures/block.png", false, "block");
    ResourceManager::LoadTexture("textures/block_solid.png", false, "block_solid");
    ResourceManager::LoadTexture("textures/paddle.png", true, "paddle");
    ResourceManager::LoadTexture("textures/ball.png", true, "ball");
    ResourceManager::LoadTexture("textures/particle.png", true, "particle");
}
void GraphicsManager::SetRenderSpecificControls()
{
    Shader myShader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(myShader);
    Particles = new ParticleGenerator(ResourceManager::GetShader("particle"), ResourceManager::GetTexture("particle"), 500);

    //Particles = new ParticleGenerator(ResourceManager::GetShader("particle"), ResourceManager::GetTexture("particle"), 500);
}

void GraphicsManager::Render()
{
    //Breakout game;
    // draw background
    //Renderer->DrawSprite(ResourceManager::GetTexture("background"), glm::vec2(0.0f, 0.0f), glm::vec2(this->Width, this->Height), 0.0f);
    Texture2D myTexture;
    myTexture = ResourceManager::GetTexture("background");
    Renderer->DrawSprite(myTexture, glm::vec2(0.0f, 0.0f), glm::vec2(width, height), 0.0f);
    // draw level
    //BreakoutGame::Levels[Level].Draw(*Renderer);
    // draw player
    //game->Player->Draw(*Renderer);
    // draw particles
    Particles->Draw();
    // draw ball
    //Breakout->Ball->Draw(*Renderer);
}
