# Bazel (https://bazel.io) BUILD file for Jukebox.

licenses(["notice"])

exports_files(["LICENSE"])

cc_binary(
  name = "jukebox",
  srcs = [
    "src/jukebox/main.cc",
    "src/jukebox/config.h",
    "src/jukebox/config.cc",
    "src/jukebox/discord/opus.cc",
    "src/jukebox/discord/opus.h",
  ],
  visibility = ["//visibility:public"],
  deps = [
    "@yaml_cpp//:yaml-cpp",
    "@opus//:libopus",
  ],
)

cc_test(
  name = "jukebox-test",
  srcs = [],
  args = [],
  visibility = ["//visibility:public"],
  deps = [":jukebox"],
)