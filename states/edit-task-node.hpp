#pragma once
#include <memory>
#include <optional>

#include "node.hpp"
#include "data.hpp"

struct EditTaskNode: Node {
    std::unique_ptr<Data> data;

    EditTaskNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~EditTaskNode() {}

    std::optional<int> get_index();

    // return false if want to choose a different index else true
    bool edit_task(int choice);

    virtual std::unique_ptr<Node> run();
};
