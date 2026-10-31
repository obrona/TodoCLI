#pragma once
#include <string>
#include <vector>
#include <stdexcept>

struct Task {
    bool is_done = false;
    std::string task = "";

    Task(bool is_done, std::string task): is_done(is_done), task(task) {}

    std::string serialise() {
        return std::to_string(is_done) + "|" + task;
    }
};

struct TaskManager {
    std::vector<Task> tasks;

    int size() {
        return tasks.size();
    }

    void add_task(Task t) {
        tasks.emplace_back(std::move(t));
    }

    void delete_task(int i) {
        if (i >= tasks.size()) {
            throw std::invalid_argument("index is out of range!");
        }
        tasks.erase(tasks.begin() + i);
    }

    Task& get_ref_to_task(int i) {
        if (i >= tasks.size()) {
            throw std::invalid_argument("index is out of range!");
        }
        return tasks[i];
    }
};