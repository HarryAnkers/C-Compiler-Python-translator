def f():
    return 5

def f1(a, b):
    return a*b

def f2( A, B, C, D):
    return A*B*C*D

def main():
    return f()+f1(2,3)+f2(4,5,6,7)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
