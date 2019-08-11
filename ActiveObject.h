//
// Created by bt LAPNUG-win10 on 11.08.2019.
//

#ifndef ACTIVEOBJECTLIB_ACTIVEOBJECT_H
#define ACTIVEOBJECTLIB_ACTIVEOBJECT_H

#include <thread>
#include <functional>
#include <queue>

class ActiveObject {
public:
    using Message = std::function<void()>;

    ActiveObject() : thd([=] {
        while (!done) {
            mq.front()();
            mq.pop();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }) {}

    ~ActiveObject() {
        Send([=] { done = true; });
        thd.join();
    }

    void Send(Message m) { mq.push(m); }

private:
    bool done = false;
    std::queue<Message> mq;
    std::thread thd;
};

#endif //ACTIVEOBJECTLIB_ACTIVEOBJECT_H
