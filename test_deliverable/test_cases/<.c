int func(){
    int a=-1;
    int b=0;
    int c=1;
    int d=2;
    
    if(a<a){
        return 2;
    }else{
        if(a<b){
            if(a<c){
                if(c<d){
                    if(b<b){
                        return 3;
                    } else {
                        if(c<a){
                            return 1;
                        } else{
                            return 10;
                        }
                    }
                }
            }
        }
    }
    
    return 20;
}

