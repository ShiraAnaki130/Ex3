#include <stdio.h>
#define NUMBERS 50
void shift_element(int* arr, int i){
    int prev= *arr;
    for(int j=0;j<i;j++){
        int nextValue= *(arr+j+1);
        *(arr+j+1)=prev;
        prev=nextValue;
    }
}
void insertion_sort(int* arr, int len){
    if(arr!=NULL){
        int count=0;
        int j;
        int* pointer=NULL;
        int currentNum;
        for(int i=1;i<len;i++){
            pointer=NULL;
            count=0;
            j=i-1;
            currentNum=*(arr+i);
            while(j>=0&&(*(arr+j)>currentNum)){
                count++;
                pointer=(arr+j);
                j--;

            }
            if(pointer!=NULL&&(count+1<=len)){
                shift_element(pointer,count);
                *(pointer)=currentNum;
            }     
        }
    }
   
}
int main(){
    int arr[NUMBERS]={0};
    int x;
    int i=0;
    while(i<NUMBERS){
        printf("Please enter a number\n");
        if(scanf("%d",&x)==1){
            *(arr+i)=x;
            i++;
        }
    }
    int* pointer=arr;
    insertion_sort(pointer,NUMBERS);
    for(int i=0;i<NUMBERS;i++){
        if(i==NUMBERS-1){printf("%d",*(arr+i));}
        else{printf("%d,",*(arr+i));}
    }
    return 1;
}