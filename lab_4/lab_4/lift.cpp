#include "lift.h"

Lift::Lift(QObject *parent) : QObject(parent)
{
    _controller.setStyleSheet("background-color:grey;");
    QObject::connect(&_cabin, SIGNAL(floorPassedSignal(size_t,Direction)), &_controller, SLOT(floorReach(size_t,Direction)));
    QObject::connect(&_cabin, SIGNAL(floorCompleteSignal(size_t,Direction)), &_controller, SLOT(calcTarget(size_t,Direction)));
    QObject::connect(&_controller, SIGNAL(newTargetSignal(size_t,size_t)), &_cabin, SLOT(getTarget(size_t,size_t)));
    QObject::connect(&_controller, SIGNAL(stayingSignal(size_t,size_t)), &_cabin, SLOT(staying(size_t,size_t)));
    QObject::connect(&_controller, SIGNAL(outtargetSignal(size_t,size_t)), &_cabin, SLOT(stopped(size_t,size_t)));
}

QWidget *Lift::widget()
{
    return &_controller;
}
