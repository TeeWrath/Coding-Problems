#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[2];
    bool containsKey(int bit){
        return links[bit] != NULL;
    }

    Node* get(int bit){
        return links[bit];
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }
};

class Trie{
    private: Node* root;
    public:
        Trie(){
            root = new Node();
        }

    public:
        void insert(int num){
            Node* node = root;

            for(int i=31;i>=0;i--){
                int bit = (num >> i) & 1;
                if(!node->containsKey(bit)){
                    node->put(bit,new Node());
                }

                node = node->get(bit);
            }
        }
    
        public:
            int getMax(int num){
                Node* node = root;
                int maxNum = 0;
                for(int i=31;i>=0;i--){
                    int bit = (num >> i) & 1;
                    if(node->containsKey(1-bit)){
                        maxNum = maxNum | (1<<i);
                        node = node->get(1-bit);
                    }
                    else{
                        node = node->get(bit);
                    }
                }

                return maxNum;
            }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        Trie trie;
        int q = queries.size();
        vector<int> ans(q, -1);
        vector<tuple<int, int, int>> offlineQueries; // {maxi, num, idx}
        
        for(int i = 0; i < q; i++) {
            int num = queries[i][0];
            int maxi = queries[i][1];
            offlineQueries.emplace_back(maxi, num, i);
        }
        
        sort(offlineQueries.begin(), offlineQueries.end());
        int i = 0;
        int n = nums.size();
        
        for(auto &it : offlineQueries) {
            int maxi = get<0>(it);
            int num = get<1>(it);
            int idx = get<2>(it);
            while(i < n && nums[i] <= maxi) {
                trie.insert(nums[i]);
                i++;
            }
            if(i != 0) {
                ans[idx] = trie.getMax(num);
            } else {
                ans[idx] = -1;
            }
        }
        
        return ans;
    }
};