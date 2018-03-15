def main():
    x=0
    condition=true
    conditionB=true
    conditionC=true
    conditionD=true
    if condition :
        x=x+1
    elif conditonB :
        x=x+2
    elif conditonC :
        x=x+3
    elif conditonD :
        x=x+4
    else :
        x=4
    return 0

# Boilerplate
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)

