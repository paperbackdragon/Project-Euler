number = 600851475143
root = int(round(600851475143**.5))
pair = 0
highest = 0

def isprime(n):
    nroot = int(round(n**.5))
    if(nroot < 2):
        return True         #small num--not prime
    if n % 2 == 0:
        return False        #even--not prime
    for i in range(nroot, 1, -1):
        if(n % i == 0):     #found a factor--not prime
            return False
    return True             #exited loop--prime

for i in range(root, 1, -1):
    if(number % i == 0):
        pair = number // i
        if(isprime(pair)):
#            print "pair is " + str(pair)
            if(pair > highest):
                highest = pair
        elif(isprime(i)):
#            print "i is " + str(i)
            if(i > highest):
                highest = i
print(highest)
