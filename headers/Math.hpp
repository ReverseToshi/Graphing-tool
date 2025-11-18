#pragma once
#include <map>
#include <functional>

class Math{
private:
    std::map<int, std::function<void()>> operations;
public:
    static void execute();
    Math();
    ~Math();
};