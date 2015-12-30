
l = [12, 10, 4, 3, 5]


memo = {}


def op_results(i, j):
    # Only one element in the list
    if j-i == 1:
        return {l[i]: -1}
    if (i, j) in memo:
        return memo[(i, j)]
    ans = dict([])
    # Find the last subtraction
    for split in range(i+1, j):
        # l is split into l[i:split] and l[split:j]
        lres = op_results(i, split)
        rres = op_results(split, j)
        # combine the result
        for a in lres:
            for b in rres:
                ans[a-b] = (a, b, split)

    memo[(i, j)] = ans
    return ans


def obtain_seq(i, j, n):
    seq = []

    obtain_seq(i, memo[(i, j)][n][2], memo[(i, j)][n][0]) + obtain_seq(memo[(i, j)][n][2], j, memo[(i, j)][n][1]) +
    [1]

print (op_results(0, 5))