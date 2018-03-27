int f(int a, int b, int c, int d)
{
    if(a){
        a=1;
    }
    if(b){
        a=2;
    }
    if(c){
        a=3;
    }
    if(d){
        a=4;
    }
    return a;
}

int main(){
    return f(1,2,3,4);
}