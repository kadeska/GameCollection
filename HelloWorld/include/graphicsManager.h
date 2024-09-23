#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

#include "helper.h"
#include "resourceManager.h"
#include "breakout.h"
#include "spriteRenderer.h"
#include "particleGenerator.h"

class GraphicsManager
{
public:
    GraphicsManager(); // Constructor

    void init(float width, float height);
    void LoadShaders();
    void ConfigureShaders();
    void LoadTextures();
    void SetRenderSpecificControls();
    void Render();


    //Breakout game;
    Helper helper;
    SpriteRenderer    *Renderer;
    ParticleGenerator *Particles;

    // Variables
    unsigned int width = 0, height = 0;
    //Breakout game;
    const char* sprite_vs_dir;


protected:

private:
    const char* vs_sprite;
};

#endif // GRAPHICSMANAGER_H
