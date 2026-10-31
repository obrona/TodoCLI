#include <charconv>
#include <iostream>
#include <print>
#include <string>

#include "delete-task-node.hpp"
#include "main-node.hpp"

std::unique_ptr<Node> DeleteTaskNode::run() {
    while (true) {
        std::println("Input the index of the task you want to delete or press [Q] to go back to main menu.");

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            std::println("Input is empty.");
            continue;
        }

        if (line == "q" || line == "Q") {
            return std::make_unique<MainNode>(std::move(data));
        }

        int choice = 0;
        const char* line_end = line.data() + line.size();
        auto [parsed_end, error] = std::from_chars(line.data(), line_end, choice);
        if (error != std::errc() || parsed_end != line_end || choice < 1 || choice > data->tasks.size()) {
            std::println("Please enter a number from 1 to {}.", data->tasks.size());
            continue;
        }

        data->tasks.delete_task(choice - 1);
        return std::make_unique<MainNode>(std::move(data));
    }
}
