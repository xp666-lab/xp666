#ifndef MINE_H
#define MINE_H

class Mine
{
public:
    Mine();

    bool GenerateMap(int in_raw, int in_column, int in_mineNum);

    void reGenerateMap();

    int getMineNumber();

    unsigned char **map;

private:
    int raw;//行数
    int column;//列数
    int mineNum;//雷数

    bool MallocMemForMap(int in_raw, int in_column, int in_mineNum);

    bool InitMap();

    void PrintMap();
};

#endif // MINE_H
