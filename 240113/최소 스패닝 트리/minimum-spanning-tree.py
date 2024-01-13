n, m = map(int, input().split())
arr = []
for i in range(m):
    a, b, c = map(int, input().split())
    arr.append([a, b, c])

arr.sort(key=lambda x:x[2])

uf = [i for  i in range(n+1)]

def find(x):
    if x == uf[x]:
        return x
    uf[x] = find(uf[x])
    return uf[x]

def union_(a, b):
    a = find(a)
    b = find(b)
    uf[b] = a

answer = 0

for i in range(m):
    a = arr[i][0]
    b = arr[i][1]
    c = arr[i][2]

    if find(a) == find(b):
        continue

    union_(a, b)
    answer += c

print(answer)