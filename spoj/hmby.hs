
readInt s = (read s) :: Integer

getNumList l = map readInt (words l)



main :: IO ()
main = do
       l <- getLine
       let nums = getNumList l
       let coefficients = take 5 nums
       let w = last nums
       let powersOf2 = [2, 4, 8, 16, 32]
       let totalMoney = foldl (+) 0 (zipWith (*) powersOf2 coefficients)
       if (w `mod` 2 == 0) && (w <= totalMoney) then putStr "YES" else putStr "NO"
