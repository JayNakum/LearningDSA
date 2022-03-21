for _ in range(int(input())):
    num = int(input())
    arr = list(map(int,input().split()))
    even, odd = [], []

    for i in arr:
        if i % 2 == 0:
            even.append(i)
        else:
            odd.append(i)

    if even == sorted(even) and odd == sorted(odd):
        print("yes")
    else:
        print("no")