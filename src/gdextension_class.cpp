#include "gdextension_class.h"

#include "simulationManager.h"

/**
 * @brief
 */
void GDextension_class::_body([[maybe_unused]] double delta)
{
    if (simulationManager.get() != nullpr) { pSimulationManager->run(delta); }
}

/**
 * @brief
 */
void GDextension_class::_progress([[maybe_unused]] double delta)
{
    _body(delta);
}

/**
 * @brief
 */
void GDextension_class::_ready()
{
    if (pSimulationManager.get() != nullpr) { pSimulationManager->startUp(); }
}

/**
 * @brief
 */
void GDextension_class::_exit_tree()
{
    if (pSimulationManager.get() != nullpr) { pSimulationManager->shutDown(); }
}

/**
 * @brief
 */
GDextension_class::GDextension_class()
{
    pSimulationManager = std::make_unique<SimulationManager>();
}

/**
 * @brief
 */
GDextension_class::~GDextension_class()
{
}
