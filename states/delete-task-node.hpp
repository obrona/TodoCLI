#pragma once
#include <memory>

#include "node.hpp"
#include "data.hpp"

struct DeleteTaskNode: Node {
    std::unique_ptr<Data> data;

    DeleteTaskNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~DeleteTaskNode() {}

    virtual std::unique_ptr<Node> run();
};
