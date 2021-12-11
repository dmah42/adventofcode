COPTS = [
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
    copts = COPTS,
    deps = [
        "@com_google_absl//absl/base",
        "@com_google_absl//absl/strings",
    ],
)

[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        copts = COPTS,
        data = [":input.txt"],
        deps = [
            ":lib",
            "//2021:input",
        ],
    )
    for n in [
        "part1",
        "part2",
    ]
]
