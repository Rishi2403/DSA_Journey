//You are given an integer n, representing the number of elements. Then, you will be given n elements. You have
//to return the sum of repetitive elements i.e. the elements that appear more than one time. 

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<int> input(n);

    for (int i=0;i<n;i++){
        cin>>input[i];
    }

    map<int,int> m;
    for(int i=0;i<n;i++){
        //storing frequency of every element in input vector
        m[input[i]]++;
    }
    int sum=0;
    // finding sum of repeptitive ele
    //pair - element frequency
    for(auto pair:m){
        if(pair.second>1){// element is repetitive
            sum+=pair.first;
        }
    }

    cout<<"The sum is --> "<<sum<<"\n";

    return 0;
}