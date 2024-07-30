#include "cabin.h"

Cabin::Cabin(QObject *parent) : QObject(parent), _state(WAIT), _floor(1), _target(1), _dir(STOP)
{
    QObject::connect(&_move_timer, SIGNAL(timeout()), this, SLOT(moving()));
    QObject::connect(this, SIGNAL(movingSignal()), this, SLOT(moving()));
    QObject::connect(&_doors, SIGNAL(closedSignal()), this, SLOT(workDone()));
    QObject::connect(this, SIGNAL(openDoorsSignal()), &_doors, SLOT(opening()));
}

void Cabin::getTarget(size_t floor, size_t target)
{
    if (_state == WAIT || _state == MESSAGE)
    {
        _state = GET_TARGET;
        _floor = floor;
        _target = target;
        _dir = target > floor ? UP : DOWN;
        emit movingSignal();
    }
}

void Cabin::stopped(size_t floor, size_t target)
{
    if (_state == MOVING)
    {
        _state = WAIT;
        _floor = floor;
        _target = target;
        _dir = STOP;
        _move_timer.stop();
        qDebug() << "Лифт остановился на " << _floor << " этаже.";
    }
}

void Cabin::staying(size_t floor, size_t target)
{
    if (_state == MOVING)
    {
        _state = STAY;
        _floor = floor;
        _target = target;
        _dir = target > floor ? UP : DOWN;
        _move_timer.stop();
        qDebug() << "Лифт остановился на " << _floor << " этаже.";
        emit openDoorsSignal();
    }
}

void Cabin::workDone()
{
    if (_state == STAY)
    {
        _state = MESSAGE;
        emit floorCompleteSignal(_floor, _dir);
    }
}

void Cabin::moving()
{
    if (_state == GET_TARGET)
        _state = MOVING;
    else
        _floor += _dir;

    _move_timer.start(MOVING_TIME);
    qDebug() << "Лифт едет. Этаж: " << _floor;
    emit floorPassedSignal(_floor, _dir);
}
