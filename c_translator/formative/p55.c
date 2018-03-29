int f(int a, int b, int c, int d)
{
    if(a)
        if(b)
            if(c)
                if(d)
                    return 1;
                else
                    return 2;
            else
                return 3;
        else
            return 4;
    else
        return 5;
}

int main(){
    return f(1,2,3,4);
}