#pragma once

class Manager
{
protected:
    bool startUpFlag = false;
public:
    virtual void startUp() = 0;
    virtual void shutDown() = 0;

    virtual void run(
#if __cplusplus >= 201703L
    [[maybe_unused]]
#endif
    double delta) = 0;

    Manager() = default;
    virtual ~Manager() = default;
};
