#! /usr/bin/env/python3
import math
def factorize(n):
    divisors = [ d for d in range(2,int(math.sqrt(n))) if n % d == 0 ]
    print(divisors)

#def main():
factorize(337123)
