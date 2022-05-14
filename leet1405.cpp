class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s =  to_string(num); 
        int count =0;
        for(int i =0; i<s.length();i++){
            string t = s.substr(i,k);
            if(t.length()==k && t[0] !=0){
            // cout<<t<<endl;
            int f = stoi(t);
             if(f !=0) {
                 if( num %f ==0){
                     count++;
                 }
             }
            }
              
        }
        return count;
        
    }
};