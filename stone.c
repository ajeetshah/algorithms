#include<stdio.h>
#define SIZE 20
int main(){
       int i;
       int j;
       int W[SIZE];
       int t;
       int n;
       
       scanf("%d",&n);
       
       for(i=0;i<n;i++){
       	scanf("%d",&W[i]);                 
       }
       
       for(i=0;i<n;i++){
       	for(j=i+1;j<n;j++){
        	if(W[i]>W[j]){
                	t = W[i];
                        W[i] = W[j];
                        W[j] = t;
                 }
        }                 
       }
       t = W[n-1];
       for(i=n-1;i>0;i--){
       	if (t>0){
        	t = t - W[i-1];
        }
        else if (t<0){
                t = W[i-1] + t;          
        }
        else {
        	t = W[i-1];     
        }      
       }
	printf("%d",t);
	return 0;
}

