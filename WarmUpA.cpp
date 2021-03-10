#include <iostream> 
#include <vector> 
using namespace std; 

void print(vector<int> nums){
    for(auto x:nums) cout << x << " "; 
    cout << endl; 
}


void solve(int n){
    vector<int> nums; 
    for(int i = 0; i < n; i++) nums.push_back(i + 1); 
    if(n % 2 == 0){
        reverse(nums.begin(), nums.end()); 
        print(nums); 
    }
    else{
        swap(nums[n/2], nums[n - 1]); 
        reverse(nums.begin(), nums.end()); 
        print(nums); 
    }
}

int main(){
    int numberCases; 
    cin >> numberCases; 
    for(int i = 0; i < numberCases; i++){
        int n; 
        cin >> n; 
        solve(n); 
    }
}

