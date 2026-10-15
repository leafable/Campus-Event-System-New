#include <iostream>
#include <limits>
#include "../include/System.h"

using namespace std;

int getSelection();
void processSelection(int selection, System& system);

int main()
{
    System system;

    system.runSystem();

    return 0;
}