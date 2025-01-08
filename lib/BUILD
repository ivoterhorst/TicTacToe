cc_library(
    name = "board-lib",
    srcs = ["board.cpp"],
    hdrs = ["board.hpp"],
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
    ],
)
