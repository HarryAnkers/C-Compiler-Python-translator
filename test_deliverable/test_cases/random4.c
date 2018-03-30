int random(){
    double x = 5;
    x += 0.5;
    x -= (3/2);
    x = x/4;
    double y = x-1;
    for(int i =0; i < 5; i++){
        y++;
        x=5-y;
    }
    return x;
}