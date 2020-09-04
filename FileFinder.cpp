#include "FileFinder.h"

inline bool isExist(const std::string& name) {
  struct stat buffer;
  return (stat (name.c_str(), &buffer) == 0);
}

std::vector<std::string> getFileWithNumber(std::string folder, std::string filename, std::string extension)
{

	std::vector<std::string> filelist;

	int idx = 1;
	while (true) {
      std::stringstream ss;
      ss << folder << "/" << filename << idx << "." << extension;
      std::string search_name = ss.str();
      if (isExist(search_name)) {
        filelist.push_back(search_name);
        idx++;
      } else {
        break;
      }
    }
	return filelist;
}