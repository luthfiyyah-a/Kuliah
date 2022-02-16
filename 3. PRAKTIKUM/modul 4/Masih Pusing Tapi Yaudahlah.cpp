#include <bits/stdc++.h>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    stack<int> s;
    int A[101];
    
    cin >> N;
    
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    
    int Q, W;
    
    cin >> Q >> W;
    char q[6];
    
    int j=0; //untuk memasukkan data ke dalam stack saat "beri", agar tidak bertambah saat "nakam"    
    for(int i=0; i<Q; i++){
        
        cin >> q;
        
        if(strcmp(q, "beri")==0){
            s.push(A[j]);
            j++;
        }
        else if(strcmp(q, "nakam")==0){
            s.pop();
        }
    }
    
    int isi_stack = 0; //mengetahui ada berapa paket yang ada di dalam stack akhir
    int sum = 0; //jumlah yupi dalam stack
    while(!s.empty()){
        isi_stack++;
        sum = sum + s.top();
        s.pop();
    }
    
    if(sum==0 || sum > W){
        printf("YAH KOSONG DONG");
    }
    else{
        printf("%d %d", sum, isi_stack);
    }
    
    return 0;
}
