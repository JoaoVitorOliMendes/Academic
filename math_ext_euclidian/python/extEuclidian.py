def extEuclidian(x, y):

    s = ti = 1
    si = t = quo = 0

    while y != 0:
        quo = x // y
        x, y = y, x % y

        s, si = si, s - quo * si
        t, ti = ti, t - quo * ti
    return s, t, x

messageString = input('Digite dois numeros: ').split()
p, q = int(messageString[0]), int(messageString[1])

print(extEuclidian(p, q))