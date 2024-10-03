#include<bits/stdc++.h>
#include<vector>
using namespace std;

void bucketSort(float arr[],int size){

    vector<vector<float> >bucket(size,vector<float> ()); //step 1
    
    //finding range
    float max_ele=arr[0];
    float min_ele=arr[0];
    for(int i=1;i<size;i++){
        max_ele=max(max_ele,arr[i]);
        min_ele=min(min_ele,arr[i]);
    }
    float range=(max_ele-min_ele)/size;

    //inserting elements into bucket
    for(int i=0;i<size;i++){
        int idx=(arr[i]-min_ele)/range;
        //boundary elements
        float diff=(arr[i]-min_ele)/range - idx;
        if(diff==0&&arr[i]!=min_ele){
           bucket[idx-1].push_back(arr[i]); 
        }else{
            bucket[idx].push_back(arr[i]);
        }
    }

    //sorting individual buckets
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
        sort(bucket[i].begin(),bucket[i].end());
        }
    }

    //combining elements from buckets
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }
    
}
int main(){
    float arr[]={6.13,8.45,0.12,1.89,4.75,2.63,7.85,10.39};
    int size=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}