/**
** Graphics manager manages all graphics relted things,
shaders and textures. Contains references to texture
image paths and shader paths.
**
**
**/

#ifndef GRAPHICSMANAGER_H
#define GRAPHICSMANAGER_H

//#include "core.h"
#include "helper.hpp"
#include "resourceManager.hpp"
#include "breakoutGame.hpp"
#include "spriteRenderer.hpp"
#include "particleGenerator.hpp"

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

    Helper helper;
    SpriteRenderer    *Renderer;
    ParticleGenerator *Particles;

    // Variables
    unsigned int width = 0, height = 0;
    //Breakout game;
    std::string sprite_vs_dir;
    std::string sprite_fs_dir;
    std::string particle_vs_dir;
    std::string particle_fs_dir;


protected:

private:
    std::string sprite_vs;
    std::string sprite_fs;
    std::string particle_vs;
    std::string particle_fs;
};

#endif // GRAPHICSMANAGER_H
