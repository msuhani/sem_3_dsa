#include <stdio.h>
int main(){
    int n=5;
    int arr[5]={34, 76, 12, 45, 2};
    int swapped;
    
    for( int i=1; i<=n-1;i++ ){
        swapped=0;
        //no swapping;
        for(int j=0; j<=n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;

                swapped=1;
                //swapping occured;
            }
        }
        if(swapped==0)
            break;
    }
    for (int i=0; i<n; i++)
        printf( "%d ", arr[i]);
}