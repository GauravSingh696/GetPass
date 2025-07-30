class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;

        for(auto str : words) {
            mp[str]++;
        }

        priority_queue<pair<int, string>> pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        vector<pair<string, int>> vec;

        while(!pq.empty()) {
            int freq = pq.top().first;
            string str = pq.top().second;
            pq.pop();

            vec.push_back({str, freq});
        }

        int i=0, j=0;

        for(;i<vec.size()-1;i++) {
            j = i;

            while(i<vec.size()-1 && vec[i].second == vec[i+1].second) {
                i++;
            }

            i++;
            sort(vec.begin()+j, vec.begin()+i);
            i--;
        }

        vector<string> result;
        sort(vec.begin()+j, vec.begin()+i);

        for(auto it : vec) {
            result.push_back(it.first);
            k--;

            if(k == 0)
                break;
        }

        return result;
    }
};
