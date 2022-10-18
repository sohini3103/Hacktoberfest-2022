class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> st;
        for(auto i: bank) st.insert(i);
        queue<string> q;
        q.push(start);
        vector<char> v = {'A', 'C', 'G', 'T'};
        int ans = 0;
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                string front = q.front();
                q.pop();
                if(front == end) return ans;
                for(int i = 0; i < front.size(); i++)
                {
                    for(int j = 0; j < v.size(); j++)
                    {
                        char x = front[i];
                        front[i] = v[j];
                        if(st.find(front) != st.end())
                        {
                            q.push(front);
                            st.erase(front);
                        }
                        front[i] = x;
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
