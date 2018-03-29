def f(a, b, c, d):
    if(a):
        if(b):
            return 23
        else:
            return 34

def main():
    return f(1,2,3,4)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
