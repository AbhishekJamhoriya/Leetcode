class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n=version1.size();
        int m=version2.size();
        int i=0;
        int j=0;
        string a="0";
        string b="0";
        while(i<n && j<m){
            int i_i=i;
            int j_j=j;
            if(version1[i]=='.' && version2[j]=='.'){
                int val_a=stoi(a);
                int val_b=stoi(b);
                if(val_a<val_b){
                    return -1;
                }
                else if(val_a>val_b){
                    return 1;
                }
                i++;
                j++;
                a="0";
                b="0";
            }
            if(version1[i_i]!='.'){
                a+=version1[i];
                i++;
            }
            if(version2[j_j]!='.'){
                b+=version2[j];
                j++;
            }
        }
        cout<<i<<" "<<j<<endl;
        while(i<n){
            if(version1[i]=='.'){
                int val_a=stoi(a);
                int val_b=stoi(b);
                if(val_a<val_b){
                    return -1;
                }
                else if(val_a>val_b){
                    return 1;
                }
                i++;
                a="0";
                b="0";
            }
            else{
                a+=version1[i];
                i++;
            }
        }
           while(j<m){
            if(version2[j]=='.'){
                int val_a=stoi(a);
                int val_b=stoi(b);
                if(val_a<val_b){
                    return -1;
                }
                else if(val_a>val_b){
                    return 1;
                }
                j++;
                a="0";
                b="0";
            }
               else{
                   b+=version2[j];
                   j++;
               }
        }
        int val_a=stoi(a);
                int val_b=stoi(b);
                if(val_a<val_b){
                    return -1;
                }
                else if(val_a>val_b){
                    return 1;
                }
        return 0;
       
        
    }
};
