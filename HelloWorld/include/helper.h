#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstring>

class RenderHelper
{
public:

    std::string currentDir = std::filesystem::current_path().string();

    const char* vs_sprite = "/src/shaders/breakout/sprite_vertex.vs";
    const char* sprite_vs_dir = combineStrings(currentDir.c_str(), vs_sprite); // currentDir.data() + vs_sprite;

// Render help functions
//

    void LoadShaders()
    {
        //ResourceManager::LoadShader("shaders/sprite.vs", "shaders/sprite.frag", nullptr, "sprite");

        const char *vs_sprite = helper.sprite_vs_dir;
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
    void ConfigureShaders() {}
    void LoadTextures() {}
    void SetRenderSpecificControls() {}


// Combine two const char* strings and return char*
// Dont forget to free memory after using this function by calling delete[] 'combinedString'
    char* combineStrings(const char* str1, const char* str2)
    {
        // calculate lengths
        size_t len1 = strlen(str1);
        size_t len2 = strlen(str2);

        // Allocate memory for combined string
        char* result = new char[len1 + len2 +1]; //+1 for null terminator
        // Copy first string and concatenate the second
        strcpy(result, str1);
        strcat(result, str2);
        return result; // return combined string

    }
};




#endif
