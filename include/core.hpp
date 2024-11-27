#ifndef CORE_H
#define CORE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "resourceManager.hpp"
#include "graphicsManager.hpp"

#include <iostream>

#include <boost/filesystem.hpp>


namespace fs = boost::filesystem;

int startGame();
fs::path getPath(std::string path_string);

#endif
