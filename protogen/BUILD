cc_library(
    name = "tictactoe_grpc",
    srcs = [
        "tictactoe.grpc.pb.cc",
        "tictactoe.pb.cc",
    ],
    hdrs = [
        "tictactoe.grpc.pb.h",
        "tictactoe.pb.h",
    ],
    visibility = ["//visibility:public"],
    deps = [
        "//protos:tictactoe_cc_proto",
        "@grpc//:grpc++",
    ],
)

# filegroup(
#     name = "tictactoe_proto_gen_files",
#     srcs = [
#         "tictactoe.grpc.pb.cc",
#         "tictactoe.grpc.pb.h",
#         "tictactoe.pb.cc",
#         "tictactoe.pb.h",
#     ],
#     # visibility = ["//visibility:public"],
# )
