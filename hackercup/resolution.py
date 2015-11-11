t = input()
for i in range(t):
	p = input()
	c = input()
	f = input()
	n = input()
	subseq_sum = set([(0, 0, 0)])
	foods = []
	for _ in range(n):
		foods.append((input(), input(), input()))
	for a_sum in subseq_sum:
		for food in foods:
			subseq_sum.add((a_sum[0] + food[0], a_sum[1] + food[1], a_sum[2] + food[2]))
	if (p, c, f) in subseq_sum:
		print "Case #", i, ": yes"
	else:
		print "Case #", i, ": no"
	
	
