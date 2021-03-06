#ifndef CATAN_MAP_H
#define CATAN_MAP_H

#include <QMainWindow>
#include <QtCore>
#include <QMessageBox>
#include "map_tracker/map_tracker.h"
#include "player/Player.h"
//#include "player/Noder.h"

namespace Ui {
    class catan_map;
}

class catan_map : public QMainWindow
{
    Q_OBJECT

public:
    explicit catan_map(QWidget *parent = 0);
    ~catan_map();
   // void checkPlayer();

private slots:
    void signalSorter(const QString &); //sorts signals

private:
    ///temporary test code (DELETE WHEN FINISHED!)
    int temp_iterator;

    Ui::catan_map *ui;
    QSignalMapper *signalMapper;
    map_tracker mapper;

    Player players[4];
    QString player_name;
    int iter;
    int numPlayers;
    Node node;

    bool robber;
    bool initial_settle;
    bool reverse;
    bool init_settle_road;

    void initial_game_start(QString);
    void city_settlement_create(QString);
    void road_pushed(QString);
    void update_players();
    void initial_settle_place();
    void changeNode(QString);
    void activate_settlements();
    void activate_roads();
    void activate_other();
    void button_output(QString);
    void settlement_output(QString);
    void city_output(QString);
    void road_output(QString);
    void activate_nodes();

    void nodeSelectedOnRobber(QString);
    void rollSelected(QString);
    void viewHand(QString);

};

#endif // CATAN_MAP_H
