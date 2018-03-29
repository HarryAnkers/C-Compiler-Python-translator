int f(int a, int b)
{
    int x=0;
    while(x<50){
        x=x+1;
    }
    while(x==0){
        x=x-1;
    }
    return x;
}

int main(){
    return f(1,2);
}
