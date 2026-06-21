class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> fr(26,0);
        for(auto x:tasks) {
            fr[x-'A']++;
        }
        sort(fr.begin(),fr.end(),greater<int>());
        int maxfreq = fr[0];
        int idletime = (maxfreq-1)*n;
        for(int i = 1;i<26;i++) {
            idletime -= min(fr[i],maxfreq-1);
        }
        idletime = max(0,idletime);
        return tasks.size()+idletime;
    }
};
