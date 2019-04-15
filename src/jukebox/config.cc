#include "config.h"

namespace jukebox {

YAML::Node load_config(std::string path) {
  YAML::Node config = YAML::LoadFile(path);
  ASSERT_CONFIGURATION_OK(config);

  return config;
}

}  // namespace jukebox