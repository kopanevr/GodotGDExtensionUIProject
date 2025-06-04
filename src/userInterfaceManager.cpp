#include "userInterfaceManager.h"

/**
 * @brief
 */
void UserInterfaceManager::_body(double delta)
{
}

/**
 * @brief
 */
void UserInterfaceManager::setMenu()
{
    static EMenus previousMenuIdentifier = menuIdentifier;

    if (menuIdentifier == previousMenuIdentifier){ return; }

    previousMenuIdentifier = menuIdentifier;

    switch (menuIdentifier)
    {
    case EMenus::MENU_0:
        currentMenu = menu_0;
        break;
    case EMenus::MENU_1:
        currentMenu = nullptr;
        break;
    default:
        currentMenu = nullptr;
        break;
    }
}

/**
 * @brief
 */
UserInterfaceManager::UserInterfaceManager()
{
    currentMenu = std::make_shared<Menu>();

    //

    menu_0 = std::make_shared<Menu_0>();

    //
}

/**
 * @brief
 */
UserInterfaceManager::~UserInterfaceManager()
{
}

/**
 * @brief
 */
void UserInterfaceManager::startUp()
{
    startUpFlag = true;

    setMenu();
}

/**
 * @brief
 */
void UserInterfaceManager::shutDown()
{
    startUpFlag = false;
}

/**
 * @brief
 */
void UserInterfaceManager::run(double delta)
{
    if (startUpFlag == false) { return; }

    _body(delta);
}
