import sys


def fresh(n: int, r: list[int]) -> bool:
    return n >= r[0] and n <= r[1]


def main():
    ranges: list[list[int]] = []
    count: int = 0

    min_bound = -1
    max_bound = -1

    for line in sys.stdin:
        line = line.strip()
        if line == "":
            break

        r = list(map(int, line.strip().split("-")))
        ranges.append(r)

        if min_bound == -1:
            min_bound = r[0]
        if max_bound == -1:
            max_bound = r[1]

        min_bound = min(min_bound, r[0])
        max_bound = max(max_bound, r[1])

    # take the union of all ranges
    for i in range(min_bound, max_bound + 1):
        rs: list[list[int]] = []
        for r in ranges:
            if fresh(i, r):
                rs.append(r)
        if len(rs) > 1:
            lmin = max_bound + 1
            lmax = min_bound
            for u in rs:
                lmin = min(lmin, u[0])
                lmax = max(lmax, u[1])
            rs = [[lmin, lmax]]
        if len(rs) == 1:
            delta = rs[0][1] - rs[0][0] + 1
            count += delta
            print(rs[0][0], rs[0][1], delta)

    print("total:", count)


if __name__ == "__main__":
    main()
