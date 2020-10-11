#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mine.h"
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    unsigned int defaultMap[3][3] = {{9,9,10},
                                     {16,16,40},
                                     {16,30,100}};

    bool ChangeLevel(int raw, int column, int mineNum);

    bool Restart();

    void paintEvent(QPaintEvent *);

    void mousePressEvent(QMouseEvent *event);

    bool MallocMemForMap_IsPushed(int in_raw, int in_column);

    void InitMap_IsPushed();

    bool GeneratePushedMap(int in_raw, int in_column);

    bool GenerateGlobalMap(int in_raw, int in_column, int in_mineNum);

    void changePosToIndex(int *px, int *py);

    void recursiveFreshBlock(int raw_pos, int col_pos);

    void pressLeftRightButtonPorc(int raw_pos, int col_pos);

    void pressLeftButtonProc(int raw_pos, int col_pos);

    void pressRightButtonProc(int raw_pos, int col_pos);

    //检查状态
    void JudgeIsOver();

    Mine m;

    //地图方格的起始位置偏移
    int map_XOffset;
    int map_YOffset;

    //时间栏的起始位置偏移
    int time_XOffset;
    int time_YOffset;

    //初始状态均置为0
    struct StateFlag
    {
        bool IsOver;//游戏是否结束的状态，如果已经结束，置1，未结束置0。
        bool IsStart;//游戏是否开始的状态，如果已经开始，置1，未开始置0.
        bool result;//游戏结果，胜利置1,失败置0.
    }STATE_FLAG;

private slots:
    void on_actionExit_triggered();

    void on_actionprimary_triggered();

    void on_actionmedium_triggered();

    void on_actionexpert_triggered();

    void on_actionRestart_triggered();

    void on_timeChange();

    void on_actionVersion_triggered();

    void on_actionAuthor_triggered();

private:
    //上层地图标记，0:未点击过，1:点击过，2:插上了小旗
    int **map_flag;
    int raw;
    int column;

    //剩余雷的个数
    int mine_Left;

    //计时器
    QTimer *timer;
    int time_cost;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
