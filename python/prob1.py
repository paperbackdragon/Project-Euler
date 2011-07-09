answer = 0
for x in range(1, 1000):            #for each number from 1 to 1000
    if x % 5 == 0 or x % 3 == 0:    #if multiple of 5 or 3
        answer += x                 #add to answer
print(answer)

#print sum(x for x in range(1000) if (x % 3) == 0 or (x % 5) == 0)
#print sum(range(0, 1000, 3)) + sum(range(0, 1000, 5)) - sum(range(0, 1000, 15))

