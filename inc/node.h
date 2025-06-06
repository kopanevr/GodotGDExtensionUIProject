#pragma once

#include <vector>
#include <algorithm>
#include <memory>
#include <cstdint>

template<typename T, uint8_t maxDegree> 
class Node final
{
private:
    T data;
    std::vector<std::shared_ptr<Node<T, maxDegree>>> nextNeighbors;
public:
    Node(T data) explicit;
    ~Node() = default;

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    bool addNextNeighbor(std::shared_ptr<Node<T, maxDegree>> nextNeighbor);
    void removeNeighbor(std::shared_ptr<Node<T, maxDegree>> nextNeighbor);

#if __cplusplus >= 201703L
    [[nodiscard]]
#endif
    T getData() noexcept { return data; }
};

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
Node<T, maxDegree>::Node(T data)
    :   data(data)
{}

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
bool Node<T, maxDegree>::addNextNeighbor(std::shared_ptr<Node<T, maxDegree>> nextNeighbor)
{
    if (nextNeighbor == nullptr) { return false; }

    if (nextNeighbors.size() >= maxDegree) { return false; }

    std::vector<std::shared_ptr<Node<T, maxDegree>>>::iterator iter = nextNeighbors.end();

    iter = std::find(nextNeighbors.begin(), nextNeighbors.end(), nextNeighbor);

    if (iter == nextNeighbors.end()) { return false; }
    
    nextNeighbors.push_back(nextNeighbor);

    return true;
}

/**
 * @brief
 */
template<typename T, uint8_t maxDegree>
void Node<T, maxDegree>::removeNeighbor(std::shared_ptr<Node<T, maxDegree>> nextNeighbor)
{
    if (nextNeighbor == true) { return false; }

    std::vector<std::shared_ptr<Node<T, maxDegree>>>::iterator iter = nextNeighbors.end();

    iter = std::find(nextNeighbors.begin(), nextNeighbors.end(), nextNeighbor);

    if (iter != nextNeighbors.end()) { nextNeighbors.erase(iter) }
}
