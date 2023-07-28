//1. get non zero of 1st (n1) and 2nd (n2)
//2. start loop of 1st and inside start loop lof 2nd from i=j=3
//3. compare i and j indices of both and return smaller: 0 (equal)/1/2
//4. take sum array s1 as n1+n2
//5. write sum of 1st and second in sum array and increment both counters by 3 if 3 returned 0
//6.. welse rite smaller in sum array and increment smaller counter by 3  
//7.  once this ends you have counter of sum. write it in sum[2]
//8. now create another array s2 of size (sum[2]+1)*3
//9. copy all values from s1 to s2

#include <stdio.h>
int main(){
    int a[27]={6,6,8,0,0,15,0,3,22,0,5,-15,1,1,11,1,2,3,2,3,-6,4,0,91,5,2,28};
    int b[27]={6,6,8,0,0,15,0,4,91,1,1,11,2,1,3,2,5,28,3,1,22,3,2,-6,5,0,-15};
    int a1[6][6]={0};
    int b1[6][6]={0};
    int c1[6][6];
    // int i=3;
    // while (i<25){
    //     a1[a[i]][a[i+1]]=a[i+2];
    //     i+=3;
    // }
    for(int i=3; i<=24; i+=3){
        a1[a[i]][a[i+1]]=a[i+2];
    }
    for(int i=3; i<=24; i+=3){
        b1[b[i]][b[i+1]]=b[i+2];
    }
    // for(int i=0; i<6; i++){
    //     for(int j=0; j<6; j++){
    //         printf("%d ", a1[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
           c1[i][j]=a1[i][j]+b1[i][j];
        }
    }
    int non_zero=0;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(c1[i][j])
                non_zero++;
            printf("%d ", c1[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    int c[(non_zero+1)*3];
    c[0]=6;
    c[1]=6;
    c[2]=non_zero;
    int counter=3;
    for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            if(c1[i][j]){
                c[counter]=i;
                c[counter+1]=j;
                c[counter+2]=c1[i][j];
                counter+=3;
            }
        }
    }
    for(int i=0;i<(non_zero+1)*3;i++){
            printf("%d  ", c[i]);
    }
}

