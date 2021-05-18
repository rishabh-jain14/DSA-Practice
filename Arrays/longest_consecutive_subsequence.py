def findLongestConseqSubseq(arr, N):
        counter = 0
        visited = []
        for i in range(len(arr)):
            if arr[i] in visited:
                continue
            flag = 1
            curr = arr[i]
            i = 1
            count = 1
            while(flag == 1):
                visited.append(curr+i)
                if (curr+i) in arr:
                    count += 1
                    i += 1
                else:
                    flag = 0
            counter = max(counter, count)
        return counter

arr = [100, 200, 101, 102, 300, 301, 302, 400, 303, 305, 304, 405, 106, 103, 105, 104]
print(findLongestConseqSubseq(arr, len(arr)))
