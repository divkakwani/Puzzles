

main = do
    rs <- sequence $ replicate 3 getLine
    let nums = map (read::String->Int) rs
    print nums
