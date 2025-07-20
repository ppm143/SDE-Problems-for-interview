class Twitter {
private:
    struct Tweet {
        int id, time;
        Tweet(int id, int time) : id(id), time(time) {}
    };
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<Tweet>> tweets;
    int timestamp;

public:
    Twitter() : timestamp(0) {
        followers.clear();
        tweets.clear();
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(tweetId, timestamp++);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        unordered_set<int> followeeList = followers[userId];
        followeeList.insert(userId);

        for (int followee : followeeList) {
            auto& tw = tweets[followee];
            for (int i = max(0, (int)tw.size() - 10); i < tw.size(); i++) {
                pq.emplace(tw[i].time, tw[i].id);
            }
        }
        vector<int> newsFeeds;
        while (!pq.empty() && newsFeeds.size() < 10) {
            newsFeeds.push_back(pq.top().second);
            pq.pop();
        }
        return newsFeeds;
    }

    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        followers[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
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