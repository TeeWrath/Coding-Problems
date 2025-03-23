class Solution {
    public:
        int maxContainers(int n, int w, int maxWeight) {
            int c = n*n;
            int t = c;
            int wt=maxWeight;
    
            while(c>0 && wt >=0){
                wt -= w;
                c--;
            }
    
            if(wt<0)c += 1;
            return t-c;
        }
    };