# Proto library to group a proto file with its dependencies
proto_library(
    name = "tictactoe_proto",
    srcs = ["tictactoe.proto"],
    visibility = ["//visibility:public"],
    deps = ["@protobuf//:any_proto"],
)

cc_proto_library(
    name = "tictactoe_cc_proto",
    visibility = ["//visibility:public"],
    deps = [":tictactoe_proto"],
)

