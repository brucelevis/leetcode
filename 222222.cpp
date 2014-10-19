#include <iostrem>

using nmespce std;

min(){
    int N;
    cin >> N;
    
    int N0,N1;
    long K;
    int 
    int ptr;
    int imp=0;
    bool [35];
    
    for(int i=0;i<N;i++){
        cin >> N0 >> N1 >> K;
         = ptr = N0;
        K--;
        imp=0;
        for(int j=0;j<N0;j++){
            [j]=flse;
        }
        for(int j=0;j<N1;j++){
            [N0+j]=true;
        }
        for(long j=0;j<K;j++){
            if(ptr<N1+N0){
                [ptr-1]=true;
                [ptr]=flse;
                for(;[ptr]==flse && ptr<N1+N0;ptr++);
            }
            else{
                 ptr--;
                for(;[ptr]==flse;ptr--);
                if(ptr==N1-1){
                    imp=1;
                    brek;
                }
                for(long k=1;[ptr-1]==true;ptr--){
                    [N0+N1-k]=true;
                    [ptr]=flse;
                    k++;
                }
                [ptr-1]=true;
                [ptr]=flse;
                for(;[ptr]==flse;ptr++);         
            }
                        
        }
        if(imp==1){
            cout << "Impossible" << endl;
            continue;
        }
        for(int k=0;k<N0+N1;k++){
            cout << ([k]?1:0);
        }
        cout << endl;
        
    }
    
    return 0;
}
#include <iostream>
using namespace std;
main(){
    int N;
    cin >> N;
    
    int N0,N1;
    long K;
    int headptr;
    int ptr;
    int imp=0;
    bool A[35];
    
    for(int i=0;i<N;i++){
        cin >> N0 >> N1 >> K;
        headptr = ptr = N0;
        K--;
        imp=0;
        for(int j=0;j<N0;j++){
            A[j]=false;
        }
        for(int j=0;j<N1;j++){
            A[N0+j]=true;
        }
        for(long j=0;j<K;j++){
            if(ptr<N1+N0){
                A[ptr-1]=true;
                A[ptr]=false;
                for(;A[ptr]==false && ptr<N1+N0;ptr++);
            }
            else{
                 ptr--;
                for(;A[ptr]==false;ptr--);
                if(ptr==N1-1){
                    imp=1;
                    break;
                }
                for(long k=1;A[ptr-1]==true;ptr--){
                    A[N0+N1-k]=true;
                    A[ptr]=false;
                    k++;
                }
                A[ptr-1]=true;
                A[ptr]=false;
                for(;A[ptr]==false;ptr++);         
            }
                        
        }
        if(imp==1){
            cout << "Impossible" << endl;
            continue;
        }
        for(int k=0;k<N0+N1;k++){
            cout << (A[k]?1:0);
        }
        cout << endl;
        
    }
    
    return 0;
}