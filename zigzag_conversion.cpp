class Solution {
public:
    string convert(string s, int numRows){
        int n = s.size();
        if(numRows<=1 || n<=numRows){
            return s;
        }
        int x = numRows-2;
        vector<vector<char>> vec1;
        vector<vector<char>> vec2;
        for(int i=0;i<n;i++){
            vector<char> a;
            vector<char> b;
            int j = i;
            for(j=i;j<i+numRows;j++){
                if(j<n){
                a.push_back(s[j]);
                }
            }
            int y = j;
            for(j=y;j<y+x;j++){
                if(j<n){
                b.push_back(s[j]);
                }
            }
            if(b.size()<x){
                while(b.size()<x){
                    b.push_back('_');
                }
            }
            reverse(b.begin(),b.end());
            i = j-1;
            vec1.push_back(a);
            vec2.push_back(b);
        }

        // making the first side of the string 
        string l="";
        n = vec1.size();
        int m = vec2.size();
        int size = vec1[0].size();
        for(int i=0;i<n;i++){
            l+=vec1[i][0];
        }

        // middle portion of the string
        vector<vector<char>> vec3;
        int counter = 0;
        for(int i=0;i<vec1.size();i++){
            vector<char> c;
            for(int j=1;j<=x;j++){
                if(j<vec1[i].size()){
                c.push_back(vec1[i][j]);
                }
            }
            if(c.size()<x){
                while(c.size()<x){
                    c.push_back('_');
                }
            }
            vec3.push_back(c);
            if(counter<vec3.size()){
                vec3.push_back(vec2[counter]);
                counter++;
            }
        }

        while(counter<vec2.size()){
            vec3.push_back(vec2[counter]);
            counter++;  
        }

       
        for (int r = 0; r < x; r++) { 
        for (int i = 0; i < vec3.size(); i++) {  
        if (r < vec3[i].size() && vec3[i][r] != '_') {
            l += vec3[i][r];
        }
        }  
        }

        // making the last side of the string 
        for(int i=0;i<n;i++){
            if(vec1[i].size()==size){
                l+=vec1[i][size-1];
            }
        }

        return l;
    }
};