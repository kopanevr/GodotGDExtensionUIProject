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
    Node(T data) explicit;
    ~Node();

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool addNextNeighbor(std::shared_ptr<Node<T, maxDegree> nextNeighbor);
    void removeNeighbor(std::shared_ptr<Node<T, maxDegree> nextNeighbor);
};

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
Node<T, maxDegree>::Node(T data)
    :   data(data)
{}
