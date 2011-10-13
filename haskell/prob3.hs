isPrime :: Integer -> Bool
isPrime x
    | x == 2              = True
    | x < 2 || x `mod` 2 == 0 = False
    | otherwise = null [y | y <- [(round sqrt x)..2], x `mod` y == 0]

