#pragma once
#include <fstream>
#include <memory>
#include <stdexcept>
#include <string>

#include "node.hpp"

#include "data.hpp"

struct EndNode: Node {
    std::unique_ptr<Data> data;

    EndNode(std::unique_ptr<Data> data): data(std::move(data)) {}

    virtual ~EndNode() {}

    void save_tasks_to_file() {
        std::ofstream save_file(data->save_file_location);
        if (!save_file) {
            throw std::runtime_error("could not open save file: " + data->save_file_location);
        }

        for (int i = 0; i < data->tasks.size(); i++) {
            save_file << data->tasks.get_ref_to_task(i).serialise() << '\n';
        }
    }

    virtual std::unique_ptr<Node> run();
};
