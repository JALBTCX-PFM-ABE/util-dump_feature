INCLUDEPATH += /c/PFM_ABEv7.0.0_Win64/include
LIBS += -L /c/PFM_ABEv7.0.0_Win64/lib -lnvutility -lBinaryFeatureData -lgdal -lxml2 -lpoppler -lm -liconv -lstdc++
DEFINES += NVWIN3X XML_LIBRARY
CONFIG += console
CONFIG -= qt
QMAKE_LFLAGS += 
######################################################################
# Automatically generated by qmake (2.01a) Wed Jan 22 13:44:44 2020
######################################################################

TEMPLATE = app
TARGET = dump_feature
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += version.h
SOURCES += main.c