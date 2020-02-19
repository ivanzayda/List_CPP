#include <iostream>
#include "List.h"

using namespace std;


int main() {
    List<int> list;
    list.Add(1);
    list.Add(2);
    list.Add(3);
    list.Add(4);
    list.Add(5);
    list.Add(6 );
    cout << list[5];
    return 0;
}
