#include <charconv>
#include <iostream>
#include <print>
#include <string>

#include "mark-task-node.hpp"
#include "main-node.hpp"

std::unique_ptr<Node> MarkTaskNode::run() {
    while (true) {
        std::println("Input the index of the task to toggle or press [Q] to return to main menu.");

        std::string line;
        std::getline(std::cin, line);
        if (line.size() == 0) {
            std::println("Input is empty.");
            continue;
        }

        if (line == "q" || line == "Q") {
            return std::make_unique<MainNode>(std::move(data));
        }

        int choice;
        char* end = line.data() + line.size();
        auto [parse_end, err] = std::from_chars(line.data(), end, choice);
        if (err != std::errc() || parse_end != end || choice < 1 || choice > data->tasks.size()) {
            std::println("Please input a number between 1 and {}", data->tasks.size());
            continue;
        }

        Task& t = data->tasks.get_ref_to_task(choice - 1);
        t.is_done = !t.is_done;

        return std::make_unique<MainNode>(std::move(data));
    }
}
