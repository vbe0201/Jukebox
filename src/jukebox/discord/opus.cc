#include "opus.h"

namespace jukebox {
namespace discord {
namespace opus {

Encoder::Encoder(int application) : application_(application) {
  CreateState();
}

Encoder::~Encoder() {
  opus_encoder_destroy(state_);
}

OpusEncoder* Encoder::CreateState() {
  int status;
  state_ = opus_encoder_create(
    kSamplingRate,
    kChannels,
    application_,
    &status
  );

  if (status != OPUS_OK)
    throw std::runtime_error("Couldn't create opus encoder: " + *opus_strerror(status));

  SetBitrate(128);
  SetFec();
  SetExpectedPacketLossPercent(0.15);
  SetBandwith(OPUS_BANDWIDTH_FULLBAND);
  SetSignalType(OPUS_AUTO);
}

void Encoder::SetBitrate(const int kbps) {
  int bitrate = std::min(128, std::max(16, kbps)) * 1024;
  opus_encoder_ctl(state_, OPUS_SET_BITRATE(bitrate));
}

void Encoder::SetBandwith(const opus_int32 setting) {
  opus_encoder_ctl(state_, OPUS_SET_BANDWIDTH(setting));
}

void Encoder::SetSignalType(const opus_int32 setting) {
  opus_encoder_ctl(state_, OPUS_SET_SIGNAL(setting));
}

void Encoder::SetFec(bool enabled) {
  opus_encoder_ctl(state_, OPUS_SET_INBAND_FEC(enabled));
}

void Encoder::SetExpectedPacketLossPercent(double percentage) {
  percentage = std::min(100, std::max(0, ((int) percentage * 100)));
  opus_encoder_ctl(state_, OPUS_SET_PACKET_LOSS_PERC(percentage));
}

OpusFrame Encoder::Encode(char data[kFrameBytes], int frame_size) {
  OpusFrame frame(kMaxDataSize);
  opus_int16* pcm = reinterpret_cast<opus_int16*>(data);

  opus_int32 encoded_length = opus_encode(state_, pcm, frame_size, frame.data(), kMaxDataSize);
  // TODO: Proper exception class
  if (encoded_length < 0)
    throw "Something wrong with your data arg.";

  frame.resize(encoded_length);
  return frame;
}

}  // namespace opus
}  // namespace discord
}  // namespace jukebox