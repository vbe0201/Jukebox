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