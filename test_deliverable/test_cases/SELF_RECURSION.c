int self(int x){
    x--;
    if(x==0){ return 0; }
    else if(x<0){return 2; }
    else{
        return self(x);
    }
    return 3;
}