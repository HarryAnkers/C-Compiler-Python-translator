int e = 5;

int f(){
    return 5+e;
}

int _f_ = 7;

int f1(int a, int b){
    return e+a*b+f;
}

int _ = 23;

int f2(int A, int B, int C, int D){
    return e+f+A*B*C*D+_;
}

int _123 = 123;

int main()
{
    return e+f+_+f()+f1(2,3)+f2(4,5,6,7)+_123;
}