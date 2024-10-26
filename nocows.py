

from sys import stdin, stdout

md = 9901

stdin = open("nocows.in", "r")
stdout = open("nocows.out", "w")

n, k = map(int, stdin.readline().strip().split())

dp = {}
dp[(1, 1)] = 1

def solve(n, k):
    if k <= 0:
        return 0
    
    if n <= 0 or n&1 == 0:
        return 0
    
    
    if n < (2*k - 1)  or n > (2**k) - 1:
        return 0
    
    if (n, k) in dp:
        return dp[(n, k)]
    
    ans = 0
    
    
    
    
    # both left and right have height k - 1
    for left_nodes in range(1, n, 2):
        right_nodes = n - left_nodes - 1
        l = (solve(left_nodes, k - 1)%md)
        r = (solve(right_nodes, k - 1)%md)
        ans = (ans + (l*r)%md)%md
        
        
    # left has height k - 1
    for right_height in range(1, k - 1):
        for left_nodes in range(1, n, 2):
            right_nodes = n - left_nodes - 1
            l = (solve(left_nodes, k - 1)%md)
            r = (solve(right_nodes, right_height)%md)
            ans = (ans + (l*r)%md)%md
            
            
    # # right has height k - 1
    for left_height in range(1, k - 1):
        for left_nodes in range(1, n, 2):
            right_nodes = n - left_nodes - 1
            l = solve(left_nodes, left_height)%md
            r = solve(right_nodes, k-1)%md
            ans = (ans + (l*r)%md)%md
            
            
    dp[(n, k)] = ans
    return dp[(n, k)]


stdout.write(f"{solve(n, k)}\n")
            
    
    
    
    
    