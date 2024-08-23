/*
time complexity: O(n)
tags: Hash Table, Linked List, Design, Heap(Priority Queue)
note:
*/

using Time = int;
using UserId = int;
using TweetId = int;

class Twitter
{
public:
    unordered_map<UserId, unordered_set<UserId>> followees;
    vector<pair<UserId, TweetId>> tweets;
    int time = 0;
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        int count = 10;
        for (int i = tweets.size() - 1; i >= 0; i--)
        {
            if (count == 0)
            {
                break;
            }
            int followingId = tweets[i].first;
            int tweetId = tweets[i].second;
            if (followees[userId].find(followingId) !=
                    followees[userId].end() ||
                followingId == userId)
            {
                result.push_back(tweetId);
                count--;
            }
        }
        return result;
    }

    void follow(int followerId, int followeeId)
    {
        followees[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        followees[followerId].erase(followeeId);
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