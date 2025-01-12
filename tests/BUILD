cc_test(
    name = "test-board",
    size = "small",
    srcs = ["test_board.cpp"],
    deps = [
        "//lib:board-lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_test(
    name = "test-game",
    size = "small",
    srcs = ["test_game.cpp"],
    deps = [
        ":player-mock",
        "//lib:board-lib",
        "//lib:game-lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "player-mock",
    testonly = 1,
    # srcs = ["player_mock.cpp"],
    hdrs = ["player_mock.hpp"],
    deps = [
        "//lib:player-lib",
        "@googletest//:gtest",
    ],
)
