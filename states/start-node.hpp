#pragma once
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

#include "node.hpp"

#include "task-manager.hpp"

#include "data.hpp"

struct StartNode: Node {
    std::unique_ptr<Data> data;

    StartNode(std::unique_ptr<Data> data): data(std::move(data)) {
        load_tasks_from_save_file();
    }

    virtual ~StartNode() {}

    void load_tasks_from_save_file() {
        std::ifstream save_file(data->save_file_location);
        if (!save_file) {
            // no save file yet, so there is nothing to load
            return;
        }

        std::string line;
        while (std::getline(save_file, line)) {
            if (line.empty()) {
                continue;
            }

            // split on the first | only, so the task text can contain |
            size_t separator = line.find('|');
            if (separator == std::string::npos) {
                throw std::runtime_error("malformed line in save file: " + line);
            }

            bool is_done = line.substr(0, separator) == "1";
            data->tasks.add_task(Task(is_done, line.substr(separator + 1)));
        }
    }

    virtual std::unique_ptr<Node> run();
};

