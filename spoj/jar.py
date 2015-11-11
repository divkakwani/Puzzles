
string = raw_input().split()
n = int(string[0])
q = int(string[1])

weights = [int(wt) for wt in raw_input().split()]

# stores (wt, list of number of pieces that can make up wt)
pieces_for_w = {0: []}

# stores the updated version of `pieces_for_w`
next_pieces_for_w = {}

for wt in weights:

    for key in pieces_for_w:
        # next_pieces_for_w[key] = pieces_for_w[key]

        if key + wt in pieces_for_w:
            next_pieces_for_w[key + wt] = pieces_for_w[key + wt]
        else:
            next_pieces_for_w[key + wt] = []

        for elt in pieces_for_w[key]:
            next_pieces_for_w[key + wt].append(elt+1)

    pieces_for_w = next_pieces_for_w


for query in xrange(q):
    x = input()
    if x not in pieces_for_w:
        print "That's impossible!"
    else:
        print ' '.join([str(i) for i in pieces_for_w[x]])
