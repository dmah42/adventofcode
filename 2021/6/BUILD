[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        data = [":input.txt"],
        deps = [
            "@com_google_absl//absl/base",
            "@com_google_absl//absl/strings",
        ],
        copts =[
            "-Wall",
            "-Werror",
            "-pedantic",
        ],
    )

    for n in ["part1", "part2"]
]
