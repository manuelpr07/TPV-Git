#include "BlockMap.h"
#include "Game.h"
void BlockMap::render()
{
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if(matriz[j][i]!= nullptr)
            matriz[j][i]->render();
        }
    }
}
void BlockMap::readMap(int level)
{
    std::ifstream in("../Mapas/level0" + std::to_string(level)+".DAT");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
    if (in.fail())
        throw std::string(" fichero de mapa de bloques no encontrado o no valido " );
    int aux;
    std::cin >> nFilas >> nColumnas;

    cellHeigth = (winHeigth - 300)/nFilas;
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
    std::cin.rdbuf(cinbuf); 
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

bool BlockMap::colides(Vector2D& pos, int size, double& angle)
{
    Vector2D bloque;
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if (matriz[j][i] != nullptr) {
                bloque = Vector2D(cellWidth * j +15, cellHeigth * i + 20);
                //arriba o abajo
                if ((pos.getX() + size >= bloque.getX() && pos.getX() <= bloque.getX()) ||
                    (pos.getX() >= bloque.getX() && pos.getX() + size <= bloque.getX() + cellWidth) ||
                    (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getX() + cellWidth)){
                    if (pos.getY() <= bloque.getY() + cellHeigth && pos.getY() + size >= bloque.getY() + cellHeigth)// golpea por abajo
                    {
                       
                        pos = { 0, 1 };
                        angle = -1;
                        matriz[j][i] = nullptr;
                        return true;
                    }
                    else if (pos.getY() + size >= bloque.getY() && pos.getY() <= bloque.getY())// golpea por arriba
                    {
                        pos = { 0, -1 };
                        angle = 1;
                        matriz[j][i] = nullptr;
                        return true;
                    }
                }
                //derecha o izquierda
                else if ((pos.getY() + size >= bloque.getY() && pos.getY() <= bloque.getY()) ||
                    (pos.getY() >= bloque.getY() && pos.getY() + size <= bloque.getY() + cellHeigth) ||
                    (pos.getY() <= bloque.getY() + cellHeigth && pos.getY() + size >= bloque.getY() + cellHeigth))
                {

                    if (pos.getX() <= bloque.getX() && pos.getX() + size >= bloque.getX())// golpea por izquieda
                    {
                        pos = { 1, 0 };
                        angle = -1;
                        matriz[j][i] = nullptr;
                        return true;
                    }
                    else if (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getX() + cellWidth)// golpea por derecha
                    {

                        pos = { -1, 0 };
                        angle = 1;
                        matriz[j][i] = nullptr;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}