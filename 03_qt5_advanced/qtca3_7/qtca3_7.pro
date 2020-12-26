QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../mylib/mylib.h \
    ../mylib/mylib_global.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../mylib/release/ -lmylib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../mylib/debug/ -lmylib
else:unix: LIBS += -L$$PWD/../mylib/ -lmylib

INCLUDEPATH += $$PWD/../mylib
DEPENDPATH += $$PWD/../mylib
