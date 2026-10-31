#include <iostream>
#include <print>
#include <string>

#include "add-task-node.hpp"
#include "main-node.hpp"

std::unique_ptr<Node> AddTaskNode::run() {
    while (true) {
        std::println("\nInput the new tasks or press [Q] to go back to main menu.");

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            std::println("Input is empty.");
            continue;
        }

        if (line == "q" || line == "Q") {
            return std::make_unique<MainNode>(std::move(data));
        }

        data->tasks.add_task(Task{false, line});
        return std::make_unique<MainNode>(std::move(data));
    }
}
