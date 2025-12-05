import sys


def main():
    count: int = 0
    fresh: set[int] = set()

    for line in sys.stdin:
        line = line.strip()
        if line == "":
            break
        [a, b] = list(map(int, line.strip().split("-")))
        for i in range(a, b + 1):
            # print(i)
            fresh.add(i)

    for item in fresh:
        count += 1

    print("total:", count)


if __name__ == "__main__":
    main()
