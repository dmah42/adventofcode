[
    cc_binary(
        name = n,
        srcs = [n + ".cc"],
        data = [":input.txt", ":test.txt"],
        copts = ["--std=c++17"],
    )

    for n in ["part1", "part2"]
]
