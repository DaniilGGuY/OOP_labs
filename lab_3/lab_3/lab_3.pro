QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    builders/basecarcasbuilder.cpp \
    builders/listcarcasbuilder.cpp \
    builders/matrixcarcasbuilder.cpp \
    commands/basecommand.cpp \
    commands/camera/addcameracommand.cpp \
    commands/camera/basecameracommand.cpp \
    commands/camera/removecameracommand.cpp \
    commands/camera/setcameracommand.cpp \
    commands/draw/basedrawcommand.cpp \
    commands/draw/drawsceneqtcommand.cpp \
    commands/load/baseloadcommand.cpp \
    commands/load/baseloadcommanddecorator.cpp \
    commands/load/listloadcommand.cpp \
    commands/load/matrixloadcommand.cpp \
    commands/load/txtloadcommanddecorator.cpp \
    commands/object/baseobjectcommand.cpp \
    commands/object/compositeobjectcommand.cpp \
    commands/object/removeobjectcommand.cpp \
    commands/object/rotateobjectcommand.cpp \
    commands/object/scaleobjectcommand.cpp \
    commands/object/shiftobjectcommand.cpp \
    commands/scene/basescenecommand.cpp \
    commands/scene/clearscenecommand.cpp \
    commands/scene/getcameraidsscenecommand.cpp \
    commands/scene/getobjectidsscenecommand.cpp \
    directors/basecarcasdirector.cpp \
    directors/basedirector.cpp \
    directors/directorsolution.cpp \
    directors/listcarcasdirector.cpp \
    directors/matrixcarcasdirector.cpp \
    drawer/basedrawer.cpp \
    drawer/basedrawercreator.cpp \
    drawer/qtdrawer.cpp \
    drawer/qtdrawercreator.cpp \
    facade/facade.cpp \
    main.cpp \
    mainwindow.cpp \
    managers/loadmanager.cpp \
    managers/scenemanager.cpp \
    managers/transformmanager.cpp \
    objects/basemodel.cpp \
    objects/camera.cpp \
    objects/carcasmodel.cpp \
    objects/composite.cpp \
    objects/edge.cpp \
    objects/invisibleobject.cpp \
    objects/object.cpp \
    objects/point.cpp \
    objects/strategy/basecentralstrategy.cpp \
    objects/structures/carcasstructure.cpp \
    objects/structures/listcarcasstructure.cpp \
    objects/structures/matrixcarcasstructure.cpp \
    objects/visibleobject.cpp \
    readers/basereader.cpp \
    readers/carcasreader.cpp \
    readers/readersolution.cpp \
    readers/txtcarcasreader.cpp \
    scene/scene.cpp \
    transform/cameraaction.cpp \
    transform/rotateaction.cpp \
    transform/scaleaction.cpp \
    transform/transferaction.cpp \
    transform/transformaction.cpp \
    visitors/drawvisitor.cpp \
    visitors/transformvisitor.cpp \
    visitors/visitor.cpp

HEADERS += \
    builders/basecarcasbuilder.h \
    builders/listcarcasbuilder.h \
    builders/matrixcarcasbuilder.h \
    commands/basecommand.h \
    commands/camera/addcameracommand.h \
    commands/camera/basecameracommand.h \
    commands/camera/removecameracommand.h \
    commands/camera/setcameracommand.h \
    commands/draw/basedrawcommand.h \
    commands/draw/drawsceneqtcommand.h \
    commands/load/baseloadcommand.h \
    commands/load/baseloadcommanddecorator.h \
    commands/load/listloadcommand.h \
    commands/load/matrixloadcommand.h \
    commands/load/txtloadcommanddecorator.h \
    commands/object/baseobjectcommand.h \
    commands/object/compositeobjectcommand.h \
    commands/object/removeobjectcommand.h \
    commands/object/rotateobjectcommand.h \
    commands/object/scaleobjectcommand.h \
    commands/object/shiftobjectcommand.h \
    commands/scene/basescenecommand.h \
    commands/scene/clearscenecommand.h \
    commands/scene/getcameraidsscenecommand.h \
    commands/scene/getobjectidsscenecommand.h \
    directors/basecarcasdirector.h \
    directors/basedirector.h \
    directors/basedirectorcreator.h \
    directors/directorcreator.h \
    directors/directorcreator.hpp \
    directors/directorsolution.h \
    directors/listcarcasdirector.h \
    directors/matrixcarcasdirector.h \
    drawer/basedrawer.h \
    drawer/basedrawercreator.h \
    drawer/qtdrawer.h \
    drawer/qtdrawercreator.h \
    facade/facade.h \
    mainwindow.h \
    managers/drawmanager.h \
    managers/drawmanager.hpp \
    managers/loadmanager.h \
    managers/scenemanager.h \
    managers/transformmanager.h \
    objects/basemodel.h \
    objects/camera.h \
    objects/carcasmodel.h \
    objects/composite.h \
    objects/edge.h \
    objects/invisibleobject.h \
    objects/object.h \
    objects/point.h \
    objects/strategy/basecentralstrategy.h \
    objects/structures/carcasstructure.h \
    objects/structures/listcarcasstructure.h \
    objects/structures/matrixcarcasstructure.h \
    objects/visibleobject.h \
    readers/basereader.h \
    readers/basereadercreator.h \
    readers/carcasreader.h \
    readers/readercreator.h \
    readers/readercreator.hpp \
    readers/readersolution.h \
    readers/txtcarcasreader.h \
    scene/scene.h \
    square_matrix/squarematrix.h \
    square_matrix/squarematrix.hpp \
    transform/cameraaction.h \
    transform/rotateaction.h \
    transform/scaleaction.h \
    transform/transferaction.h \
    transform/transformaction.h \
    visitors/drawvisitor.h \
    visitors/transformvisitor.h \
    visitors/visitor.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
