[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        copts = [
            "-Wall",
            "-Werror",
            "-pedantic",
        ],
        data = [":input.txt"],
        deps = [
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
