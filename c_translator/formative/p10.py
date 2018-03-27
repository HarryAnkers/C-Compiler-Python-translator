def f0( a, b, c, d, e, f):
    return a-b-c-d-e-f

def f1(a):
    1+34+535

def main():
    f1(f0(1,2,3,4,5,6))
    return f0(1,2,3,4,5,6)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
