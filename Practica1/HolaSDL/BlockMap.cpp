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

    cellHeigth = (WIN_HEIGTH/2)/nFilas;
    cellWidth = (WIN_WIDTH - BLOCK_HEIGHT*2)/nColumnas;
    for (int i = 0; i < nFilas; i++) {
        for (int j = 0; j < nColumnas; j++) {
            std::cin >> aux;
            if (aux != 0)
            {
                matriz[j][i] = new Block(Vector2D(cellWidth * j + BLOCK_HEIGHT, cellHeigth * i + BLOCK_WIDTH), cellHeigth, cellWidth, aux, i, j, getText());
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

bool BlockMap::colides(SDL_Rect rect, Vector2D& collision_vector, const Vector2D& velocity)
{
    Vector2D bloque;
    for (int i = 0; i < nColumnas; i++) {
        for (int j = 0; j < nFilas; j++) {
            if (matriz[j][i] != nullptr) {
                bloque = Vector2D(cellWidth * j + BLOCK_WIDTH, cellHeigth * i + BLOCK_HEIGHT);
                //arriba o abajo
                if ((rect.x + rect.w >= bloque.getX() && rect.x <= bloque.getX()) ||
                    (rect.x >= bloque.getX() && rect.x + rect.w <= bloque.getX() + cellWidth) ||
                    (rect.x <= bloque.getX() + cellWidth && rect.x + rect.w >= bloque.getX() + cellWidth))
                {
                    if (rect.y <= bloque.getY() + cellHeigth && rect.y + rect.w >= bloque.getY() + cellHeigth &&
                        velocity.getY() < 0)// golpea por abajo
                    {
                       
                        collision_vector = { 0, 1 };
                        game->createReward(Vector2D(cellWidth * j + BLOCK_HEIGHT / 2, cellHeigth * i + BLOCK_WIDTH / 2));
                        matriz[i][j] = nullptr;
                        return true;
                    }
                    else if (rect.y + rect.w >= bloque.getY() && rect.y <= bloque.getY() &&
                        velocity.getY() > 0)// golpea por arriba
                    {
                        collision_vector = { 0, -1 };
                        game->createReward(Vector2D(cellWidth * j + BLOCK_HEIGHT / 2, cellHeigth * i + BLOCK_WIDTH / 2));
                        matriz[i][j] = nullptr;
                        return true;
                    }
                }
                //derecha o izquierda
                if ((rect.y <= bloque.getY() && rect.y + rect.w >= bloque.getY()) ||
                    (rect.y >= bloque.getY() && rect.y + rect.w <= bloque.getY() + cellHeigth) ||
                    (rect.y <= bloque.getY() + cellHeigth && rect.y + rect.w >= bloque.getY() + cellHeigth))
                    {

                        if (rect.x <= bloque.getX() && rect.x + rect.w >= bloque.getX())// golpea por izquieda
                        {
                            collision_vector = { -1, 0 };
                            game->createReward(Vector2D(cellWidth * j + BLOCK_HEIGHT / 2, cellHeigth * i + BLOCK_WIDTH / 2));
                            matriz[i][j] = nullptr;
                            return true;
                        }
                        else if (rect.x <= bloque.getX() + cellWidth && rect.x + rect.w >= bloque.getX() + cellWidth)// golpea por derecha
                        {
                            collision_vector = { 1, 0 };
                            game->createReward(Vector2D(cellWidth * j + BLOCK_HEIGHT / 2, cellHeigth * i + BLOCK_WIDTH / 2));
                            matriz[i][j] = nullptr;
                            return true;
                        }
                    }
            }
        }
    }
    return false;
}

void BlockMap::breakBlock(int i, int j)
{

}