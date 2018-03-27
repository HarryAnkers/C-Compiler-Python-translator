int f(int a, int b, int c, int d)
{
    if(a){
        return 1;
    } 
    if(b){
        return 15;
    }
    if(c){
        return 22;
    }
    if(d){
        return 50;
    }
}

int main(){
    return f(1,2,3,4);
}