cc_library(
    name = "board-lib",
    srcs = ["board.cpp"],
    hdrs = [
        "board.hpp",
        "types.hpp",
    ],
    visibility = [
        "//bin:__pkg__",
        "//tests:__pkg__",
    ],
)

cc_library(
    name = "player-lib",
    srcs = ["humanplayer.cpp"],
    hdrs = [
        "humanplayer.hpp",
        "player.hpp",
        "types.hpp",
    ],
    visibility = [
        "//bin:__pkg__",
        "//tests:__pkg__",
    ],
)

cc_library(
    name = "randomplayerchooser-lib",
    srcs = ["randomplayerchooser.cpp"],
    hdrs = [
        "randomplayerchooser.hpp",
        "startingplayerchooser.hpp",
        "types.hpp",
    ],
    visibility = [
        "//bin:__pkg__",
        "//tests:__pkg__",
    ],
)

cc_library(
    name = "game-lib",
    srcs = ["game.cpp"],
    hdrs = ["game.hpp"],
    visibility = [
        "//bin:__pkg__",
        "//tests:__pkg__",
    ],
    deps = [
        ":board-lib",
        ":player-lib",
        ":randomplayerchooser-lib",
    ],
)
