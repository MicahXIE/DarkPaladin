class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int res = 0;
        int greed_size = g.size();
        int cookies_size = s.size();
        
        if (greed_size == 0 || cookies_size == 0)
            return 0;
        
        int g_index = 0;
        for (int i=0; i<cookies_size; i++){
            if (s[i] >= g[g_index]){
                res += 1;
                g_index++;
                if(g_index == greed_size)
                    break;
            }
        }  
        
        return res;

    }
};