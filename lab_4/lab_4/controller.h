#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QGridLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define FLOOR_COUNT    19

class Controller : public QWidget
{
    Q_OBJECT;

    enum ControllerState
    {
        OUTTARGET,
        TARGETFIND,
        TARGETAPPER,
        TARGETTED,
    };

public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller() = default;

public slots:
    void newTarget(size_t floor, Direction dir);
    void floorReach(size_t floor, Direction dir);
    void outtarget();
    void calcTarget(size_t floor, Direction dir);

signals:
    void newTargetSignal(size_t floor, size_t target);
    void stoppedSignal();
    void floorReachedSignal(size_t target, Direction dir);
    void floorAppearSignal(size_t floor, Direction dir);
    void outtargetSignal(size_t floor, size_t target);
    void stayingSignal(size_t floor, size_t target);
    void unpressSignal(size_t floor, Direction dir);

private:
    bool targetExist(size_t &new_floor);

private:
    ControllerState _state;
    size_t _floor;
    size_t _target;
    Direction _dir;

    std::vector<std::shared_ptr<Button>> _buttons_up;
    std::vector<std::shared_ptr<Button>> _buttons_cabin;
    std::vector<std::shared_ptr<Button>> _buttons_down;

    std::vector<bool> _floors_upper_order;
    std::vector<bool> _floors_cabin_order;
    std::vector<bool> _floors_down_order;

    std::unique_ptr<QGridLayout> _layout;
};

#endif
