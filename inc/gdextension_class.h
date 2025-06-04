#pragma once

#include <memory>

#include <godot_cpp/core/class_db.hpp> 
#include <godot_cpp/classes/node.hpp>

#include "manager.h"

class GDextension_class final : public godot::Node
{
    GDCLASS(GDextension_class, godot::Node)

private:
    std::unique_ptr<Manager> pSimulationManager;
private:
    void _body(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta);

    void _progress(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta);

    void _ready();
    void _exit_tree();
public:
    GDextension_class();
    ~GDextension_class();
};
