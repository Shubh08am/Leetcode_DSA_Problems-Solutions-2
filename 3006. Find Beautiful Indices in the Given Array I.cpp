class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int>a_indices , b_indices, result;
        int n=s.size(),len1=a.size(),len2=b.size();
        for(int i=0;i<=n-len1;i++){
            if(s.substr(i,len1)==a) { 
                a_indices.push_back(i);
            }
        }
        for(int i=0;i<=n-len2;i++){
            if(s.substr(i,len2)==b){
                b_indices.push_back(i);
            }
        }
        unordered_set<int>used;
        for(int i=0;i<a_indices.size();i++){
            //check between a_indices[i]-k to a_indices[i]+k -> b_indices[i] present 
            int value1 = a_indices[i]-k ; 
            int value2 = a_indices[i]+k ; 
            auto it1 = lower_bound(b_indices.begin(),b_indices.end(),value1) ; 
            auto it2 = lower_bound(b_indices.begin(),b_indices.end(),value2) ; 
            if(it1 == b_indices.end()) continue; 
            else if(abs((*it1)-a_indices[i])<=k) {
              if(!used.count(a_indices[i]))  result.push_back(a_indices[i]);
                used.insert(a_indices[i]);
            }
            if(it2 == b_indices.end()) continue; 
            else if(abs((*it2)-a_indices[i])<=k) {
              if(!used.count(a_indices[i]))  result.push_back(a_indices[i]);
                used.insert(a_indices[i]);
            }
        }
    return result;
    }
};
