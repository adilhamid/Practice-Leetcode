struct Tweet
{
	int userId;
	int id;
	int time;
	Tweet(int userId, int id, int time) : userId(userId), id(id), time(time){
	}

};

bool operator <(const Tweet & a, const Tweet & b)
{
	return a.time<b.time;
}
bool operator >(const Tweet & a, const Tweet & b)
{
	return a.time>b.time;
}
class Twitter {

public:
	/** Initialize your data structure here. */
	map<int, set<int>> userMap;
	map<int, vector<Tweet>> tweetMap;
	int curTime = 0;
	Twitter() {

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) {
		tweetMap[userId].push_back(Tweet(userId,tweetId, curTime++));
	}

	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId) {
		vector<int> res;
		priority_queue<Tweet, vector<Tweet>, less<Tweet>> queue;
		map<int, int> hash;
		if (tweetMap.find(userId) != tweetMap.end())
			hash[userId] = tweetMap[userId].size() - 1;
		for (int id : userMap[userId])
		{
			if (tweetMap.find(id) != tweetMap.end())
				hash[id] = tweetMap[id].size() - 1;
		}
		for (auto h : hash)
		{
			if (h.second < 0) hash.erase(h.first);
			else queue.push(tweetMap[h.first][h.second]);
		}
		int num = 0;
		
		while (num < 10 && hash.size() > 0)
		{
			Tweet top = queue.top();
			res.push_back(top.id);
			hash[top.userId]--;
			queue.pop();
			if (hash[top.userId] < 0)hash.erase(top.userId);
			else
				queue.push(tweetMap[top.userId][hash[top.userId]]);
			++num;
		}
		return res;
	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId) {
		userMap[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) {
		userMap[followerId].erase(followeeId);
	}
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */