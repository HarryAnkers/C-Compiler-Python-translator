int f(int a, int b, int c, int d)
{
    if(a)
        if(b)
            return 23;
        else
            return 34;
}

int main(){
    return f(1,2,3,4);
}