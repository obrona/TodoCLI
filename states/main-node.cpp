#include <charconv>
#include <iostream>
#include <print>

#include "main-node.hpp"
#include "add-task-node.hpp"
#include "delete-task-node.hpp"
#include "edit-task-node.hpp"
#include "mark-task-node.hpp"
#include "end-node.hpp"

#include "task-manager.hpp"

std::unique_ptr<Node> MainNode::run() {
    while (true) {
        std::println("\nWelcome to TodoCLI!");
        for (int i = 0; i < commands.size(); i++) {
            std::println("[{}] {}", i + 1, commands[i]);
        }

        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            std::println("Input is empty.");
            continue;
        }

        int choice = 0;
        const char* line_end = line.data() + line.size();
        auto [parsed_end, error] = std::from_chars(line.data(), line_end, choice);
        if (error != std::errc() || parsed_end != line_end || choice < 1 || choice > commands.size()) {
            std::println("Please enter a number from 1 to {}.", commands.size());
            continue;
        }

        if (choice == 1) {
            std::println("");
            for (int i = 0; i < data->tasks.size(); i++) {
                Task& t = data->tasks.get_ref_to_task(i);
                std::println("{}. [{}] {}", i + 1, (t.is_done) ? "X" : " ", t.task);
            }
        }

        else if (choice == 2) {
            return std::make_unique<AddTaskNode>(std::move(data));
        }

        else if (choice == 3) {
            return std::make_unique<DeleteTaskNode>(std::move(data));
        }

        else if (choice == 4) {
            return std::make_unique<EditTaskNode>(std::move(data));
        }

        else if (choice == 5) {
            return std::make_unique<MarkTaskNode>(std::move(data));
        }

        else if (choice == 6) {
            return std::make_unique<EndNode>(std::move(data));
        }

    }
}
