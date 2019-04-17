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
licenses(["notice"])

exports_files(["COPYING"])

cc_library(
  name = "libopus",
  srcs = glob([
    "celt/*.c",
    "celt/x86/*.c",
    "silk/*.c",
    "silk/float/*.c",
    "silk/x86/*.c",
    "src/*.c",
  ],
  exclude = [
    "celt/opus_custom_demo.c",
    "src/opus_demo.c",
    "src/repacketizer_demo.c",
  ]),
  hdrs = glob([
    "celt/*.h",
    "celt/x86/*.h",
    "include/*.h",
    "silk/*.h",
    "silk/float/*.h",
    "silk/x86/*.h",
    "src/*.h",
  ]) + ["config.h"],
  includes = [".", "celt", "include", "silk", "silk/float", "src"],
  copts = [
    "-DHAVE_CONFIG_H",
    "-std=gnu99",
    "-O2",
    "-g",
    "-msse4.1",
    "-maes",
    "-fvisibility=hidden",
    "-W",
    "-Wall",
    "-Wextra",
    "-Wcast-align",
    "-Wnested-externs",
    "-Wshadow",
    "-Wstrict-prototypes",
    "-Wno-sign-compare",
  ],
  visibility = ["//visibility:public"],
)

genrule(
  name = "config_h",
  srcs = [
    "autogen.sh",
    "configure.ac",
    "Makefile.am",
    "doc/Makefile.am",
    "NEWS",
    "README",
    "AUTHORS",
    "ChangeLog",
  ] + glob([
    "**/*.in",
    "m4/*.m4",
    "*.mk",
    "src/*.c",
  ]),
  outs = ["config.h"],
  cmd = "./$(location autogen.sh) " +
        "&& ./`dirname $(location autogen.sh)`/configure --enable-optimizations " +
        "&& cp config.h $(location config.h)",
)
  """
)