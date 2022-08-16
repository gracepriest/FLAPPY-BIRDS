#pragma once
#include "Common.h"
using namespace std;

template <typename T>
class StackFSM
{

public:
    stack<T> GameState;                     // ENUM CLASS
    T currentStateFunction;

    StackFSM()
    {
        if (!GameState.empty())
        {
            currentStateFunction = getCurrentState();
        }
        else
        {
            this->pushState(GAMESTATE::LOAD);
        }
    }
    ~StackFSM()
    {

    }
    T getCurrentState()
    {

        return GameState.top();
    }


    virtual void updateState()
    {
        

        




       

    }


    void popState()
    {
        return GameState.pop();
    }

    void pushState(T state)
    {
        if (GameState.empty())
        {
            GameState.push(state);
        }
        else if (getCurrentState() != state)
        {
            GameState.push(state);
        }
    }

};