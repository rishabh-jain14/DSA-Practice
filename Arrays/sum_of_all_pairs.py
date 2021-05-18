import collections

print("Please enter a list of numbers : ", end = '')
arr = list(map(int, input().split()))
print("Now, enter the value of k : ", end= '')
k = int(input())
c = 0
frequency = dict(collections.Counter(arr))
print(frequency)
for x in arr:
    rem = k - x
    if rem in frequency:
        if rem == x:
            c += frequency[rem] - 1
        else:
            c += frequency[rem]
c = int(c/2)
print(c)