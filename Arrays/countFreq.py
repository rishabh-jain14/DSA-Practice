import collections

def countFreq(num, k):
    l = len(num)
    key = int(l/k)
    freq = collections.Counter(num)
    print(' '.join(map(str, [x for x in freq if freq[x] > key])))

countFreq([1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1]  , 4)