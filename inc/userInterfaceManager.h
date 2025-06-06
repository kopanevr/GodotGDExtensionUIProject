#pragma once

#include <cstdint>
#include <memory>

#include "manager.h"
#include "menu.h"
#include "menu_0.h"

enum class EMenus : uint8_t
{
    MENU_0 = 1U,
    MENU_1

    // , MENU_NUM

    , MENU_DEF
};

class UserInterfaceManager final : public Manager
{
private:
private:
    void _body(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta);

    void setMenu();
private:
    EMenus menuIdentifier = EMenus::MENU_0; // Идентификатор меню.

    std::shared_ptr<Menu> currentMenu; // Текущее меню.

    //

    std::shared_ptr<Menu_0> menu_0;
public:
    UserInterfaceManager();
    ~UserInterfaceManager();

    void startUp() override;
    void shutDown() override;

    void run(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta) override;
};
