int f(int a, int b, int c, int d)
{
    if(a)
        if(b)
            return 23;
        else if(c)
            return 7;
}

int main(){
    return f(1,2,3,4);
}