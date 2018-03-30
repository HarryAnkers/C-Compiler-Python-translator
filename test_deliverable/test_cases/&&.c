int func(){
    int a=1;
    int b=0;
    if(a&&a){
        if(a&&b){
            return 1;
        } else {
            if(b&&b){
                return 2;
            } else {
                return 10;
            }
        }
    }
    return 20;
}
