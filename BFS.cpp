#include<iostream>
using namespace std;
int n=5;
int arr[5],visited[5],queue[20],adjacent[5][5];
int rear=-1,front=-1;
void  enqueue();
int   dequeue();
void enqueue(int value)
{
 if(front==19)
 printf("the queue is filled\n");
 else if(front==-1&&rear==-1)
 {
  front=rear=0;
  queue[rear]=value;
}
 else
  {
	  rear=rear+1;
      queue[rear]=value;
  }
}
int dequeue()
{
	int value;
	if(front==-1&&rear==-1||(front>rear)){
	printf("the queue is empty  so dequeue cannot be performed\n");
    }
	else
	{
	 value=queue[front];
	 front=front+1;
     printf("the value dequeued is %d\n",value);
     }
}
bool queueempty(){
    if(front==-1&&rear==-1||(front>rear)){
	 return true;
    }
    else{
        return false;
    }
}
void BFS(int n,int i){//where i is index of n
   int w;
   visited[i]=1;
   enqueue(n);
   while(!queueempty()){
      w=dequeue();
      for(int j=0;j<n;j++){
          cout<<j<<endl;
          if(adjacent[i][j]==1 && !visited[j]){
            cout<<j<<"\n";
            enqueue(arr[j]);
            visited[j]=1;
            cout<<"This is in BFS\n";
            cout<<arr[j];}

      }
   }
}
int main(){
// cout<<"Enter the number of nodes\n";
// cin>>n;
 cout<<"enter the nodes of graph\n";
 for(int i=0;i<n;i++){
     cin>>arr[i];
 }
 for(int i=0;i<n;i++){
     visited[i]=0;
 }
 cout<<"Enter the adjacent matrix \n";
 for(int i=0;i<n;i++){
     for(int j=0;j<n;j++){
         cin>>adjacent[i][j];
     }
 }
 BFS(arr[0],0);
 return 0;
}