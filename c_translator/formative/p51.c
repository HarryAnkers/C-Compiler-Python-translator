int f(int a, int b)
{
    if(a){
        return 1;
    } else if(b-1){
        return 15;
    }
}

int main(){
    return f(1,2);
}