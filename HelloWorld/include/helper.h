#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <cstring>
#include <filesystem>

class Helper
{
public:

    std::string currentDir = std::filesystem::current_path().string();

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
