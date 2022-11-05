#include "BlockMap.h"
class Game;

void BlockMap::render()
{
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if(matriz[i][j]!= nullptr)
            matriz[i][j]->render();
        }
    }
}
void BlockMap::readMap()
{
    std::ifstream in("../Mapas/level01.DAT");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

    int aux;
    std::cin >> nFilas >> nColumnas;
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            std::cin >> aux;
            if (aux != 0)
                matriz[i][j] = new Block({ 0,0 }, cellHeigth, cellWidth, aux, i, j, tex);
            else matriz[i][j] = nullptr;
        }
    } //Block(Vector2D position, unsigned int h, unsigned int w, unsigned int cl, unsigned int fil, unsigned int col, Texture* text)

}
int BlockMap::getBlocks()
{
    int n = 0;
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if (matriz[i][j] != nullptr)
                n++;
        }
    }
    return n;
}