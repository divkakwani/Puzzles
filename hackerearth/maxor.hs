
import Data.Bits

-- solve :: (Num a) => [a] -> [a]

solve [] = 1 : replicate 127 0

solve (x:xs) = [(count !! i) + (count !! (i `xor` x)) |  i <- [0..127]]
                where count = solve xs

-- ans :: (Num a) => [a] -> b

nC2 (x:xs) = sum $ map (\x -> (x * (x - 1)) / 2) $ filter (> 1) xs

main = do
    n <- getLine
    numStrs <- sequence $ replicate ((read n)::Int) getLine
    let numbers = map (read :: String -> Int) numStrs
    print $ truncate $ nC2 $ solve $ numbers




