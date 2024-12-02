#ifndef CORE_H
#define CORE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"


#include "resourceManager.hpp"
#include "graphicsManager.hpp"

#include <iostream>
#include <filesystem>

#include <boost/filesystem.hpp>

/**
 * @brief - boost::filesystem
 * 
 */
namespace bfs = boost::filesystem;
namespace stdfs = std::filesystem;

int startGame();


bfs::path getPath(std::string path_string);

std::vector<stdfs::path> getFilesInFolder(stdfs::path path);

#endif
