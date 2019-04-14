# Bazel (https://bazel.io) BUILD file for Jukebox.

licenses(["notice"])

exports_files(["LICENSE"])

cc_binary(
  name = "jukebox",
  srcs = [
    "main.cc",
  ],
  hdrs = [],
  visibility = ["//visibility:public"],
)

cc_test(
  name = "jukebox-test",
  srcs = [],
  args = [],
  visibility = ["//visibility:public"],
  deps = [":double-conversion"],
)