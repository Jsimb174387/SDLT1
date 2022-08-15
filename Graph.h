#ifndef Graph_H
#define Graph_H


#include <iostream>
#include <vector>
#include <map>
#endif

#pragma once

//modified graph to include direction
class graph {
public:
    std::map <std::string, std::vector<std::string>>  gp;
    bool isEmpty();

    bool keyExists(std::string key);

    void addNode(std::string node);
    auto getMap();

    auto retrieve(std::string key);

    void append(std::string key, std::string value);

    void simpleConnect(std::string key1, std::string key2);
    void print(std::string key);
};