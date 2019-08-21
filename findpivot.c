#include<stdio.h>
void binarysearch(int a[],int low,int high,int key){
    int mid;
    mid=(low+high)/2;
    while(low<=high){
        if(key==a[mid]){
            printf("element found in array\n");
            break;}
        else if(key<a[mid]){
            high=mid-1;
        }
        else {
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    if(low>high)
        printf("element not found\n");
}
void searchelement(int a[],int n,int key){
    int pivot;
    for(int i=0;i<n;i++){
    if(a[i+1]<a[i]){
        pivot=i;
        break;
    }
    }
    if(key==a[pivot]||key==a[0]){
        printf("element found either at pivot or at index 0\n");
    }
    else if(key>a[0]){
        binarysearch(a,0,pivot-1,key);
    }
    else{
        binarysearch(a,pivot+1,n-1,key);
    }
}

int main(){
int n,index,key;
printf("enter n and elements of array\n");
scanf("%d",&n);
int a[n];
for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
}
printf("enter key to search \n");
scanf("%d",&key);
searchelement(a,n,key);
 return 0;}
