#ifndef JUKEBOX_SRC_CONFIG_H_
#define JUKEBOX_SRC_CONFIG_H_

#include <stdexcept>
#include <string>

#include "yaml-cpp/yaml.h"

namespace jukebox {

YAML::Node load_config(std::string path);

}  // namespace jukebox

#endif  // JUKEBOX_SRC_CONFIG_H_