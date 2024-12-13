def mergeArrays(a, b):
    n = len(a)
    m = len(b)

    # Initial gap
    gap = (n + m + 1) // 2

    while gap > 0:
        print(a)
        print(b)
        print(gap)
        i = 0
        # Compare elements in the first array
        while i + gap < n:
            if a[i] > a[i + gap]:
                a[i], a[i + gap] = a[i + gap], a[i]
            i += 1

        # Compare elements between the two arrays
        j = gap - n if gap > n else 0
        while i < n and j < m:
            if a[i] > b[j]:
                a[i], b[j] = b[j], a[i]
            i += 1
            j += 1

        # Compare elements in the second array
        j = 0
        while j + gap < m:
            if b[j] > b[j + gap]:
                b[j], b[j + gap] = b[j + gap], b[j]
            j += 1

        # Reduce the gap
        gap = (gap + 1) // 2 if gap > 1 else 0


a = [1, 3, 5, 7]
b = [0, 2, 6, 8, 9]

mergeArrays(a, b)
print(a)
print(b)
