cc_binary(
    name = "tictactoe",
    srcs = ["tictactoe.cpp"],
    deps = [
        "//lib:board-lib",
        "//lib:game-lib",
        "//lib:player-lib",
        "//lib:randomplayerchooser-lib",
    ],
)

cc_binary(
    name = "tictactoe-server",
    srcs = ["tictactoeserver.cpp"],
    deps = [
        "//protos:tictactoe_cc_grpc",
        "@grpc//:grpc++",
    ],
)

cc_binary(
    name = "tictactoe-client",
    srcs = ["tictactoe_client_main.cpp"],
    deps = [
        "//lib:tictactoe-client-lib",
    ],
)
