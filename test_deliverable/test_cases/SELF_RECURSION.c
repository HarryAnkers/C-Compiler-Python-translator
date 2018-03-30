int self(int x){
    if(x>0){
        x--;
        return self(x);
    } else {
        return x;
    }
}
