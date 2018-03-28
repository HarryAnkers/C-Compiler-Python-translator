int f(int a, int b)
{
    int x=0;
    while(a&&x<50){
        x=x+1;
    }
    while(a||x==0){
        x=x-1;
    }
    return x;
}

int main(){
    return f(1,2);
}