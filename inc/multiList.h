#pragma once

#include <vector>
#include <memory>

#include "node.h"

template<typename T, uint8_t maxDegree> 
class MultiList final
{
private:
    std::vector<std::shared_ptr<Node<T, maxDegree>>> multiNodes;
public:
    MultiList() = default;
    ~MultiList() = default;

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    std::shared_ptr<Node<T, maxDegree>> addNode(T data);

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool addEdge(std::shared_ptr<Node<T, maxDegree>> firstNode, std::shared_ptr<Node<T, maxDegree>> secondNode);
    void removeEdge(std::shared_ptr<Node<T, maxDegree>> firstNode, std::shared_ptr<Node<T, maxDegree>> secondNode);
};

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
std::shared_ptr<Node<T, maxDegree>> MultiList<T, maxDegree>::addNode(T data)
{
    std::shared_ptr<Node<T, maxDegree>> node = std::make_shared<Node<T, maxDegree>>(data);

    multiNodes.push_back(node);

    return node;
}

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
bool MultiList<T, maxDegree>::addEdge(std::shared_ptr<Node<T, maxDegree>> firstNode, std::shared_ptr<Node<T, maxDegree>> secondNode)
{
    if (firstNode == nullptr || secondNode == nullptr) { return false; }

    if (firstNode->addNextNeighbor(secondNode) == false) { return false; }
    if (secondNode->addNextNeighbor(firstNode) == false) { firstNode->removeNeighbor(secondNode); return false; }

    return true;
}

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
void MultiList<T, maxDegree>::removeEdge(std::shared_ptr<Node<T, maxDegree>> firstNode, std::shared_ptr<Node<T, maxDegree>> secondNode)
{
    if (firstNode == nullptr || secondNode == nullptr) { return; }

    firstNode->removeNeighbor(secondNode);
    secondNode->removeNeighbor(firstNode);
}
