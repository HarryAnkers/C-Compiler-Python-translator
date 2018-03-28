z=0
def f():
	global z
	return 5

def main():
	global z
	return f()

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
