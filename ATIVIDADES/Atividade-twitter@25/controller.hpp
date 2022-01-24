#pragma once
#include "user.hpp"

class Controller{
    map<string, shared_ptr<User>> users;
    map<int, shared_ptr<Tweet>> tweets;
    int nextTwId = 0;

    Tweet* createTweet(string sender, string msg) {
        shared_ptr<Tweet> newMessage = make_shared<Tweet>(nextTwId, sender, msg);
        this->tweets[nextTwId] = newMessage;
        nextTwId++;
        return newMessage.get();
    } 

public:
    Controller() {};

    void addUser(string username) {
        auto it = users.find(username);
        if(it == users.end()) {
            User newUser{username};
            this->users[username] = make_shared<User>(newUser); 
        } else {
            throw "User already exists";
        }
    }

    User* getUser(string username) {
        auto it = users.find(username);
        if(it != users.end()) {
            return it->second.get();
        } else {
            throw "User not found";
        }    
    }

    void sendTweet(string username, string msg) {
        User* user {this->getUser(username)};
        user->sendTweet(createTweet(username, msg));
    }

    void sendRt(string username, int twId, string msg) {
        User* user{this->getUser(username)};
        Tweet* twFound{user->getInbox().getTweet(twId)};
        Tweet* newTweet{this->createTweet(username, msg)};
        newTweet->setRt(twFound);
        user->sendTweet(newTweet);
    }

    void rmUser(string username) {
        User* user{this->getUser(username)};
        user->unfollowAll();
        user->rejectAll();

        for (auto& tweet : user->getInbox().getMyTweets()) {
            tweet->setDeleted();
        }  
        auto it = this->users.find(username);
        this->users.erase(it);
    }

    friend std::ostream& operator<<(std::ostream& os, const Controller& c) {
        for (auto user: c.users) {
            os << *user.second;
        } 
        return os;
    }
};

