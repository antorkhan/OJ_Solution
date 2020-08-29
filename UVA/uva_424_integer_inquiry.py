sum = 0
while True:
    try:
        n1 = int(input())
        if n1 == 0:
            break
        else:
            sum += n1
    except EOFError:
        break
print(sum)