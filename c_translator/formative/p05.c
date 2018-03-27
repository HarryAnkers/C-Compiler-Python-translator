int f(){
    return 5;
}

int f1(int a, int b){
    return a*b;
}

int f2(int A, int B, int C, int D){
    return A*B*C*D;
}

int main()
{
    return f()+f1(2,3)+f2(4,5,6,7);
}