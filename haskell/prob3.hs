{- The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143? -}

main = putStrLn $ show $ lpFact 600851475143

lpFact :: Integer -> Integer
lpFact x
    | isPrime x = 

isPrime :: Integer -> Bool
isPrime x
    | x == 2                  = True
    | x < 2 || x `mod` 2 == 0 = False
    | otherwise = null [y | y <- reverse [2..(round $ sqrt $ fromIntegral x)], x `mod` y == 0]

