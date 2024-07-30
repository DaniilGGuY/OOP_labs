#include "doors.h"

Doors::Doors() : _state(CLOSED)
{
    QObject::connect(&_opening_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&_opened_timer,  SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(&_closing_timer, SIGNAL(timeout()), this, SLOT(closed()));
}

void Doors::opening()
{
    if (_state == CLOSED || _state == CLOSING)
    {
        _state = OPENING;
        qDebug() << "Двери открываются...";
        auto closing_time = _closing_timer.remainingTime();
        _closing_timer.stop();
        _opening_timer.start(DOORS_TIME - closing_time);
    }
}

void Doors::opened()
{
    if (_state == OPENING)
    {
        _state = OPENED;
        qDebug() << "Двери открыты...";
        _opened_timer.start(DOORS_TIME);
    }
}

void Doors::closing()
{
    if (_state == OPENED)
    {
        _state = CLOSING;
        qDebug() << "Двери закрываются...";
        _closing_timer.start(DOORS_TIME);
    }
}

void Doors::closed()
{
    if (_state == CLOSING)
    {
        _state = CLOSED;
        qDebug() << "Двери закрыты.";
        emit closedSignal();
    }
}
