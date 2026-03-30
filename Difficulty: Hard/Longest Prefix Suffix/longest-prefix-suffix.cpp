class Solution {
  public:
    int getLPSLength(string &s) {
        vector<int> lps(s.size(),0);
        int preffix=0 , suffix=1 ;
        
        while(suffix<s.size()){
            //agar match kr gya prefix or suffix
            if(s[preffix]==s[suffix]){
                lps[suffix]=preffix+1;
                suffix++ , preffix++;
            }
            //if not mathced
            else
            {
                if(preffix==0){
                    lps[suffix]=0;
                    suffix++;
                }
                else{
                    preffix=lps[preffix-1];
                }
            }
        }
        
        return lps[s.size()-1];
        
    }
};