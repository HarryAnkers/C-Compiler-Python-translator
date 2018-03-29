def main():
	x=3
	y=4
	z=((x*((y+((x*x)*y))+x))*y)
	return (z+((x*((y+((x*x)*y))+x))*y))

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
