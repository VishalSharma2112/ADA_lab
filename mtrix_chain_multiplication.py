def msm(n, p, m, s):
    for i in range(1, n):
        m[i][i] = 0
    
    for l in range(2, n):
        for i in range(1, n - l + 1):
            j = i + l - 1
            m[i][j] = float('inf')
            
            for k in range(i, j):
                q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
                
                if q < m[i][j]:
                    m[i][j] = q
                    s[i][j] = k
    
    return m, s

def validparen(s, i, j):
    if i==j:
        print(f'A{i}', end="")
    else:
        print("(", end="")
        validparen(s, i, s[i][j])
        validparen(s, s[i][j]+1, j)
        print(")", end="")

matrices = [2, 4, 2, 5, 6, 2]
n = len(matrices)

m = [[0] * n for _ in range(n)]
s = [[0] * n for _ in range(n)]

msm(n, matrices, m, s)
validparen(s, 1, 5)