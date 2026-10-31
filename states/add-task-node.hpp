#pragma once
#include <memory>

#include "node.hpp"
#include "data.hpp"

struct AddTaskNode: Node {
    std::unique_ptr<Data> data;

    AddTaskNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~AddTaskNode() {}

    virtual std::unique_ptr<Node> run();
};
