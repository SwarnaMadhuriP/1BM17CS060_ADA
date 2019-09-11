#include<iostream>
using namespace std;
#define size 3
int a[3],queue[3],visited[3],adjacent[3][3],front=-1,rear=-1;
void enqueue(int val){
   if(rear==size-1){
     cout<<"Queue Filled\n";}
   else if(front==-1 && rear==-1){
      front=rear=0;
      queue[rear]=val;}
   else{
      rear=rear+1;
      queue[rear]=val;}
  }
int dequeue(){
   int value;
   if((front==-1 && rear==-1)|| front>rear)
     {cout<<"queue is empty\n";
       return -1;
      }
    else{
     value=queue[front];
     front=front+1;
     return value;
    }
  
}
bool isempty(){

   if((front==-1 && rear==-1)|| front>rear)
     {
      return true;}
    return false;
     }
  
void BFS(int source,int k){
  int val1,index=k;//index is the index of the value dequeued.
  visited[k]=1;
  enqueue(source);
  cout<<source<<" ";
  while(!isempty()){
        val1=dequeue();
            for(int i=0;i<3;i++){
            if(adjacent[index][i]==1 && !visited[i]){
             enqueue(a[i]);
             cout<<a[i]<<" ";
           }
         }
   }
}


int main(){
  cout<<"enter nodes\n";
  for(int i=0;i<3;i++)
  { 
   cin>>a[i];}
  int source,index;
  cout<<"enter source and index\n";
  cin>>source>>index;
  for(int i=0;i<3;i++){
    visited[i]=0;}
  cout<<"Enter Adjacent matrix\n";
  for(int i=0;i<3;i++)
  {
   for(int j=0;j<3;j++){
     cin>>adjacent[i][j];}}
   BFS(source,index);
  return 0;
}
