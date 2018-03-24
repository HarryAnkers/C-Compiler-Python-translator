
void f2(int a1,int a2,int a3,int a4,int a5,int a6){
}

int f1()
{
    int a=1;
    {
        int b=2;
        {
            int c=3;
            int d=4;
            int e=5;
            {
                f2(1,2,3,4,5,6);
                return a+b+c;
            }
        }
    }
}

