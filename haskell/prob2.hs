fib :: Int -> Int -> [Int] -> [Int]
fib x y zs 
    | x + y > 4000000 = zs
    | otherwise = fib y (x+y) (zs ++ [x+y])

main = putStrLn $ show $ sum (filter even (fib 1 2 [1,2]))

