
import enchant

d = enchant.Dict("en_US")


s = input()

memo = [ [] for _ in range(len(s)) for _ in range(len(s))]

def get_all_splits(s):
    splits = set([])
    
    if d.check(s):
        splits.add(s)

    # otherwise, split the string into two such that each
    # of the substring can be further split
    for i in range(1, len(s)):
        lsplits = split(s[:i])
        rsplits = split(s[i:])

        for a in lsplits:
            for b in rsplits:
                splits.append(a + ' ' + b)

    return splits



print(split(s))
