{- The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143? -}

main = putStrLn $ show $ lpFact 600851475143

--Returns the largest prime factor of x--
lpFact :: Integer -> Integer
lpFact x = head $ reverse $ primeFactors x

--Returns all the prime factors of x--
primeFactors :: Integer -> [Integer]
primeFactors x = [y | y <- candidates x, isFactor x y && isPrime y]

--Returns true if x is prime--
isPrime :: Integer -> Bool
isPrime x
    | x == 2                  = True    --Prime if 2
    | x < 2 || x `mod` 2 == 0 = False   --Not prime if < 2 or even
    | otherwise = null [y | y <- candidates x, isFactor x y]

--Returns true if y is a factor of x--
isFactor :: Integer -> Integer -> Bool
isFactor x y = x `mod` y == 0

--Returns a list of all integers from 2 to the square root of x--
candidates :: Integer -> [Integer]
candidates x = [2..(round $ sqrt $ fromIntegral x)]