cc_library(
    name = "floor",
    srcs = [
        "floor.cc",
        "floor.h",
    ],
)

cc_test(
    name = "floor_test",
    srcs = ["floor_test.cc"],
    deps = [
        ":floor",
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
            ":floor",
            "@com_google_absl//absl/base",
            "@com_google_absl//absl/strings",
        ],
    )

    for n in ["part1", "part2"]
]
