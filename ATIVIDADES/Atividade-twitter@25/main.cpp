#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include <algorithm>
#include "tweet.hpp"
#include "inbox.hpp"
#include "user.hpp"
#include "controller.hpp"
#include "auxiliar.hpp"

vector<string> getcmd() {
    string line;
    getline(cin, line);
    cout << "$" << line << "\n";
    return aux::split(line, ' ');
}

int main() 
{
    Controller c;

    while(true) {
        auto param = getcmd();
        auto cmd = param[0];
        try {
            if (cmd == "exit") {
                break;
            } else if (cmd == "add") {
                c.addUser(param[1]);
            } else if (cmd == "rm") {
                c.rmUser(param[1]);
            }  else if (cmd == "show") {
                cout << c << '\n';
            } else if (cmd == "follow") {
                c.getUser(param[1])->follow(c.getUser(param[2]));
            } else if (cmd == "unfollow") {
                c.getUser(param[1])->unfollow(param[2]);
            } else if (cmd == "twittar") {
                auto msg = aux::slice(param, 2);
                c.sendTweet(param[1], aux::join(msg, " "));
            } else if (cmd == "like") {
                c.getUser(param[1])->like(std::stoi(param[2]));
            } else if (cmd == "rt") {
                auto msg = aux::slice(param, 3);
                c.sendRt(param[1], stoi(param[2]), aux::join(msg, " "));
            } else if (cmd == "timeline") {
                cout << c.getUser(param[1])->getInbox().getTimeline() << '\n';
            } else {
                cout << "fail: comando invalido" << '\n';
            }
        } catch(const char* e) {
            cout << "fail: " << e << '\n';
        }
    }
    return 0;
}