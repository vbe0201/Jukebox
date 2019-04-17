#ifndef JUKEBOX_SRC_DISCORD_OPUS_H_
#define JUKEBOX_SRC_DISCORD_OPUS_H_

#include <stdint.h>

#include <algorithm>
#include <stdexcept>
#include <string>
#include <vector>

#include "opus/opus.h"

namespace jukebox {
namespace discord {
namespace opus {

const int kSamplingRate = 48000;
const int kChannels = 2;
const int kFrameLength = 20;
const int kSampleSize = 4;  // (bitrate / 8) * kChannels (bitrate == 16)
const int kSamplesPerFrame = kSamplingRate / 1000 * kFrameLength;
const int kFrameSize = kSamplesPerFrame * kSampleSize;
const int kFrameBytes = kFrameSize * kChannels * sizeof(opus_int16);

const int kMaxDataSize = 1 << 16;

using OpusFrame = std::vector<uint8_t>;

class Encoder {
 public:
  explicit Encoder(int application = OPUS_APPLICATION_AUDIO);

  ~Encoder();

  void SetBitrate(const int kbps);

  void SetBandwith(const opus_int32 setting);

  void SetSignalType(const opus_int32 setting);

  void SetFec(bool enabled = true);

  void SetExpectedPacketLossPercent(double percentage);

  OpusFrame Encode(char data[kFrameBytes], int frame_size);

 private:
  const int application_;
  OpusEncoder* state_;

  OpusEncoder* CreateState();
};

}  // namespace opus
}  // namespace discord
}  // namespace jukebox

#endif  // JUKEBOX_SRC_DISCORD_OPUS_H_