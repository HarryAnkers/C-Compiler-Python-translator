def main():
	x=0
	condition=1
	conditionB=1
	conditionC=1
	conditionD=1
	if condition :
		x=(x+1)
	elif(conditionB) :
		x=(x+2)
	elif(conditionC) :
		x=(x+3)
	elif(conditionD) :
		x=(x+4)
	else :
		x=4
	return 0

# Boilerplat
if __name__ == "__main__":
    import sys
    ret=main()
    sys.exit(ret)
