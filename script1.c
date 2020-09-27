#include <stdio.h>
#include <math.h>
void main()
{
    int m=4, n=4, p, q, c, d, i, j,k;
    float sh=2;
    float first[10][10],mult1[10][10],mult2[10][10],mult3[10][10];
    float trans[4][4],trans2[4][4],scale[4][4],sum=0,sum2=0,sum3=0;
    
    printf("enter the values of object matrix\n");
    

for(d=0;d<n;d++)
{
    for(c=0;c<m-1;c++)
    {
        scanf("%f",&first[c][d]);
        first[m-1][d]=1;
    }
}
//back tranlation matrix
printf("\n");

for(i=0;i<4;i++)
{
 for(j=0;j<4;j++)   
 {
     if(i==j)
       trans[i][j]=1;
     else
       trans[i][j]=0;
       
     trans[0][3]=-1*first[0][3];
     trans[1][3]=-1*first[1][3];
     trans[2][3]=-1*first[2][3];
 }
}
//matrix multiplication

for(i=0;i<4;i++){
for(j=0;j<4;j++){
for(k=0;k<4;k++){
sum=sum+trans[i][k]*first[k][j];
}
mult1[i][j]=sum;
sum=0;
}
}
//scaling matrix
printf("\n");
for(i=0;i<4;i++)
{
 for(j=0;j<4;j++)   
 {
     if(i==j)
     {
       scale[i][j]=2;
     }
     else
     {
       scale[i][j]=0;
     } 
       scale[3][3]=1;
       
 }
    
}
//matrix multiplication
for(i=0;i<4;i++){
for(j=0;j<n;j++){
for(k=0;k<4;k++){
sum2=sum2+scale[i][k]*mult1[k][j];
}
mult2[i][j]=sum2;
sum2=0;
}
}

//forward translation matrix
printf("\n");


for(i=0;i<4;i++)
{
 for(j=0;j<4;j++)   
 {
     if(i==j)
     {
       trans2[i][j]=1;
     }
     else
     {
       trans2[i][j]=0;
     } 
     trans2[0][3]=first[0][3];
     trans2[1][3]=first[1][3];
     trans2[2][3]=first[2][3];
 }
}

for(i=0;i<4;i++){
for(j=0;j<n;j++){
for(k=0;k<4;k++){
sum3=sum3+trans2[i][k]*mult2[k][j];
}
mult3[i][j]=sum3;
sum3=0;
}
}
for(i=0;i<4;i++)
  {
    for(j=0;j<n-1;j++)
    printf("\n%0.1f",mult3[j][i]);
   
   }
}
