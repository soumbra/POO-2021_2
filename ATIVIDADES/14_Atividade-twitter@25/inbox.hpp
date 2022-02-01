#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include "tweet.hpp"

class Inbox{
    map<int, Tweet*> myTweets;
    map<int, Tweet*> timeline;

public:
    Inbox() {}

    vector<Tweet*> getTimeline() const{
        vector<Tweet*> result;
        for (auto& message : this->timeline) {
            if (message.second->isDeleted() == false) {
                result.push_back(message.second);
            }
        }

        reverse(result.begin(), result.end());
        return result;
    }

    vector<Tweet*> getMyTweets() const{
        vector<Tweet*> result;
        for (auto& message : myTweets) {
            result.push_back(message.second);
        }
        return result;      
    }

    void storeInTimeline(Tweet* tweet) {
        this->timeline[tweet->getId()] = tweet;
    }

    void storeInMyTweets(Tweet* tweet) {
        this->myTweets[tweet->getId()] = tweet;
    }

    void rmMsgsFrom(string username) {
        vector<int> ids;
        for (auto& message : timeline) {
            if (message.second->getSender() == username) {
                ids.push_back(message.first);
            }
        }
        for (auto id : ids) {
            auto it = this->timeline.find(id);
            this->timeline.erase(it);
        }
    }

    Tweet* getTweet(int id) {
        auto it = this->timeline.find(id);
        if (it == this->timeline.end()) {
            throw "Tweet nao encontrado";
        } else {
            return it->second;
        }
    } 

    friend std::ostream& operator<<(std::ostream& os, const Inbox& i) {
        os << i.getTimeline() << '\n';

        return os;
    }

};
