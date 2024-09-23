#include "graphicsManager.h"
//#include "breakout.h"

GraphicsManager::GraphicsManager()
{
    //ctor

}

void GraphicsManager::init(float _width, float _height)
{
    sprite_vs_dir = helper.combineStrings(helper.currentDir.c_str(), vs_sprite);
    vs_sprite = "/src/shaders/breakout/sprite_vertex.vs";
    width = _width;
    height = _height;
}

void GraphicsManager::LoadShaders()
{
    //ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");

    const char *vs_sprite = sprite_vs_dir;
    const char *fs_sprite = "/home/joseph/Dev/codeblocks/HelloWorld/src/shaders/breakout/sprite_fragment.fs";
    const char *gs_sprite = nullptr;

    const char *vs_particle = "/home/joseph/Dev/codeblocks/HelloWorld/src/shaders/breakout/particle_vertex.vs";
    const char *fs_particle = "/home/joseph/Dev/codeblocks/HelloWorld/src/shaders/breakout/particle_fragment.fs";
    const char *gs_particle = nullptr;

    //std::cout << vs_particle << "\n";
    //std::cout << vs_particle << "\n";

    //std::cout << vs;

    // The above code could be moved into a helper class or some sort of data management class

    ResourceManager::LoadShader(vs_sprite, fs_sprite, gs_sprite, "sprite");
    ResourceManager::LoadShader(vs_particle, fs_particle, gs_particle, "particle");
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
    game.Levels[game.Level].Draw(*Renderer);
    // draw player
    Breakout::Player->Draw(*Renderer);
    // draw particles
    Particles->Draw();
    // draw ball
    Breakout::Ball->Draw(*Renderer);
}
