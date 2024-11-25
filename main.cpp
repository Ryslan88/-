#include "automobile.h"

int main() {
    Automobile autoObj;
    
    autoObj.displayAutomobileData(); 

    autoObj.inputAutomobileData();
    autoObj.displayAutomobileData();

    autoObj.updateAutomobileByNumber();
    autoObj.displayAutomobileData();

    autoObj.searchAutomobile();

    return 0;
}
