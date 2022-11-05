#include "BlockMap.h"
class Game;

void BlockMap::render()
{
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if(matriz[j][i]!= nullptr)
            matriz[j][i]->render();
        }
    }
}
void BlockMap::readMap()
{
    std::ifstream in("../Mapas/level01.DAT");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt

    int aux;
    std::cin >> nFilas >> nColumnas;

    cellHeigth = (winHeigth - 120)/nFilas;
    cellWidth = (winWidth - 40)/nColumnas;
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            std::cin >> aux;
            if (aux != 0)
            {
                matriz[j][i] = new Block(Vector2D(cellWidth * j + 20, cellHeigth * i + 15), cellHeigth, cellWidth, aux, i, j, tex);
            }
            else matriz[j][i] = nullptr;
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

Vector2D BlockMap::colides(Vector2D pos, int size)
{
    Vector2D bloque;
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if (matriz[i][j] != nullptr)
            {
                bloque = Vector2D(cellWidth * j + 20, cellHeigth * i + 15);
                //arriba o abajo
                if ((pos.getX() + size >= bloque.getX() && pos.getX() <= bloque.getX()) || (pos.getX() >= bloque.getX() && pos.getX() + size <= bloque.getX() + cellWidth) || (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getX() + cellWidth))
                {
                    if (pos.getY() >= bloque.getY() + cellHeigth && pos.getY() + size <= bloque.getY() + cellHeigth)// golpea por abajo
                    {

                        return{ 0, -1 };

                    }
                    else if (pos.getY() + size >= bloque.getY() && pos.getY() <= bloque.getY())// golpea por arriba
                    {

                        return{ 0, 1 };

                    }
                }
                //derecha o izquierda
                else if ((pos.getY() + size >= bloque.getY() && pos.getY() <= bloque.getY()) || (pos.getY() >= bloque.getY() && pos.getY() + size <= bloque.getY() + cellHeigth) || (pos.getY() <= bloque.getY() + cellHeigth && pos.getY() + size >= bloque.getY() + cellHeigth))
                {
                    if (pos.getX() <= bloque.getX() && pos.getX() + size >= bloque.getX())// golpea por izquieda
                    {

                        return{ -1, 0 };

                    }
                    else if (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getY() + cellWidth)// golpea por derecha
                    {

                        return{ 1, 0 };

                    }
                }
            }
        }
    }
}