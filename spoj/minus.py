# Subproblems:
#   DP(i, j) = DP(i, k) - DP(k+1, j)
# 
#   


t = int(input())

for case in range(t):
    n, m = map(int, input().split())
    nums = []
    for i in range(n):  nums.append(int(input()))
    
    # create and initialize a dp table
    dp = [ [ {} for j in range(n)] for i in range(n)]

    for i in range(n):  dp[i][i][nums[i]] = None

    for length in range(2, n+1):
        for start in range(n-length+1):
            for split in range(start+1, start+length):
                # first half: [start, split); second half: [split, start+length)
                for i in dp[start][split-1]:
                    for j in dp[split][start+length-1]:
                        dp[start][start+length-1][i-j] = (i, j, split)



    def print_res(i, j, m):
        if i != j:
            print_res(i, dp[i][j][m][2]-1, dp[i][j][m][0])
            print(dp[i][j][m][2]-1)
            print_res(dp[i][j][m][2], j, dp[i][j][m][1])

    print_res(0, n-1, m)
