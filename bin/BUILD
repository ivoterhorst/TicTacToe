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
    name = "tictactoe_server",
    srcs = ["tictactoeserver.cpp"],
    deps = [
        "//protogen:tictactoe_grpc",
        "@grpc//:grpc++",
    ],
)
