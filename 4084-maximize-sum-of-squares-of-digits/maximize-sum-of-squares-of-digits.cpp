class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s = "";

        if(num*9 < sum){
            return s;
        }
        // while(true){
            // char x = '9';
            // int u = 9;
            // while(sum>0){
            //     if(sum-u >= 0){
            //         s+=x;
            //         sum-=u;
            //     }
            //     else{
            //         u--;
            //         x--;
            //     }
            // }
        // ? 
        bool b = false;
        for(int i=0;i<num;i++){
            if(b){
                s+='0';
                continue;
            }
            for(char c='9';c>='0';c--){
                while(s.size()<num && sum - (c-'0') >= 0){
                    s+=c;
                    sum = sum - (c-'0');
                }

                if(sum == 0){
                    b = true;
                    break;
                }
            }

            if(b){
                break;
            }
        }

        while(s.size()<num){
            s+='0';
        }

        // for(int i=0;i<num-s.size();i++){
        //     s+='0';
        // }  

        return s;
    }
};