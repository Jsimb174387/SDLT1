
#include "Graph.h"
#pragma once
using namespace std;

graph::graph(void)
{
    std::map <std::string, std::vector<std::string>> gp{};

}


graph::~graph(void)
{
}

//modified graph to include direction
    bool graph::isEmpty() {
        return gp.empty();
        
    }

    bool graph::keyExists(string key) {
        return gp.count(key);
    }

    void graph::addNode(string node) {
        if (keyExists(node)) {
            //do nothing, just to make code look similar
        }
        else {
            vector<string> vect{};
            gp.emplace(node, vect);
        }
    }
    auto graph::getMap() {
        return gp;
    }

    auto graph::retrieve(string key) {
        return gp[key];
    }

    void graph::append(string key, string value) {
        gp[key].push_back(value);
    }

    void graph::simpleConnect(string key1, string key2) {
        //only connects one side
        if (keyExists(key1) && keyExists(key2)) {
            append(key1, key2);
        }
    }
    void graph::print(string key) {
        cout << key << ", ";
        for (string value : gp[key]) {
            cout << "[" << value << "] ";
        }
        cout << "\n";
    }