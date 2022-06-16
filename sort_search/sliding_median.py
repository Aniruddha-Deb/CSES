from bisect import insort, bisect
import math
import heapq

def main():

    n, k = [int(i) for i in input().split(" ")]
    A = [int(i) for i in input().split(" ")]

    lo, hi = [], []
    heapq.heappush(lo, -A[0])

    for a in A[1:k]:
        if a > -lo[0]:
            heapq.heappush(hi, a)
        else:
            heapq.heappush(lo, -a)
        if len(hi) > len(lo):
            himin = heapq.heappop(hi)
            heapq.heappush(lo, -himin)
    
    print(-lo[0], end=" ")
    for i in range(n-k):
        if A[i] in lo: # tricky part!!!
            lo.remove()
        if a > lomax:
            hi.append(a)
            himin = min(himin, a)
        else:
            lo.append(a)
            lomax = max(lomax,a)
        if len(hi) > len(lo):
            lo.append(himin)
            lomax = himin
            himin = min(hi)


    print()

if __name__ == '__main__':
    main()