#include "simulationManager.h"

#include "userInterfaceManager.h"

/**
 * @brief
 */
void SimulationManager::_body(double delta)
{
    for (const std::unique_ptr<Manager>& e : processManagers) { e->run(delta); }
}

/**
 * @brief
 */
SimulationManager::SimulationManager()
{
    processManagers.push_back(std::make_unique<UserInterfaceManager>());
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

    for (const std::unique_ptr<Manager>& e : processManagers) { e->startUp(); }
}

/**
 * @brief
 */
void SimulationManager::shutDown()
{
    for (const std::unique_ptr<Manager>& e : processManagers) { e->shutDown(); }

    startUpFlag = false;
}

/**
 * @brief
 */
void SimulationManager::run(double delta)
{
    if (startUpFlag == false) { return; }

    _body(delta);
}
