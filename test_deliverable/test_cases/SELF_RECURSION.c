int function(int x){
    if(x==0){
        return x;
    }
    else{
        x--;
        return function(x);
    }
}