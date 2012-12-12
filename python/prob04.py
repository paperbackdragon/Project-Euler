#The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
#Find the largest palindrome made from the product of two 3-digit numbers.
#current solution takes 30 secs to compute!
num = 999
n = num
m = num
pd = 0
largest = 0

def ispalindrome(pd):
    isodd = False
    stack = []
    strn = list(str(pd))
    i = len(strn) / 2
    
    if len(strn) % 2 != 0:
        isodd = True
    for j in range(i):
        stack.append(strn.pop())
    if(isodd):
        strn.pop()
    for k in range(len(stack)):
        if stack.pop() != strn.pop():
            return False
    return True
        
for x in range(n, 1, -1):
    for y in range(m, 1, -1):
        pd = n*m
        if ispalindrome(pd) and largest < pd:
            largest = pd
        m = m-1
    m = num
    n = n-1

print largest

