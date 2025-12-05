import sys


def fresh(n: int, range: list[int]) -> bool:
    return n >= range[0] and n <= range[1]


def main():
    ranges: list[list[int]] = []
    count: int = 0

    for line in sys.stdin:
        line = line.strip()
        if line == "":
            break
        range = list(map(int, line.strip().split("-")))
        ranges.append(range)

    for line in sys.stdin:
        n = int(line.strip())
        for range in ranges:
            if fresh(n, range):
                count += 1
                print(n, range)
                break

    print(count)


if __name__ == "__main__":
    main()
