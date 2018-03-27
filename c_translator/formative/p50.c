int f(int a, int b)
{
    if(a){
        return 1;
    } else if(a-1){
        return 0;
    } else if(b){
        return 10;
    } else if(b-1){
        return 15;
    }
}

int main(){
    return f(1,2);
}