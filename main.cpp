//
// Created by bt LAPNUG-win10 on 11.08.2019.
//

#include <iostream>
#include "ActiveObject.h"

int main() {
    ActiveObject activeObject;
    activeObject.Send([] {
        std::cout << "test1" << std::endl;
    });

    activeObject.Send([] {
        std::cout << "test2" << std::endl;
    });

    activeObject.Send([] {
        std::cout << "test3" << std::endl;
    });

    std::cout << "ending main";
}