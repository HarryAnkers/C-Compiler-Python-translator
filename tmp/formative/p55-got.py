def f(a,b,c,d):
	if (a) :
		if (b) :
			if (c) :
				if (d) :
					return 1
				else :
					return 2

			else :
				return 3

		else :
			return 4

	else :
		return 5


def main():
	return f(1,2,3,4)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
