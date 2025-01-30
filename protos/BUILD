load("//bazel:cc_grpc_library.bzl", "cc_grpc_library")

proto_library(
    name = "tictactoe_proto",
    srcs = ["tictactoe.proto"],
)

cc_proto_library(
    name = "tictactoe_cc_proto",
    deps = [":tictactoe_proto"],
)

cc_grpc_library(
    name = "tictactoe_cc_grpc",
    srcs = [":tictactoe_proto"],
    grpc_only = True,
    visibility = ["//visibility:public"],
    deps = [":tictactoe_cc_proto"],
)
