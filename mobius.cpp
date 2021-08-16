void mobiusFunction(){
    memset(isPrime, true, sizeof(isPrime));
    for(int i=1; i<LIMIT; i++) mobius[i]=1;
    for(long long int i=2; i<LIMIT; i++){
        if(isPrime[i]){
            for(long long int j=i+i; j<LIMIT; j+=i){
                isPrime[j]=false;
                mobius[j]*=-i;
            }
            for(long long int j=i*i; j<LIMIT; j+=i*i){
                mobius[j]=0;
            }
            mobius[i]*=-i;
        }
    }
    for(int i=1; i<LIMIT; i++){
        if(mobius[i]==i) mobius[i]=1;
        else if(mobius[i]==-i) mobius[i]=-1;
        else mobius[i]=0;
    }
}

