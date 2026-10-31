#pragma once
#include <memory>

struct Node {
    virtual std::unique_ptr<Node> run() = 0;

    virtual ~Node() {}
};