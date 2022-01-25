#include<stdio.h>
#include<stdlib.h>

void worker(int x,int y,int x_no, int y_no , int arr[][x*y]) {
    
    int i,sum=0,max;
    float avg;
    max=arr[0][y_no];
    
    for(i=0;i<10;i++) {
        sum=sum+arr[i][y_no];
        if(max<arr[i][y_no]) {
            max=arr[i][y_no];  //find maximum marks 
        }
    }

    avg=sum/10.0;  //calculate avg marks for homeworks
    printf("In chapter %d Homework %d : \n",x_no+1,y_no+1);
    printf("average:%f\t maximum: %d\n",avg,max);
}

void manager(int x,int y,int x_no,int arr[][x*y]) {
    int i,j;
    for(i=x_no*y,j=0;j<y;i++,j++)//passing homework no for chapter no=x_no
        worker(x,y,x_no,i,arr);
}

int main() {
    FILE *fp;
    int x,y,i=0,j=0;
    printf("Number of chapters : ");
    scanf("%d",&x);
    printf("Number of Homework : ");
    scanf("%d",&y);

    int a[10][x*y];  //total no of columns will be x*y
    fp=fopen("data.txt","r");

    for(i=0;i<10;i++) {
        for(j=0;j<x*y;j++) {
            fscanf(fp,"%d ",&a[i][j]); //storing file contents into array
        }
    }

    for(i=0;i<10;i++) {
        for(j=0;j<y*x;j++) {
        printf("%d\t",a[i][j]);
        }
        printf("\n");
    }

    for(i=0;i<x;i++)
        manager(x,y,i,a);//created manager function 

    fclose(fp);//closing of file
}