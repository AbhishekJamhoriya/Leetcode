class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string val="";
        int n=s.size();
        for(int i=0;i<n;i++){
            
               if(s[i]==' '){
                   if(val!=""){
                       if(ans==""){
                          ans+=val; 
                       }
                       else{
                          ans=val+" "+ans; 
                       }
                       
                   }
                   val="";
               }
               else{
                   val+=s[i];
               }
        }
       if(val!=""){
                       if(ans==""){
                          ans+=val; 
                       }
                       else{
                          ans=val+" "+ans; 
                       }
                       
                   }
               return ans;
    }
};
