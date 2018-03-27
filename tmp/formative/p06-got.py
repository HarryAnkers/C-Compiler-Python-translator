e=5
def f():
	global e
	return (5+e)

_f_=7
def f1(a,b):
	global e
	global _f_
	return ((e+(a*b))+_f_)

_=23
def f2(A,B,C,D):
	global e
	global _f_
	global _
	return (((e+_f_)+(((A*B)*C)*D))+_)

_123=123
def main():
	global e
	global _f_
	global _
	global _123
	return ((((((e+_f_)+_)+f())+f1(2,3))+f2(4,5,6,7))+_123)

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
