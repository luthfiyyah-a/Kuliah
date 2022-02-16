#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define ARR 101
using namespace std;

vector <int> adjList[ARR];
int visited[ARR];

void dfs(int curVertex)
{
    //menandai bahwa vertex ini sudah pernah dikunjungi
    visited[curVertex] = 0; //Perhatikan baris ini untuk trivia question
    for (int i = 0 ; i < adjList[curVertex].size() ; i++) //menelusuri daftar vertex yang terhubung dengan curVertex
    {
        int nextVertex = adjList[curVertex][i];
        
        if (visited[nextVertex]) //mengecek jika belum dikunjungi
        {
            dfs(nextVertex);
            //do something
        }
    }
    //do something
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    for(int i=1; i<=100; i++){
        scanf("%d", &visited[i]); //iya, ditampung ke visited. agar yang '0' tidak perlu ditelusuri nantinya
        //memasukkan edge a-b
        if(i%10 != 1){ //ketika posisi vertex bukan yang di paling kiri. karena kalau paling kiri tidak dihubungkan ke node sebelumnya
            adjList[i].push_back(i-1);
            adjList[i-1].push_back(i); 
        }
        
        if(i>10){ //ketika posisi vertex bukan yang paling atas, karena paling atas udh gaada tetangga atasnya.
            adjList[i].push_back(i-10);
            adjList[i-10].push_back(i);
        }
        
        if(i%10 != 0){ //ketika posisi vertex bukan yang paling kanan
            adjList[i].push_back(i+1);
            adjList[i+1].push_back(i);
        }
        
        if(i<=90){
            adjList[i].push_back(i+10);
            adjList[i+10].push_back(i);
        }
    }
        
    int pulau = 0;
    
    for(int i=1; i<=100; i++){
        
        if(visited[i] == 1){
            dfs(i);
            pulau++;
        }
    }
    
    printf("%d", pulau);
    
    return 0;
}
