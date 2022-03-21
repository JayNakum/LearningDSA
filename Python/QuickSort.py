def partition(Array: list, beg: int, end: int) -> int:
    pivot = Array[end]
    i = beg - 1
    for j in range(beg, end):
        if (Array[j] <= pivot):
            i += 1
            # exchange(Array[i], Array[j])
            temp = Array[i]
            Array[i] = Array[j]
            Array[j] = temp

    # exchange(Array[i + 1], Array[end])
    Array[i + 1], Array[end] = Array[end], Array[i + 1]
    return i + 1


def quickSort(Array: list, beg: int, end: int) -> None:
    if (beg < end):
        # print(Array)
        pivot = partition(Array, beg, end)
        quickSort(Array, beg, (pivot - 1))
        quickSort(Array, (pivot + 1), end)


if __name__ == '__main__':
    Array = [7, 8, 16, 1, 2, 5]
    print('Unsorted Array:')
    print(Array)
    quickSort(Array, 0, len(Array) - 1)
    print('Unsorted Array:')
    print(Array)