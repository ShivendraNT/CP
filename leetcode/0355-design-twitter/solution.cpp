class Twitter {
public:
    int time;
    unordered_map<int,unordered_set<int>> friends;
    unordered_map<int,vector<pair<int,int>>> tweets;
    class node{
        public:
        int time;
        int tweetid;
        int row;
        int col;
        node(int time,int tweetid,int row,int col){
            this->time=time;
            this->tweetid=tweetid;
            this->row=row;
            this->col=col;
        }
    };
    class compare{
        public:
        bool operator()(node*a,node*b){
            return a->time<b->time;
        }
    };
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<vector<pair<int,int>>> totalposts;
        if(!tweets[userId].empty()) {
            totalposts.push_back(tweets[userId]);
        }
        for(int i: friends[userId]){
            if(!tweets[i].empty()) {
                totalposts.push_back(tweets[i]);
            }
        }
        priority_queue<node*, vector<node*>, compare> maxheap;
        for(int i=0; i<totalposts.size(); i++){
            int lastIdx = totalposts[i].size() - 1;
            maxheap.push(new node(totalposts[i][lastIdx].first, totalposts[i][lastIdx].second, i, lastIdx));
        }
        vector<int> ans;
        while(!maxheap.empty() && ans.size()<10){
            node* temp=maxheap.top();
            ans.push_back(temp->tweetid);
            maxheap.pop();
            if(temp->col - 1 >= 0){
                maxheap.push(new node(totalposts[temp->row][temp->col-1].first, totalposts[temp->row][temp->col-1].second, temp->row, temp->col-1));
            }
            delete temp;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        friends[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        friends[followerId].erase(followeeId);
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
