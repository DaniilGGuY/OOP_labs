#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "doors.h"
#include "controller.h"

#define MOVING_TIME 1000

class Cabin : public QObject
{
    Q_OBJECT;

    enum CabinState
    {
        WAIT,
        GET_TARGET,
        MOVING,
        STAY,
        MESSAGE
    };

public:
    explicit Cabin(QObject *parent = nullptr);
    ~Cabin() = default;

public slots:
    void getTarget(size_t floor, size_t target);
    void stopped(size_t floor, size_t target);
    void staying(size_t floor, size_t target);
    void workDone();
    void moving();

signals:
    void openDoorsSignal();
    void floorPassedSignal(size_t floor, Direction dir);
    void movingSignal();
    void floorCompleteSignal(size_t floor, Direction dir);

private:
    CabinState _state;
    size_t _floor;
    size_t _target;
    Direction _dir;
    Doors _doors;
    QTimer _move_timer;
};

#endif
