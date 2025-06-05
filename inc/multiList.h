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
    bool addEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secomdNode);
    void removeEdge(std::shared_ptr<Node<T, maxDegree> firstNode, std::shared_ptr<Node<T, maxDegree> secomdNode);
};
