//constructive algorithms  interactive

#include<bits/stdc++.h>
using namespace std;
int t,n;

int query(int i,int j,int k){
    int r;
    cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
    cin>>r;
    return r;
}

int main(){
    cin>>t;
    while (t -- ){
        cin>>n;
        vector<int> a(n+1,-1);
        vector<int> res(n+1,-1);
        for(int i=1;i+2<=n;i+=3){
            a[i] = query(i,i+1,i+2);
        }
        int imp,crew;//crew1
        for(int i=1;i+2<=n;i+=3){
            if(a[i]!=a[i+3]){
                for(int j = i+1;;j++){
                    a[j] = query(j,j+1,j+2);
                    if(a[j]!=a[j-1]){
                        res[j-1] = a[j-1];
                        res[j+2] = a[j]; 
                        if(res[j-1]){
                            crew = j-1;
                            imp = j+2;
                        }else{
                            imp = j-1;
                            crew = j+2;
                        }
                        break;
                    }
                }
                break;
            }
        }
        
        for(int i=1;i+2<=n;i+=3){
            if((i-1)/3 == (crew-1)/3 || (i-1)/3 == (imp-1)/3 ){
                for(int j = i;j<i+3;j++){
                    if(res[j] == -1){
                        res[j] = query(imp,crew,j);
                    }
                }
            }else if(a[i]==0){
                if(query(i,i+1,crew)){
                    res[i+2] = 0;
                    if(query(i,imp,crew)){
                        res[i] = 1;
                        res[i+1] = 0; 
                    }else{
                        res[i] = 0;
                        res[i+1] = 1;
                    }
                }else{
                    res[i] = 0;
                    res[i+1] = 0;
                    res[i+2] = query(i+2,imp,crew);
                }
            }else{
                if(query(i,i+1,imp)){
                    res[i] = 1;
                    res[i+1] = 1;
                    res[i+2] = query(i+2,imp,crew);
                }else{
                    res[i+2] = 1;
                    if(query(i,imp,crew)){
                        res[i] = 1;
                        res[i+1] = 0; 
                    }else{
                        res[i] = 0;
                        res[i+1] = 1;
                    }
                }
            }
        }
    
        queue<int> q;
        for(int i = 1;i<=n;i++){
            if(!res[i]){
                q.push(i);
            }
        }
        
        cout<<"! "<<q.size()<<" ";
        while(q.size()){
            cout<<q.front()<<" ";
            q.pop();
        }
        cout<<endl;
    }
    return 0;
}
