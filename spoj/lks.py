
max_wt, n = map(int, input().split())
items = [tuple(map(int, input().split())) for i in range(n)]


memo = [ [-1 for _ in range(200)] for _ in range(501)]

def knapsack(item_no, wt_left):
    
    if item_no >= n:
        return 0
    if items[item_no][1] > wt_left:
        return knapsack(item_no+1, wt_left)
    if memo[item_no][wt_left] != -1:
        return memo[item_no][wt_left]

    memo[item_no][wt_left] = max(knapsack(item_no+1, wt_left), \
                                 items[item_no][0] + knapsack(item_no+1, wt_left-items[item_no][1]))
    return memo[item_no][wt_left]


print(knapsack(0, max_wt))
