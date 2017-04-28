def fib_to(n):
     fibs = [0, 1]
     for i in range(2, n+1):
         fibs.append(fibs[-1] + fibs[-2])
     return fibs


fib_to(20)
#get first 20 fib numb;

fib_to(40)[17]
#get 17th fib numb


def fib(n, computed = {0: 0, 1: 1}):
     if n not in computed:
         computed[n] = fib(n-1, computed) + fib(n-2, computed)
     return computed[n]

fib(400)
