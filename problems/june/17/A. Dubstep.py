import sys, threading, time
from random import *
from math import ceil, log2, log10, remainder, gcd
from bisect import bisect_left as bl, bisect_right as br
from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
from itertools import permutations, combinations

inf = float('inf')
ninf = float('-inf')
mod = 10 ** 9 + 7

def li(): return list(map(int, input().split()))
def mi(): return map(int, input().split())
def ii(): return int(input())
def si(): return input()

def solve():
    s = si()
    s = s.replace("WUB", " ").strip()
    ans = []
    for c in s:
        if c == " " and len(ans) and ans[-1] == c: continue
        ans.append(c)
    print("".join(ans))

def main():
    t = 1
    for i in range(t):
        solve()

if __name__ == "__main__":
    main()

    # sys.setrecursionlimit(1 << 30)
    # threading.stack_size(1 << 27)
    # main_thread = threading.Thread(target=main)
    # main_thread.start()
    # main_thread.join()


