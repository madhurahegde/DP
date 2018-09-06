#include<iostream>
#include<vector>
using namespace std;
vector<int> seq;
void print() {
    cout<<"Inside Print";
    for(int j=0;j<=seq.size();j++) {
        cout<<seq[j]<<" ";    
    }
    cout<<endl;
}


int findSeq(int m,int n, int i, int count) {
    cout<<"\nInside findSeq\n";
    
    if(seq.size() == n)
    {
        print();
        return 1;
    }
    if(i<=m)
    {
        seq.push_back(i);
        cout<<seq.front()<<" ";
        int nextEle = 2*i;
        for(int j=nextEle; j<=2*nextEle && j<=m; j++) {
            count+= findSeq(m,n,j,count);
            seq.pop_back();
        }
    }
    return count;
}

int main() {
    vector<int> seq;
    int count = findSeq(10,4,1,0);

    cout<<"No. of sequence is:"<<count<<endl;
}