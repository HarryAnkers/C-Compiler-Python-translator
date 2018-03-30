int func(){
    int x=1;
    int y=0;
    if(x!=y){
        if(x!=x){
            return 1;
        }else{
            if(y!=y){
                return 2;
            }else{
                return 10;
            }
        }
    }
    return 20;
}

