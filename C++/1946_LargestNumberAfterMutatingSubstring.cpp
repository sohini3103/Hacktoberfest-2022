class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        
        
        int changed = 0;
        int n = num.size();
        
        for(int i = 0 ; i < n; i++){
            if(num[i] - 48 < change[num[i] - 48] && changed == 0){
                num[i] = change[num[i] - 48] + 48;
                changed = 1;
            }
            else if(changed == 1 && num[i] - 48 <= change[num[i] - 48]){
                num[i] = change[num[i] - 48] + 48;
            }
            else if(changed == 1){
                break;
            }
        }
        return num;

    }
};
