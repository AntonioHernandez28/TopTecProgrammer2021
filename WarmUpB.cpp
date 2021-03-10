#include <iostream> 
#include <vector>
#include <unordered_map>
using namespace std; 

void solve(vector<long long> nums){
    unordered_map<long long, int> hashMap;  
    int minNumber = 2000000000; 
    long long int res = -1; 
    for(auto x:nums){
        long long int eX = x; 
        if(hashMap.find(eX) == hashMap.end()) hashMap[eX] = 1; 
        else hashMap[eX]++; 
    }

    for(int i = 0; i < nums.size(); i++){
        if(hashMap[nums[i]] == 1){
            if(nums[i] < minNumber){
                res = i + 1; 
                minNumber = nums[i]; 
            }
        }
    }
    cout << res << '\n'; 
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    
    long long int numberCases; 
    cin >> numberCases; 
    for(int i = 0; i < numberCases; i++){
        vector<long long> participants; 
        long long int n; 
        cin >> n; 
        for(int j = 0; j < n; j++){
            long long int curr; 
            cin >> curr; 
            participants.push_back(curr); 
        }
        solve(participants); 
    }
}

