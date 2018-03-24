int f1(int a1,int a2,int a3,int a4)
{
    return a1+a2+a3+a4;
}

int f2(){
    f1(10,11,12,13);
    f1(11,22,33,44);
    return f1(1,2,3,4);
}

void f3(){
}

int f4(){
    f3();
    return 1;
}
