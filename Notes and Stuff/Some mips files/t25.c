void f(){}

int f1(int a1,int a2,int a3,int a4)
{
    return a1+a2+a3+a4;
}

int f2(int a1,int a2,int a3,int a4,int a5,int a6)
{
    return a1+a2+a3+a4+a5+a6;
}

int f3(int a1,int a2,int a3,int a4,int a5,int a6,int a7,int a8)
{
    return a1+a2+a3+a4+a5+a6+a7+a8;
}

int f4(){
    f();
    int a = f1(1,2,3,4);
    int b = f2(5,6,7,8,9,10);
    int c = f3(11,12,13,14,15,16,17,18);
    return a+b+c;
}
