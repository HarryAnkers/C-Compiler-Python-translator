def main(a, b):
    x=0
    while(1 and (x<50)):
        x=x+1
    while(0 or (x==0)):
        x=x-1
    return x

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
