#include <bits/stdc++.h>
#include <cmath>
#include <stdio.h>
#define MAX 100000
using namespace std;

vector <int> adjList[MAX];
bool visited[MAX];
// int start;

int power(int x, int y){
    int hasil = 1;
    for(int i=0; i<y; i++){
        hasil = x * hasil;
    }
    return hasil;
}

int bfs(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = 1;
    int total = 0; //total hari
    int jumlah; //jumlah hari untuk menyebarkan sapi dari suatu node ke tetangganya (yang belum divisit)
    
    while (!q.empty()) // ada yang tau kenapa seperti ini?
    {
        int curNode = q.front();
        q.pop();
        
        int jumlah_tetangga = 0;
        for (int i = 0 ; i < adjList[curNode].size() ; i++) // sama seperti DFS
        {
            int nextNode = adjList[curNode][i];
            if (!visited[nextNode])
            {
                q.push(nextNode);
                visited[nextNode] = 1; //Perhatikan baris ini untuk trivia question
                jumlah_tetangga++;
            }
        }
        
        //ini dapet dari perumusan setelah diobservasi
        for(int k=0; k<=17; k++){
            if(jumlah_tetangga < power(2, k)){
                jumlah = jumlah_tetangga + k;
                // printf("jumlah = %d\n", jumlah);
                break;
            }
        }
        
        total += jumlah;
    }
    
    return total;
}


int main(){

    int n;
    int a, b;
    
    cin >> n;
    
    for(int i = 0; i<n-1; i++){
        //memasukkan edge a-b
        cin >> a >> b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }
    
//     //cari vertex yang paling banyak tetangganya
//     int jumlah_max, index_max;

//     jumlah_max = index_max = 0;
//     for(int i=1; i<=n; i++){
//         if(jumlah_max < adjList[i].size()){
//             jumlah_max = adjList[i].size();
//             index_max = i;
//         }
//     }
    
    // start = index_max;
    
    cout << bfs(1);

    return 0;
}

