class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>,int>mp;
int x=0,y=0;
        mp[{x,y}]=1;
for(auto&ch:path){
   	if(ch=='N'){
   		y++;
   	}
		if(ch=='S'){
			y--;
		}
		if(ch=='E'){
			x++;
		}
		if(ch=='W'){
			x--;
		}
	 if(++mp[{x,y}]>1) return true;
}
return false;
    }
};
