#include <wireframe.h>

int main(){
    wfrInit();

    wfrVec2 p1, p2;

    p1.x = 10;
    p1.y = 10;
    p2.x = 50;
    p2.y = 20;

    wfrDrawLine(p1, p2);

    while (1){
        wfrRefresh();
    }
    

    wfrTerminate();
    return 0;
}