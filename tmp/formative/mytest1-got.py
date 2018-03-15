x=0

def main():
	global x
	x=(x+1)
	return x

y=0

z=0

def func():
	global x
	global y
	global z
	x=(x+y)
	return x

a=0

b=0

def thing():
	global x
	global y
	global z
	global a
	global b
	return a

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
