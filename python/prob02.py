fib = [1, 2]
x = sum(fib)
i = 2
answer = 0

#get fibonacci sequence
while x <= 4000000:
    fib += [x]
    x = fib[i] + fib[i-1]
    i += 1

#find even nums
for each in fib:
    if each % 2 == 0:
        answer += each
print(answer)

