#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    public:
        stack<pair<int,int>> st;
        StockSpanner() {
            
        }
        
        int next(int price) {
            int span = 1;
            while(!st.empty() && st.top().first <= price){
                span += st.top().second;
                st.pop();
            }
            st.push({price,span});
            return span;
        }
    };

int main(){
    StockSpanner *stockSpanner = new StockSpanner();
    cout << stockSpanner->next(100) << " For 100\n";
    cout << stockSpanner->next(80) << " For 80\n";
    cout << stockSpanner->next(60) << " For 60\n";
    cout << stockSpanner->next(70) << " For 70\n";
    cout << stockSpanner->next(60) << " For 60\n";
    cout << stockSpanner->next(75) << " For 75\n";
    cout << stockSpanner->next(85) << " For 85\n";
    return 0;
}