"""
The nth term of the sequence of triangle numbers is given by, tn = .5*n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position and adding these values we 
form a word value. For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle 
number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly two-thousand common 
English words, how many are triangle words?

"""
import re

def is_triangle_number(num):
    for n in range(1, 1000):
        tn = .5*n*(n+1)
        if tn > num:
            return False
        if tn == num:
            return True

def word_value(word):
    total = 0
    for letter in word:
        total += ord(letter) - 64
    return total

count = 0
f = open("words.txt")
for line in f:
    for word in re.split("[\",]", line):
        val = word_value(word)
        if is_triangle_number(val):
            count += 1
print count

