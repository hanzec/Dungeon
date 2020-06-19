//
// Created by hanzech on 6/6/20.
//

#include <sys/stat.h>
#include "boost/filesystem.hpp"
#include "ResourcesManager.h"

namespace fs = boost::filesystem;

Resource::ResourcesManager::ResourcesManager(const std::string& recourseFolder) {

    //1st need to make sure folder exist
    if(!fs::is_directory(recourseFolder))
        throw std::runtime_error("recourse Folder not exist");

    //initialized terrain storage



}

Resource::ResourcesManager::~ResourcesManager() {

}
