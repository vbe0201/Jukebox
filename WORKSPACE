# Bazel (https://bazel.io/) WORKSPACE file for Jukebox.

workspace(name = "jukebox")

new_local_repository(
  name = "yaml_cpp",
  path = "externals/yaml-cpp",
  build_file_content = """
exports_files(["LICENSE"])

cc_library(
  name = "yaml-cpp",
  srcs = glob([
    "src/**/*.cpp",
    "src/**/*.h",
  ]),
  hdrs = glob([
    "include/**/*.h",
  ]),
  includes = ["include"],
  visibility = ["//visibility:public"],
)
  """,
)

new_local_repository(
  name = "opus",
  path = "externals/opus",
  build_file_content = """
exports_files(["COPYING"])

cc_library(
  name = "libopus",
  srcs = glob([
    "celt/*.c",
    "silk/*.c",
    "silk/float/*.c",
  ]) + [
    "src/analysis.c",
    "src/mlp.c",
    "src/mlp_data.c",
    "src/opus.c",
    "src/opus_decoder.c",
    "src/opus_encoder.c",
    "src/opus_multistream.c",
    "src/opus_multistream_decoder.c",
    "src/opus_multistream_encoder.c",
    "src/repacketizer.c",
  ],
  hdrs = glob([
    "celt/*.h",
    "include/*.h",
    "silk/*.h",
    "silk/float/*.h",
    "src/*.h",
  ]),
  includes = ["celt", "include", "silk", "silk/float"],
  copts = [
    '-DHAVE_CONFIG_H',
    '-I$(GENDIR)/opus/opus',  # For config.h.
    '-Iopus/opus/celt',
    '-Iopus/opus/include',
    '-Iopus/opus/silk',
    '-Iopus/opus/silk/fixed',
    '-Iopus/opus/silk/float',
    '-std=gnu99',
    '-O2',
    '-g',
    '-fvisibility=hidden',
    '-W',
    '-Wall',
    '-Wextra',
    '-Wcast-align',
    '-Wnested-externs',
    '-Wshadow',
    '-Wstrict-prototypes',
  ],
  visibility = ["//visibility:public"],
)
  """
)