#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    public:
    vector<pair<int,int>> nums;
    int size;
        LRUCache(int capacity) {
            size = capacity;
        }
        
        int get(int key) {
            for(auto it: nums){
                if(it.first == key){
                    return it.second;
                }
                return -1;
            }
        }
        
        void put(int key, int value) {
            if(nums.size() == size){
                nums.pop_back();
            }
            for(auto it: nums){
                if(it.first == key){
                    it.second = value;
                }
            }
            nums.push_back({key,value});
        }
    };

int main(){
    LRUCache *lRUCache = new LRUCache(2);
    lRUCache->put(1,1);
    lRUCache->put(2,2);
    cout << lRUCache->get(1) << endl;
    lRUCache->put(3,3);
    cout << lRUCache->get(2) << endl;
    
    return 0;
}