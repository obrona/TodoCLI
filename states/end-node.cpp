#include <print>

#include "end-node.hpp"
#include "main-node.hpp"

std::unique_ptr<Node> EndNode::run() {
    try {
        save_tasks_to_file();
        return std::unique_ptr<Node>();
    } catch (std::runtime_error& err) {
        std::println("Could not save file, returning to main menu");
        return std::make_unique<MainNode>(std::move(data));
    }
}
