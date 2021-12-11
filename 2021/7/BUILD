COPTS= [
            "-Wall",
            "-Werror",
            "-pedantic",
        ]

cc_library(
    name = "lib",
    srcs = [
        "lib.cc",
        "lib.h",
        ],
    deps = [
            "@com_google_absl//absl/base",
            "@com_google_absl//absl/strings",
    ],
    copts = COPTS,
)

[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        data = [":input.txt"],
        deps = [":lib"],
        copts = COPTS,
    )

    for n in ["part1", "part2"]
]
