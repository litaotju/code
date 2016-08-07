N = int(raw_input())
M = int(row_input())

value = []
for i in range(N):
    row = []
    for j in range(M):
        val = int(raw_input())
        row.append(val)
    value.append(row)

print value