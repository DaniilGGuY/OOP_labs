#include "controller.h"

Controller::Controller(QWidget *parent) : QWidget(parent), _state(OUTTARGET), _floor(1), _target(1), _dir(STOP)
{
    _layout = std::unique_ptr<QGridLayout>(new QGridLayout);
    setLayout(_layout.get());

    _floors_cabin_order = std::vector(FLOOR_COUNT, true);
    _floors_upper_order = std::vector(FLOOR_COUNT, true);
    _floors_down_order = std::vector(FLOOR_COUNT, true);

    QObject::connect(this, SIGNAL(floorReachedSignal(size_t,Direction)), this, SLOT(floorReach(size_t,Direction)));
    QObject::connect(this, SIGNAL(floorAppearSignal(size_t,Direction)), this, SLOT(calcTarget(size_t,Direction)));
    QObject::connect(this, SIGNAL(stoppedSignal()), this, SLOT(outtarget()));

    for (int i = 2; i <= FLOOR_COUNT; ++i)
    {
        std::shared_ptr<Button> button(new Button(i, DOWN));
        _buttons_down.push_back(button);
        QObject::connect(button.get(), SIGNAL(buttonPressedSignal(size_t,Direction)), this, SLOT(newTarget(size_t,Direction)));
        QObject::connect(this, SIGNAL(unpressSignal(size_t,Direction)), button.get(), SLOT(unpressed(size_t,Direction)));
        _layout->addWidget(button.get(), FLOOR_COUNT - i, 0);
    }

    for (int i = 1; i <= FLOOR_COUNT - 1; ++i)
    {
        std::shared_ptr<Button> button(new Button(i, UP));
        _buttons_down.push_back(button);
        QObject::connect(button.get(), SIGNAL(buttonPressedSignal(size_t,Direction)), this, SLOT(newTarget(size_t,Direction)));
        QObject::connect(this, SIGNAL(unpressSignal(size_t,Direction)), button.get(), SLOT(unpressed(size_t,Direction)));
        _layout->addWidget(button.get(), FLOOR_COUNT - i, 1);
    }

    for (int i = 1; i <= FLOOR_COUNT; ++i)
    {
        std::shared_ptr<Button> button(new Button(i, LIFT));
        _buttons_down.push_back(button);
        QObject::connect(button.get(), SIGNAL(buttonPressedSignal(size_t,Direction)), this, SLOT(newTarget(size_t,Direction)));
        QObject::connect(this, SIGNAL(unpressSignal(size_t,Direction)), button.get(), SLOT(unpressed(size_t,Direction)));
        _layout->addWidget(button.get(), FLOOR_COUNT - i, 2);
    }
}

void Controller::newTarget(size_t floor, Direction dir)
{
    if (dir == UP)
        _floors_upper_order[floor - 1] = 0;
    else if (dir == DOWN)
        _floors_down_order[floor - 1] = 0;
    else if (dir == LIFT)
        _floors_cabin_order[floor - 1] = 0;

    _state = TARGETFIND;
    targetExist(_target);
    emit newTargetSignal(_floor, _target);
    emit floorReachedSignal(_floor, _dir);
}

void Controller::calcTarget(size_t floor, Direction dir)
{
    if (_state == TARGETTED)
    {
        _state = TARGETAPPER;
        _floor = floor;
        _dir = dir;
        if (!targetExist(_target))
        {
            emit stoppedSignal();
            return;
        }

        emit newTargetSignal(_floor, _target);
    }
}

void Controller::floorReach(size_t floor, Direction dir)
{
    if (_state == TARGETFIND || _state == TARGETAPPER || _state == TARGETTED)
    {
        _state = TARGETTED;
        _floor = floor;
        _dir = dir;

        if (_dir == DOWN && !_floors_down_order[_floor - 1])
        {
            _floors_cabin_order[_floor - 1] = 1;
            _floors_down_order[_floor - 1] = 1;
            emit unpressSignal(_floor, LIFT);
            emit unpressSignal(_floor, DOWN);
            emit stayingSignal(_floor, _target);
        }
        else if (_dir == UP && !_floors_upper_order[_floor - 1])
        {
            _floors_cabin_order[_floor - 1] = 1;
            _floors_upper_order[_floor - 1] = 1;
            emit unpressSignal(_floor, LIFT);
            emit unpressSignal(_floor, UP);
            emit stayingSignal(_floor, _target);
        }
        else if (!_floors_cabin_order[_floor - 1])
        {
            _floors_cabin_order[_floor - 1] = 1;
            emit unpressSignal(_floor, LIFT);
            emit stayingSignal(_floor, _target);
        }
        else if (_floor == _target)
        {
            _floors_cabin_order[_floor - 1] = 1;
            _floors_down_order[_floor - 1] = 1;
            _floors_upper_order[_floor - 1] = 1;
            emit unpressSignal(_floor, LIFT);
            emit unpressSignal(_floor, DOWN);
            emit unpressSignal(_floor, UP);
            emit stayingSignal(_floor, _target);
        }
    }
}

void Controller::outtarget()
{
    if (_state == TARGETTED)
    {
        _state = OUTTARGET;
        _dir = STOP;
        _target = _floor;
        emit outtargetSignal(_floor, _target);
    }
}

bool Controller::targetExist(size_t &new_floor)
{
    if (_dir == STOP || _dir == DOWN)
    {
        for (size_t i = 1; i <= _floor; ++i)
        {
            if (!_floors_cabin_order[i - 1] || !_floors_upper_order[i - 1] || !_floors_down_order[i - 1])
            {
                _dir = DOWN;
                new_floor = i;
                return true;
            }
        }

        for (size_t i = FLOOR_COUNT; i > _floor; --i)
        {
            if (!_floors_cabin_order[i - 1] || !_floors_upper_order[i - 1] || !_floors_down_order[i - 1])
            {
                _dir = UP;
                new_floor = i;
                return true;
            }
        }
    }
    else
    {
        for (size_t i = FLOOR_COUNT; i >= _floor; --i)
        {
            if (!_floors_cabin_order[i - 1] || !_floors_upper_order[i - 1] || !_floors_down_order[i - 1])
            {
                _dir = UP;
                new_floor = i;
                return true;
            }
        }

        for (size_t i = 1; i < _floor; ++i)
        {
            if (!_floors_cabin_order[i - 1] || !_floors_upper_order[i - 1] || !_floors_down_order[i - 1])
            {
                _dir = DOWN;
                new_floor = i;
                return true;
            }
        }
    }

    return false;
}
