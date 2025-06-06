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
    MultiList();
    ~MultiList();

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    std::shared_ptr<Node<T, maxDegree>> addNode(T data);

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool addEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secondNode);
    void removeEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secondNode);
};

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
bool MultiList<T, maxDegree>::addEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secondNode)
{
    if (firstNode == nullptr || secondNode == nullptr) { return false; }

    return true;
}

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
void MultiList<T, maxDegree>::removeEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secondNode)
{
}
