#include "BlockMap.h"

void BlockMap::render()
{
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            matriz[i][j].render();
        }
    }
}
void BlockMap::readMap()
{

}
//int BlockMap::getBlocks()
//{
//    int n = 0;
//    for (int i = 0; i < nColumnas; i++) {
//        for (int j = 0; j < nFilas; j++) {
//            if (matriz[i][j] != nullptr)
//                n++;
//        }
//    }
//}