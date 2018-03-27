def f(a,b):
	x=0
	While (1 and (x > 50)) :
		x=(x+1)

	While (0 or (x == 0)) :
		x=(x-1)

	return x

def main():
	return f(1,2)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
