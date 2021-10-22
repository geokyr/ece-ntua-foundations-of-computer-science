def fastmodpower(a, n, p):
    res=1
    while (n > 0):
        if (n % 2 == 1):
            res = res * a % p
        n = n // 2
        a = a * a % p
    return res

def fermat_test(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(1,30):
        a = n - i
        if a > 1:
            if fastmodpower(a, n - 1, n) != 1:
                return False
            else:
                break
    return True

def fermat_test_slow(n):
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(1,30):
        a = n - i
        if a > 1:
            if pow(a, n - 1, n) != 1:
                return False
            else:
                break
    return True