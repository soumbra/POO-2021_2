#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

class Tweet{
    int id;
    string username;
    string message;
    set<string> likes;
    Tweet *rt {nullptr};
    bool deleted{false};

public:
    Tweet(int id, string username, string message) : id(id), username(username), message(message) {}

    int getId() const{
        return this->id;
    }

    string getSender() const{
        return this->username;
    }

    string getMessage() const{
        return this->message;
    }

    void like(string username) {
        likes.insert(username);
    }

    set<string> getLikes() const{
        return this->likes;
    }

    void setRt(Tweet *tw) {
        this->rt = tw;
    }

    bool isDeleted() const{
        if(this->deleted == true) {
            return true;
        }

        return false;
    } 

    void setDeleted() {
        this->deleted = true;
        this->message = "Esse tweet foi deletado :(";
        this->username = "";
        this->likes.clear();
    }

    friend ostream& operator<<(ostream& os, const Tweet& t) {
        os << t.id << ':' << t.username << ':' << '(' << t.message << ')';
        
        if ((int)t.likes.size() > 0){
            os << " [";
            for (auto liked : t.likes) {
                os << liked << ',';
            }
            os << ']';
        }

        if (t.rt != nullptr) {
            os << "\n   " << *t.rt; 
        }

        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const vector<Tweet*>& v) {
        for (auto message : v ) {
            os << *message << '\n';
        }

        return os;
    }
};