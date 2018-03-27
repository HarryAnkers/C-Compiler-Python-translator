x=1

def f0():
    global x
    if(x):
        return

def main():
    global x
    f0()
    return 10

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
