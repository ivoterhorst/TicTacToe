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
    deps = [
        ":utils-lib",
    ],
)

cc_library(
    name = "player-lib",
    srcs = ["player.cpp"],
    hdrs = [
        "player.hpp",
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
    ],
)

cc_library(
    name = "utils-lib",
    srcs = ["utils.cpp"],
    hdrs = [
        "types.hpp",
        "utils.hpp",
    ],
    # visibility = [
    #     "//bin:__pkg__",
    #     "//tests:__pkg__",
    # ],
)
