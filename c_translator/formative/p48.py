def f(a):
    if(a):
        return 1
    elif(a-1):
        return 0
    else:
        return 5

def main():
    return f(1)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
