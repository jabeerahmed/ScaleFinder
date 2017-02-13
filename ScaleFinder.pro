QT += core
QT -= gui

CONFIG += c++11

TARGET = ScaleFinder
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

#  enum Api {
#    UNSPECIFIED,    /*!< Search for a working compiled API. */
#    MACOSX_CORE,    /*!< Macintosh OS-X Core Midi API. */
#    LINUX_ALSA,     /*!< The Advanced Linux Sound Architecture API. */
#    UNIX_JACK,      /*!< The JACK Low-Latency MIDI Server API. */
#    WINDOWS_MM,     /*!< The Microsoft Multimedia MIDI API. */
#    RTMIDI_DUMMY    /*!< A compilable but non-functional API. */
#  };

macx {
    message("Building for mac osx")
    DEFINES += __MACOSX_CORE__=0x1
    LIBS += -framework CoreFoundation
    LIBS += -framework AudioToolbox
    LIBS += -framework AudioUnit
    LIBS += -framework CoreAudio
    LIBS += -framework CoreServices
    LIBS += -framework CoreMIDI
}

unix:!macx {
    message("Building for unix only")
    DEFINES += __UNIX_JACK__=0x1
}


win32 {
    message("Building for Windows")
    DEFINES += __WINDOWS_MM__
    LIBS += -lwinmm
}


SOURCES += ScaleFinder/main.cpp \
           ScaleFinder/BasicTypes.cpp \
           ScaleFinder/Data.cpp \
           ScaleFinder/NoteFactory.cpp \
           ScaleFinder/ScaleFactory.cpp \
           ScaleFinder/rtmidi/RtMidi.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    ScaleFinder/BasicTypes.hpp \
    ScaleFinder/Data.hpp \
    ScaleFinder/NoteFactory.hpp \
    ScaleFinder/ScaleFactory.hpp \
    ScaleFinder/rtmidi/RtMidi.h


INCLUDEPATH += ScaleFinder/rtmidi

QMAKE_CXXFLAGS += -std=c++11



DISTFILES += \
    ScaleFinder/rtmidi/autogen.sh \
    ScaleFinder/rtmidi/rtmidi-config.in \
    ScaleFinder/rtmidi/msw/rtmidilib.vcproj \
    ScaleFinder/rtmidi/doc/images/ccrma.gif \
    ScaleFinder/rtmidi/doc/images/mcgill.gif \
    ScaleFinder/rtmidi/doc/doxygen/footer.html \
    ScaleFinder/rtmidi/doc/doxygen/header.html \
    ScaleFinder/rtmidi/doc/doxygen/Doxyfile.in \
    ScaleFinder/rtmidi/doc/doxygen/tutorial.txt \
    ScaleFinder/rtmidi/doc/release.txt \
    ScaleFinder/rtmidi/msw/rtmidilib.sln \
    ScaleFinder/rtmidi/tests/cmidiin.dsp \
    ScaleFinder/rtmidi/tests/midiout.dsp \
    ScaleFinder/rtmidi/tests/midiprobe.dsp \
    ScaleFinder/rtmidi/tests/qmidiin.dsp \
    ScaleFinder/rtmidi/tests/RtMidi.dsw \
    ScaleFinder/rtmidi/tests/sysextest.dsp \
    ScaleFinder/rtmidi/rtmidi.pc.in \
    ScaleFinder/rtmidi/README.md \
    ScaleFinder/rtmidi/msw/readme

