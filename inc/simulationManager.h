#pragma once

#include <vector>
#include <memory>

#include "manager.h"
#include "userInterfaceManager.h"

class SimulationManager final : public Manager
{
private:
    std::vector<std::unique_ptr<Manager>> Managers;
private:
    void _body([[maybe_unused]] double delta);
public:
    SimulationManager();
    ~SimulationManager();

    void startUp() override;
    void shutDown() override;
    void run([[maybe_unused]] double delta) override;
};
