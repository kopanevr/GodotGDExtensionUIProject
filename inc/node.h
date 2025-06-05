#pragma once

#include <vector>
#include <memory>
#include <cstdint>

template<typename T, uint8_t maxDegree> 
class Node final
{
private:
    T data;
    std::vector<std::shared_ptr<Node<T, maxDegree>> nextNeighbors;
public:
    Node();
    ~Node();

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool addNextNeighbor(std::shared_ptr<Node<T, maxDegree> nextNeighbor);
#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool removeNeighbor(std::shared_ptr<Node<T, maxDegree> nextNeighbor);
};
