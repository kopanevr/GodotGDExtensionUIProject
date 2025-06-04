#pragma once

#include <vector>
#include <memory>

#include "manager.h"
#include "userInterfaceManager.h"

class SimulationManager final : public Manager
{
private:
    std::vector<std::unique_ptr<Manager>> processManagers;
private:
    void _body(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta);
public:
    SimulationManager();
    ~SimulationManager();

    void startUp() override;
    void shutDown() override;

    void run(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta) override;
};
