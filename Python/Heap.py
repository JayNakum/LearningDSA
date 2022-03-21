def maxHeapify(arr, n, i):
    largest = i
    left = 2 * i
    right = 2 * i + 1

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        print(arr)
        arr[i], arr[largest] = arr[largest], arr[i]
        maxHeapify(arr, n, largest)


def heapSort(arr):
    heapSize = len(arr)

    for i in range(heapSize // 2 - 1, -1, -1):
        maxHeapify(arr, heapSize, i)

    for i in range(heapSize - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        maxHeapify(arr, i, 0)


if __name__ == '__main__':

    arr = [12, 11, 36, 17, 0, 6]
    heapSort(arr)
    heapSize = len(arr)
    print("Sorted array is")
    for i in range(heapSize):
        print("%d" % arr[i], end=" ")
