#pragma once
#include <memory>
#include <string>
#include <vector>

#include "node.hpp"

#include "data.hpp"


struct MainNode: Node {
    std::unique_ptr<Data> data;

    std::vector<std::string> commands = {
        "list task",
        "add task",
        "delete task",
        "edit task",
        "mark task",
        "exit"
    };

    MainNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~MainNode() {}

    std::unique_ptr<Node> run();
};
