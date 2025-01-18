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
        ":test-mocks",
        "//lib:board-lib",
        "//lib:game-lib",
        "@googletest//:gtest",
        "@googletest//:gtest_main",
    ],
)

cc_library(
    name = "test-mocks",
    testonly = 1,
    hdrs = [
        "player_mock.hpp",
        "playerchooser_mock.hpp",
    ],
    deps = [
        "//lib:player-lib",
        "//lib:randomplayerchooser-lib",
        "@googletest//:gtest",
    ],
)
