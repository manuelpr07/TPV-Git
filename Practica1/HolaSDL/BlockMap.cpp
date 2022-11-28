#include "BlockMap.h"
#include "Game.h"

BlockMap::BlockMap(unsigned int nfil, unsigned int ncol, Texture* text) //: ArcanoidObject(Vector2D{0,0}, 0, 0, nullptr)
{
    nFilas = nfil;
    nColumnas = ncol;
    texture = text;
    for (int i = 0; i < nColumnas; i++) {
        matriz[i] = new Block * [nFilas];
    }
}

BlockMap::~BlockMap()
{
    for (int i = 0; i < nColumnas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}
void BlockMap::render()
{
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if(matriz[j][i]!= nullptr)
            matriz[j][i]->Block::render();
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

    cellHeigth = (WIN_HEIGTH/2)/nFilas;
    cellWidth = (WIN_WIDTH - BLOCK_HEIGHT*2)/nColumnas;
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            std::cin >> aux;
            if (aux != 0)
            {
                matriz[j][i] = new Block(Vector2D(cellWidth * j + BLOCK_HEIGHT, cellHeigth * i + BLOCK_WIDTH), cellHeigth, cellWidth, aux, i, j, texture);
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

bool BlockMap::colides(Vector2D pos, int size, Vector2D& collision_vector, const Vector2D& velocity)
{
    Vector2D bloque;
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if (matriz[j][i] != nullptr) {
                bloque = Vector2D(cellWidth * j + BLOCK_WIDTH, cellHeigth * i + BLOCK_HEIGHT);
                if ((pos.getX() + size >= bloque.getX() && pos.getX() <= bloque.getX()) || (pos.getX() >= bloque.getX() && pos.getX() + size <= bloque.getX() + cellWidth) || (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getX() + cellWidth)) { //arriba o abajo
                    if (pos.getY() <= bloque.getY() + cellHeigth && pos.getY() + size >= bloque.getY() + cellHeigth && velocity.getY() < 0)// golpea por abajo
                    {
                        collision_vector = { 0, 1 };
                        matriz[j][i] = nullptr;
                        return true;
                    }
                    else if (pos.getY() + size >= bloque.getY() && pos.getY() <= bloque.getY() && velocity.getY() > 0)// golpea por arriba
                    {
                        collision_vector = { 0, -1 };
                        matriz[j][i] = nullptr;
                        return true;
                    }
                }
                if ((pos.getY() <= bloque.getY() && pos.getY() + size >= bloque.getY()) || (pos.getY() >= bloque.getY() && pos.getY() + size <= bloque.getY() + cellHeigth) || (pos.getY() <= bloque.getY() + cellHeigth && pos.getY() + size >= bloque.getY() + cellHeigth)){//derecha o izquierda
                    if (pos.getX() <= bloque.getX() && pos.getX() + size >= bloque.getX())// golpea por izquieda
                    {
                        collision_vector = { 1, 0 };
                        matriz[j][i] = nullptr;
                        return true;
                    }
                    else if (pos.getX() <= bloque.getX() + cellWidth && pos.getX() + size >= bloque.getX() + cellWidth)// golpea por derecha
                    {
                        collision_vector = { 1, 0 };
                        matriz[j][i] = nullptr;
                        return true;
                    }
                }
            }
        }
    }
    return false;
}