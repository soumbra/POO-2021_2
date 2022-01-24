#pragma once
#include "inbox.hpp"

class User{
    string username;
    Inbox inbox;
    map<string, User*> followers;
    map<string, User*> following;

public:
    User(string username) : username(username) {}

    void follow(User * other) {
        auto it = following.find(other->username);
        if (it == following.end() && it->second != this) {
            this->following[other->username] = other;
            other->followers[this->username] =  this;
        } else {
            throw "Voce ja segue esses sujeito";
        } 
    }

    Inbox& getInbox() {
        return this->inbox;
    }

    void sendTweet(Tweet * msg) {
        inbox.storeInMyTweets(msg);
        inbox.storeInTimeline(msg);
        for(auto& [key, user] : followers) {
            user->inbox.storeInTimeline(msg);
        }      
    }
    
    void like(int twId) {
        auto allMessages = this->inbox.getTimeline();
        for (auto message : allMessages) {
            if (message->getId() == twId) {
                message->like(this->username);
                return;
            }       
        }
        throw "Tweet nao encontrado";       
    }

    void unfollow(string username) {
        auto it = this->following.find(username);
        if (it != this->following.end()) {
            auto userFound = it->second;
            this->following.erase(it);
            auto it2 = userFound->followers.find(this->username);
            userFound->followers.erase(it2);
            inbox.rmMsgsFrom(username);
        } else {
            throw "Usuario nao encontrado";
        }
    }

    void unfollowAll() {
        for (auto& user : following) {
            auto it = user.second->followers.find(this->username);
            user.second->followers.erase(it);
        }  
        this->following.clear();
    }

    void rejectAll() {
        for (auto& user : followers) {
            auto it = user.second->following.find(this->username);
            user.second->following.erase(it);
        }
        this->followers.clear();
    }

    friend std::ostream& operator<<(std::ostream& os, const User& u) {
        os << u.username << '\n';
        os << "     Seguidos ";
        os << '[';
        for (auto& follow : u.following) {
            os << follow.first << ", ";
        } 
        os << ']' << '\n';

        os << "     Seguidores ";
        os << '[';
        for (auto& follower : u.followers) {
            os << follower.first << ", ";
        } 
        os << ']' << '\n';

        return os;
    }   
};