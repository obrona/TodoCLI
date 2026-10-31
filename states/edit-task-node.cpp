#include <charconv>
#include <iostream>
#include <print>
#include <string>

#include "edit-task-node.hpp"
#include "main-node.hpp"

std::optional<int> EditTaskNode::get_index() {
    while (true) {
        std::println("Input the index of the task you want to edit or press [Q] to return to main menu.");

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            std::println("Input is empty.");
            continue;
        }

        if (line == "q" || line == "Q") {
            return std::nullopt;
        }

        int choice = 0;
        char* end = line.data() + line.size();
        auto [parse_end, err] = std::from_chars(line.data(), end, choice);
        if (err != std::errc() || parse_end != end || choice < 1 || choice > data->tasks.size()) {
            std::println("Please enter a number from 1 to {}.", data->tasks.size());
            continue;
        }

        return choice;
    }
}

bool EditTaskNode::edit_task(int choice) {
    while (true) {
        std::println("Input the new task or press [Q] to choose a different index.");

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            std::println("Input is empty");
            continue;
        }

        if (line == "q" || line == "Q") {
            return false;
        }

        data->tasks.get_ref_to_task(choice).task = line;
        return true;
    }
}

std::unique_ptr<Node> EditTaskNode::run() {
    while (true) {
        auto choice = get_index();
        if (!choice) {
            return std::make_unique<MainNode>(std::move(data));
        }

        bool res = edit_task(choice.value() - 1);
        if (!res) continue;

        return std::make_unique<MainNode>(std::move(data));
    }
}
