int random(int x, int y){
    x = 5;
    do{
        x--;
        y=x;
    }while(y!=0);
    if (x==0){
        return y;
    }
    return 3;
    
}