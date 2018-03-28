def main():
	x=0
	y=1
	z=((x and y) and y)
	return z

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
