import sys


def inside(n: int, range: list[int]) -> bool:
    return n >= range[0] and n <= range[1]


def intersects(r1: list[int], r2: list[int]) -> bool:
    return inside(r1[0], r2) or inside(r1[1], r2)


def union(r1: list[int], r2: list[int]) -> list[int]:
    return [min(r1[0], r2[0]), max(r1[1], r2[1])]


def union_list(ranges: list[list[int]]):
    for i in range(len(ranges)):
        for j in range(i + 1, len(ranges)):
            r1 = ranges[i]
            r2 = ranges[j]
            if intersects(r1, r2):
                r1 = union(r1, r2)
                ranges.remove(r2)
                union_list(ranges)
                print(r1)
                return


def delta(range: list[int]) -> int:
    return range[1] - range[0] + 1


def main():
    ranges: list[list[int]] = []
    count: int = 0

    for line in sys.stdin:
        line = line.strip()
        if line == "":
            break
        [a, b] = list(map(int, line.strip().split("-")))
        ranges.append([a, b])

    union_list(ranges)

    # for r in ranges:
    #     print(r)

    print("total:", count)


if __name__ == "__main__":
    main()
