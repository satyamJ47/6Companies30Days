class Solution {
public:
    string getHint(string secret, string guess) {
        
        int bulls = 0;
        int cows = 0;
        int n = secret.size();
        unordered_map<char,int>ump1,ump2;
        for(int i=0;i<n;i++){
           if(secret[i] == guess[i]){
               bulls++;
           } 
           else{
               ump1[secret[i]]++;
               ump2[guess[i]]++;
           }
        }
        for(auto i:ump1){
            if(ump2.find(i.first)!=ump2.end()){
                cows += min(i.second,ump2[i.first]);
            }
        } 
        return to_string(bulls) + 'A'+ to_string(cows) +'B';
    }
};

// TC : O(N)
// SC : O(N)
