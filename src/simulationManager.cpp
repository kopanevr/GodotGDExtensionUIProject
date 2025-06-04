#include "simulationManager.h"

#include "userInterfaceManager.h"

/**
 * @brief
 */
void SimulationManager::_body(double delta)
{
    for (const std::unique_ptr<Manager>& e : managers) { e->run(delta); }
}

/**
 * @brief
 */
SimulationManager::SimulationManager()
{
    managers.push_back(std::make_unique<UserInterfaceManager>());
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

    for (const std::unique_ptr<Manager>& e : managers) { e->startUp(); }
}

/**
 * @brief
 */
void SimulationManager::shutDown()
{
    for (const std::unique_ptr<Manager>& e : managers) { e->shutDown(); }

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
