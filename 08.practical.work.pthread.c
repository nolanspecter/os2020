#include <stdio.h>
#include <pthread.h>

void *threadFunc1(void *args){
    for(long long int i=1; i<=1000000; i++){
        if(i==1||i==2){
            printf("%lld (Prime)\n",i);
            }
        else{
            int count = 0;
            for(long long int j=1; j<=i; j++){
                if (i%j==0){
                    count++;
                    }
                }
            if(count==2){
                printf("%lld (Prime)\n", i);
            }
        }
    }
}

void *threadFunc2(void *args){
	long long int t1 = 0, t2 = 1, nextTerm;
    	for (long long int i = 1; i <= 1000000; ++i) {
        	printf("%lld (Fibo)\n ", t1);
        	nextTerm = t1 + t2;
        	t1 = t2;
        	t2 = nextTerm;
    }

}


int main(){
	pthread_t tid1, tid2;
	pthread_create(&tid1, NULL, threadFunc1, NULL);
	pthread_create(&tid2, NULL, threadFunc2, NULL);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}

