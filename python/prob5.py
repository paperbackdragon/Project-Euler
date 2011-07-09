#2520 is the smallest number that can be divided by each of the numbers from 1 to 10 w/out remainder.
#What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#i = 2520 

#def divby(n):
#    for x in range(1, 21):
#        if n % x != 0:
#            return False
#    return True

#while divby(i) == False:
#    print i
#    i += 2520

#print i
        
#answer from boards:
i = 1
for k in range(1, 21):
    if i % k > 0:
        for j in range(1, 21):
            if (i*j) % k == 0:
                print str(i) + " * " + str(j) + " = " + str(i*j)
                i *= j
                break
print i                



