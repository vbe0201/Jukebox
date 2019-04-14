#include "config.h"

namespace jukebox {

YAML::Node load_config(std::string path) {
  YAML::Node config = YAML::LoadFile(path);
  // The configuration section for the bot user that interacts with Discord.
  YAML::Node bot_config = config["bot"];

  // These are critical parts of the core configuration that should be present
  // at any time.
  if (!bot_config["token"] || !bot_config["guild_id"] ||
      !bot_config["user_id"] || !bot_config["session_id"] ||
      !bot_config["endpoint"]) {
    throw std::runtime_error(
        "Missing configuration entries in the 'bot' section.");
  }

  return config;
}

}  // namespace jukebox