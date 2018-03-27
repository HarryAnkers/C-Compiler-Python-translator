def f(a, b):
    if(a):
        return 1
    elif(a-1):
        return 0
    elif(b):
        return 10
    elif(b-1):
        return 15
    else:
        return 5

def main():
    return f(1,2)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
