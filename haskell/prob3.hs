isPrime :: Integer -> Bool
isPrime x
    | x == 2                  = True
    | x < 2 || x `mod` 2 == 0 = False
    | otherwise = null [y | y <- reverse [2..(round (sqrt (fromIntegral x)))], x `mod` y == 0]

