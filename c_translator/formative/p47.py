def f(a):
    if(a):
        return 1
    elif(a-1):
        return 0

def main():
    f(1)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
