{- The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143? -}

main = putStrLn $ show $ lpFact 600851475143

lpFact :: Integer -> Integer
lpFact x = head $ primeFactors x

primeFactors :: Integer -> [Integer]
primeFactors x = [y | y <- reverse [2..(round $ sqrt $ fromIntegral x)], x `mod` y == 0 && isPrime y]

isPrime :: Integer -> Bool
isPrime x
    | x == 2                  = True    --Prime if 2
    | x < 2 || x `mod` 2 == 0 = False   --Not prime if < 2 or even
    | otherwise = null [y | y <- reverse [2..(round $ sqrt $ fromIntegral x)], x `mod` y == 0]