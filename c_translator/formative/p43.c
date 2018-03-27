int main()
{
    int z;
    int x=4;
    {
        int y=5;
        z=x+y;
    }
    {
        int a=34;
        z=a+z;
    }
    return z;
}