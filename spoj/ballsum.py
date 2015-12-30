
def gcd(a, b):  return a if b == 0 else gcd(b, a%b)

while True:
    n, k = map(int, input().split())
    if n == -1: break
    nume = (k*k)//4 - k//2 if k%2 == 0 else ((k-1)*(k-1))//4
    deno = (n*(n-1))//2
    g = gcd(deno, nume)
    if nume == 0:   print(0)
    else:   print(str(nume//g) + '/' + str(deno//g))
