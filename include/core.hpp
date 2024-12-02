#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <filesystem>

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "resourceManager.hpp"
#include "graphicsManager.hpp"

#include "helper.hpp"


int startGame(stdfs::path _gamePath, stdfs::path _shaderPath);
//stdfs::path _gamePath, stdfs::path _shaderPath


bfs::path getPath(std::string path_string);

std::vector<stdfs::path> getFilesInFolder(stdfs::path path);

#endif
