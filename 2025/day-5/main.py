import sys


def inside(n: int, range: list[int]) -> bool:
    return n >= range[0] and n <= range[1]


def intersects(r1: list[int], r2: list[int]) -> bool:
    return inside(r1[0], r2) or inside(r1[1], r2)


def union(r1: list[int], r2: list[int]) -> list[int]:
    return [min(r1[0], r2[0]), max(r1[1], r2[1])]


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

    while len(ranges) != 0:
        current = ranges.pop()
        for r in ranges[:]:
            if intersects(current, r):
                current = union(current, r)
                ranges.remove(r)
        count += delta(current)

    print("total:", count)


if __name__ == "__main__":
    main()
