#pragma once

class Manager
{
protected:
    bool startUpFlag = false;
public:
    virtual void startUp() = 0;
    virtual void shutDown() = 0;
    virtual void run([[maybe_unused]] double delta) = 0;

    Manager() = default;
    virtual ~Manager() = default;
};
