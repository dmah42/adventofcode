cc_library(
    name = "board",
    srcs = [
        "board.cc",
        "board.h",
    ],
    deps = [
        "@com_google_absl//absl/strings",
    ],
)

cc_test(
    name = "board_test",
    srcs = ["board_test.cc"],
    deps = [
        ":board",
        "@com_google_googletest//:gtest",
        "@com_google_googletest//:gtest_main",
    ],
)

[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        data = [":input.txt"],
        deps = [
            ":board",
            "//2021:input",
            "@com_google_absl//absl/base",
            "@com_google_absl//absl/strings",
        ],
    )
    for n in [
        "part1",
        "part2",
    ]
]
