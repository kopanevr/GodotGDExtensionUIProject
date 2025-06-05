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
};
