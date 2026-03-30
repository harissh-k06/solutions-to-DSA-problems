class Solution(object):
    def findLeastNumOfUniqueInts(self, arr, k):
        freq = sorted(Counter(arr).values())
        unique = len(freq)

        for f in freq:
            if k >= f:
                k -= f
                unique -= 1
            else:
                break

        return unique