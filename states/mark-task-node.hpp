#pragma once
#include <memory>

#include "node.hpp"
#include "data.hpp"

struct MarkTaskNode: Node {
    std::unique_ptr<Data> data;

    MarkTaskNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~MarkTaskNode() {}

    virtual std::unique_ptr<Node> run();
};
