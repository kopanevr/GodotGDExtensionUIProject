#include "simulationManager.h"

#include "userInterfaceManager.h"

/**
 * @brief
 */
void SimulationManager::_body([[maybe_unused]] double delta)
{
    for (const std::unique_ptr<Manager>& e : pManagers) { e->run(delta); }
}

/**
 * @brief
 */
SimulationManager::SimulationManager()
{
    pManagers.push_back(std::make_unique<UserInterfaceManager>());
}

/**
 * @brief
 */
SimulationManager::~SimulationManager()
{
}

/**
 * @brief
 */
void SimulationManager::startUp()
{
    startUpFlag = true;

    for (const std::unique_ptr<Manager>& e : pManagers) { e->startUp(); }
}

/**
 * @brief
 */
void SimulationManager::shutDown()
{
    for (const std::unique_ptr<Manager>& e : pManagers) { e->shutDown(); }

    startUpFlag = false;
}

/**
 * @brief
 */
void SimulationManager::run([[maybe_unused]] double delta)
{
    if (startUpFlag == false) { return; }

    _body(delta);
}
