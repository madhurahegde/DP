/*
Samarpit is the main hero of the Dhoom 4.He is trying to steal from the Code Bank Of Hackers.
Samarpit has a key with an integer value printed on it. He also has N other keys with each key having its 
own specific value.Samarpit is trying to break the Lock for which he is supposed to get to the lock's key value.
He can perform one type of operation.Take his own key and one of the other N keys and merge them.
During merging Samarpit's Key value changes to product of both the keys modulus 100000.
For example if his key value was X and he took a key with value Y the his new key will be (X*Y)%100000.
The other key that was used during the merging process remains along with other N-1 keys.
This entire process of merging takes 1 second.
Now since he is in a hurry he asks to you to find the minimum time in which he could reach to the lock's key value.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <stdio.h>
#define MAX 100001
using namespace std;

int main()
{

    long int N, final_key;
    long int key;
    long int cur;
    long int temp;
    long int nTime;
    queue<long int> BFS;
    long int keys[MAX];
    // vector<int> time1(MAX, 0);
    long int time1[MAX];
    memset(time1, 0, sizeof(time1)); //, 0)

    //freopen("input.txt", "r", stdin);
    cin >> key >> final_key;
    cin >> N;

    // cout << key << "  " << final_key << endl
    //      << N << endl;
    for (int i = 0; i < N; i++)
    {
        cin >> keys[i];
        // cout<<keys[i]<<"  ";
    }

    // for (int i = 0; i < N; i++)
    // {
    //     //cout<<keys[i];
    //     cout << keys[i] << "  ";
    // }

    bool flag = true;
    BFS.push(key);
    time1[key] = 0;
    while (!BFS.empty() && flag)
    {
        cur = BFS.front();
        BFS.pop();

        for (int j = 0; j < N; j++)
        {
            temp = (cur * keys[j]) % 100000;
            nTime = time1[cur] + 1;

            if (time1[temp] == 0)
            {
                time1[temp] = nTime;
                BFS.push(temp);
            }
            if (temp == final_key)
            {
    
                flag = false;
            }
            // break;
        }
    }

   // cout<<time1[final_key]<<"  "<<endl;
    long int ans = (!flag) ? time1[final_key] : -1 ;
    cout<< ans<<endl;

    return 0;
}