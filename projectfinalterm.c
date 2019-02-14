#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int hold_move[8][8]={0};
int count_move[8][8]={0};
int count=0;

int check_legal_move(int a[][8],int dr,int dc,int row,int colum,int n){
    count++;
    if(n==2){
        n=1;
    }
    else{
        n=2;
    }
    if(dr+row > 8 || dr+row < 0 || dc+colum > 8 || dc+colum < 0 ){
        return 0;
    }
    if(a[row+dr][dc+colum]==n){
        return 0;
    }
    if(a[row+dr][dc+colum]==0){
        hold_move[row+dr][dc+colum]=9;
        count_move[row+dr][dc+colum]=count;
        count=0;
        return 1;
    }
    return check_legal_move(a,dr,dc,row+dr,colum+dc,n);
}

void check_homes(int a[][8],int n,int row,int colum,int *p,int *p1,int eval[][8]){
    int hold;
    for(int i=row-1;i<=row+1;i++){
        for(int j=colum-1;j<=colum+1;j++){
            if(a[i][j]==n){
                hold=check_legal_move(a,i-row,j-colum,i,j,n);
            }
        }
    }
}

void best_move(int eval[][8],int x,int y){

}



void maximum(int *p,int *p1,int eval[][8]){
    int max=-120,max1=-120;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(hold_move[i][j]==9){
                if(max<eval[i][j]){
                    max=eval[i][j];
                    *p=i;
                    *p1=j;
                }
            }
        }
    }
}

void findmove(int a[][8],int n,int eval[][8]){
    int x,y,x1,y1;
    int holdn;
    if(n==2){
        holdn=1;
    }
    else{
        holdn=2;
    }
    int hold,*ptox=&x,*ptoy=&y;
    int *ptox1=&x1,*ptoy1=&y1;
    int max=-120;
    int holdx,holdy;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(a[i][j]==n){
                check_homes(a,holdn,i,j,ptox,ptoy,eval);
            }
        }
    }
    maximum(ptox1,ptoy1,eval);
    printf("%d %d\n",*ptoy1,*ptox1);
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         printf("%d",hold_move[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("#\n");
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         printf("%d",count_move[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("#\n");
    // printf("%d %d",x1,y1);
    // a[*ptox1][*ptoy1]=n;
    // for(int i=0;i<8;i++){
    //     for(int j=0;j<8;j++){
    //         printf("%d",a[i][j]);
    //     }
    //     printf("\n");
    // }
}

int main(int argc, char const *argv[])
{
    int counter;
    int eval[8][8]={{ 120 ,-20 ,20 ,5 ,5 ,20 ,-20 ,120 },{-20 ,-40 ,-5 ,-5 ,-5 ,-5 ,-40 ,-20},{20 ,-5 ,15 ,3, 3 ,15 ,-5 ,20 },
        {5 ,-5 ,3 ,3 ,3 ,3 ,-5 ,5 },{5 ,-5 ,3 ,3 ,3 ,3 ,-5 ,5 },{ 20 ,-5 ,15 ,3 ,3 ,15 ,-5 ,20 },{ -20 ,-40 ,-5 ,-5 ,-5 ,-5 ,-40 ,-20 },
        {120 ,-20 ,20 ,5, 5 ,20 ,-20 ,120}
    };
    int n=argv[9][0]-48;
    int a[8][8];
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            a[i][j]=argv[i+1][j]-48;
        }
    }
    findmove(a,n,eval);
    return 0;
}






















