x=0

def f():
	x=(x+1)
	return x

def main():
	return (f()+f())

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
