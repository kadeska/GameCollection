#ifndef HELPER_H
#define HELPER_H

#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include "../include/core.hpp"

class Helper {
public:
  std::filesystem::path currentPath = std::filesystem::current_path();
  std::string currentPathStr = currentPath.string();
  // std::string currentDir = std::filesystem::current_path().string();

  // game_path is the current path
  stdfs::path game_path = currentPathStr;
  // shader_path is the path to the shader directory.
  stdfs::path shader_path = game_path.string() + "/src/shaders/breakout";

  // particle fragment shader path
  // particle vertex shader path
  // sprite fragment shader path
  // sprite vertex shader path

  // Combine two const char* strings and return char*
  // Dont forget to free memory after using this function by calling delete[]
  // 'combinedString'
  char *combineStrings(const char *str1, const char *str2) {
    // calculate lengths
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);

    // Allocate memory for combined string
    char *result = new char[len1 + len2 + 1]; //+1 for null terminator
    // Copy first string and concatenate the second
    strcpy(result, str1);
    strcat(result, str2);

    // std::cout << result << "HELLO!!";
    return result; // return combined string
  }
};

#endif
