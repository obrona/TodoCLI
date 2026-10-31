#include <memory>

#include "start-node.hpp"

#include "data.hpp"

int main() {
    auto data = std::make_unique<Data>("tasks.save", TaskManager());
    std::unique_ptr<Node> curr_state_node = std::make_unique<StartNode>(std::move(data));

    while (curr_state_node) {
        curr_state_node = curr_state_node->run();
    }
}