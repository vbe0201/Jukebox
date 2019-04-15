#ifndef JUKEBOX_SRC_CONFIG_H_
#define JUKEBOX_SRC_CONFIG_H_

#include <stdexcept>
#include <string>

#include "yaml-cpp/yaml.h"

namespace jukebox {

// Used to check that the critical configuration entries required by Jukebox are
// being provided.
#define ASSERT_CONFIGURATION_OK(config)                              \
  if (!config["bot"]["token"] || !config["bot"]["guild_id"] ||      \
      !config["bot"]["user_id"] || !config["bot"]["session_id"] ||  \
      !config["bot"]["endpoint"] || !config["server"]["address"] || \
      !config["server"]["port"])                                    \
    throw std::runtime_error("Missing required configuration entries!");

// Loads the configuration files and verifies all required options.
YAML::Node load_config(std::string path);

}  // namespace jukebox

#endif  // JUKEBOX_SRC_CONFIG_H_