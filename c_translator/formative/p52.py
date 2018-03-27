def main(a, b, c, d):
    if(a):
        return 1
    if(b):
        return 15
    if(c):
        return 22
    if(d):
        return 50

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
