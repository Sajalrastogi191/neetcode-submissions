class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;  //user->tweets
    unordered_map<int,unordered_set<int>> follows; //user->follows
    priority_queue<vector<int>> pq; //max_heap
    int timer;  
    Twitter() {
        timer = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>> pq;
        follows[userId].insert(userId);
        for(int user : follows[userId]) {
            if(!tweets[user].empty()) {
                int lastIndex = tweets[user].size() - 1;
                pq.push({tweets[user][lastIndex].first, user, lastIndex});
            }
        }
        vector<int> ans;
        while(!pq.empty() && ans.size() < 10) {
            auto top = pq.top();
            pq.pop();
            
            int time = top[0];
            int user = top[1];
            int index = top[2];
            
            ans.push_back(tweets[user][index].second);
            
            if(index > 0) {
                pq.push({tweets[user][index - 1].first, user, index - 1});
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */