{- A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.

 Find the largest palindrome made from the product of two 3-digit numbers. -}

import Data.Char

--Print answer
main = putStrLn $ show $ maxPal

--Find largest palindrome
maxPal :: Integer
maxPal = maximum [x | x <- palProducts threeDigit, isPalindrome x]

--Figure out if a number is a palindrome
isPalindrome :: Integer -> Bool
isPalindrome x = (numToList x) == (reverse $ numToList x)

--Find products of all combinations of two 3-digit numbers
palProducts :: [Integer] -> [Integer]
palProducts x = concatMap (\y -> map (y*) x) x

--Convert a number into a list of its digits
numToList :: Integer -> [Int]
numToList x = map digitToInt (show x)

--All 3-digit numbers
threeDigit :: [Integer]
threeDigit = [100..999]

