/*
Question : Quick Sort Code

Sort an array A using Quick Sort.
Change in the input array itself. So no need to return or print anything.

Input format :
First line will contain T number of test case and each tet case will consist of two lines.
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
for every test case print rray elements in increasing order (separated by space) in a new line.

Constraints :
1 <= T <= 10
1 <= n <= 10^5
0 <= arr[i] <= 10^9

Sample Input 1 :
1
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
1
5
1 5 2 7 3
Sample Output 2 :
1 2 3 5 7 
*/
#include<bits/stdc++.h>
using namespace std;
int partition(vector<int>& arr,int start,int end){
    int previousIndex =start-1;
    for(int i=start;i<end;i++){
        if(arr[i]<arr[end]){
            previousIndex++;
            swap(arr[i],arr[previousIndex]);
        }
    }
    swap(arr[previousIndex+1],arr[end]);
    return previousIndex+1;
}
void quickSort(vector<int>& arr,int start,int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quickSort(arr,start,pivot-1);
        quickSort(arr,pivot+1,end);
    }
}
int main(){
    
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        quickSort(arr,0,n-1);
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}