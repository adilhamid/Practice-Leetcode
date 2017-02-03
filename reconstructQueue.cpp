
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        
        sort(people.begin(),people.end(), mysort);

//      vector<pair<int,int>>result;
        
        for(int i =0; i< people.size(); i++){
            pair<int,int> temp = people[i];
            int val = people[i].second;
            people.erase(people.begin()+i);
            people.emplace(people.begin()+val, temp);
        }
        
        return people;
    }
    static bool mysort(const pair<int,int>a,const pair<int,int>b){
        return (a.first==b.first)? a.second < b.second : a.first > b.first;
    }
};