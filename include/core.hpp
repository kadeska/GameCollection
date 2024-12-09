#ifndef CORE_H
#define CORE_H

#include <filesystem>
#include <vector>

//#include <boost/filesystem.hpp>

/*
 * boost::filesystem
 *
 */
//namespace bfs = boost::filesystem;

/*
* std::filesystem
*
*/
namespace stdfs = std::filesystem; 



int startGame(stdfs::path _gamePath, stdfs::path _shaderPath);
// stdfs::path _gamePath, stdfs::path _shaderPath

//bfs::path getPath(std::string path_string);

std::vector<stdfs::path> getFilesInFolder(stdfs::path path);

#endif
