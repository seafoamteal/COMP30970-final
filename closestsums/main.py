import bisect
from math import inf


def main():
    N = int(input())
    case = 0

    while True:
        nums = []

        for i in range(N):
            nums.append(int(input()))
        nums.sort()

        m = int(input())

        case += 1
        print(f"Case {case}:")
        for i in range(m):
            q = int(input())

            min_diff = inf
            closest_sum = inf
            for idx, n in enumerate(nums):
                target = q - n
                closest = bisect.bisect(nums, target)

                if closest == 0:
                    check = closest
                    if closest == idx:
                        check += 1

                    maybe_sum = n + nums[check]
                    if abs(q - maybe_sum) < min_diff:
                        closest_sum = maybe_sum
                        min_diff = abs(q - maybe_sum)
                elif closest == N:
                    check = closest - 1
                    if check == idx:
                        check -= 1

                    maybe_sum = n + nums[check]
                    if abs(q - maybe_sum) < min_diff:
                        closest_sum = maybe_sum
                        min_diff = abs(q - maybe_sum)

                elif closest == N - 1:
                    check = closest
                    if check == idx:
                        check -= 1

                    maybe_sum = n + nums[check]
                    if abs(q - maybe_sum) < min_diff:
                        closest_sum = maybe_sum
                        min_diff = abs(q - maybe_sum)

                else:
                    check = closest - 1
                    if check == idx:
                        check -= 1

                    maybe_sum = n + nums[check]
                    if abs(q - maybe_sum) < min_diff:
                        closest_sum = maybe_sum
                        min_diff = abs(q - maybe_sum)

                    check = closest
                    if check == idx:
                        check += 1

                    maybe_sum = n + nums[check]
                    if abs(q - maybe_sum) < min_diff:
                        closest_sum = maybe_sum
                        min_diff = abs(q - maybe_sum)

            print(f"Closest sum to {q} is {closest_sum}.")

        try:
            N = int(input())
        except EOFError:
            break


if __name__ == "__main__":
    main()
