int f(int a, int b, int c, int d)
{
    if(a)
        a=23;
        return a;
    else if(c)
        a=7;
        return a;
}

int main(){
    return f(1,2,3,4);
}