class Solution {
public:
    bool condition(long long m,long long div1,long long div2,long long cnt1,long long cnt2){
        long long x = (m/div1);
        long long y = m/div2;
        long long LCM = std::lcm(div1,div2);
        long long z = m/LCM;
        x-=z;
        y-=z;
        x<=cnt2?x=0:x-=cnt2;
        y<=cnt1?y=0:y-=cnt1;
        return m-(x+y+z)>=cnt1+cnt2;
    }
    int minimizeSet(int div1, int div2, int cnt1, int cnt2) {
        long long l = 0,h=1e17,m;
        long long res = 0;
        while(l<=h){
            // int m = l + (h-l)/2;
            long long m = (l+h)/2;
            if(condition(m,div1,div2,cnt1,cnt2)){
                res = m;
                h = m - 1;
            }
            else{
                l = m + 1;
                cout<<endl;
            }
        }
        return res;
    }
};
