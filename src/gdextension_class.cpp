#include "gdextension_class.h"

#include "simulationManager.h"

/**
 * @brief
 */
void GDextension_class::_body(double delta)
{
    if (pSimulationManager.get() != nullptr) { pSimulationManager->run(delta); }
}

/**
 * @brief
 */
void GDextension_class::_progress(double delta)
{
    _body(delta);
}

/**
 * @brief
 */
void GDextension_class::_ready()
{
    if (pSimulationManager.get() != nullptr) { pSimulationManager->startUp(); }
}

/**
 * @brief
 */
void GDextension_class::_exit_tree()
{
    if (pSimulationManager.get() != nullptr) { pSimulationManager->shutDown(); }
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
