def main(a, b, c, d):
    if(a):
        a=23
        return a
    elif(c):
        a=7
        return a

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
