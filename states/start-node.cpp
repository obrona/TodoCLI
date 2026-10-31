#include "start-node.hpp"
#include "main-node.hpp"

std::unique_ptr<Node> StartNode::run() {
    return std::make_unique<MainNode>(std::move(data));
}
