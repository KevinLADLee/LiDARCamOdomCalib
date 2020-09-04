#pragma once

#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <sstream>

std::vector<std::string> getFileWithNumber(std::string folder, std::string filename, std::string extension);
