#############################################################################
# Makefile for building: libmezzoAnalyzer.so.1.0.0
# Generated by qmake (2.01a) (Qt 4.2.2) on: Tue Jul 24 21:56:25 2007
# Project:  mezzoAnalyzer.pro
# Template: lib
# Command: /usr/lib/qt4/bin/qmake -unix -o Makefile mezzoAnalyzer.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
LEX           = flex
YACC          = yacc
DEFINES       = -DQT_NO_DEBUG -DQT_SVG_LIB -DQT_QT3SUPPORT_LIB -DQT3_SUPPORT -DQT_XML_LIB -DQT_GUI_LIB -DQT_NETWORK_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC  $(DEFINES)
CXXFLAGS      = -pipe -O2 -Wall -W -D_REENTRANT -fPIC  $(DEFINES)
LEXFLAGS      = 
YACCFLAGS     = -d
INCPATH       = -I/usr/lib/qt4/mkspecs/linux-g++ -I. -I/usr/lib/qt4/include/QtCore -I/usr/lib/qt4/include/QtCore -I/usr/lib/qt4/include/QtNetwork -I/usr/lib/qt4/include/QtNetwork -I/usr/lib/qt4/include/QtGui -I/usr/lib/qt4/include/QtGui -I/usr/lib/qt4/include/QtXml -I/usr/lib/qt4/include/QtXml -I/usr/lib/qt4/include/Qt3Support -I/usr/lib/qt4/include/Qt3Support -I/usr/lib/qt4/include/QtSvg -I/usr/lib/qt4/include/QtSvg -I/usr/lib/qt4/include -I. -I$(QT4)/include -I$(QT4)/include/QtCore -I$(QT4)/include/QtGui -I$(QT4)/include/QtDesigner -I$(QT4)/include/QtNetwork -I$(QT4)/include/ActiveQt -I$(QT4)/include/Qt3Support -I. -I.
LINK          = g++
LFLAGS        = -Wl,-rpath,/usr/lib/qt4/lib -shared -Wl,-soname,libmezzoAnalyzer.so.1
LIBS          = $(SUBLIBS)  -L/usr/lib/qt4/lib -L../mezzo_lib/Debug -lmezzo_lib -L$(QT4)/lib -L/usr/lib -L/usr/X11R6/lib -lQtDesigner -lQtSvg -lQt3Support -lQtSql -lQtXml -lQtGui -lpng -lSM -lICE -lXi -lXrender -lXrandr -lXfixes -lXcursor -lXinerama -lfreetype -lfontconfig -lXext -lX11 -lQtNetwork -lQtCore -lz -lm -lglib-2.0 -ldl -lpthread
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/lib/qt4/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -sf
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = src/odcheckerdlg.cpp moc_odcheckerdlg.cpp
OBJECTS       = odcheckerdlg.o \
		moc_odcheckerdlg.o
DIST          = /usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/g++.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		mezzoAnalyzer.pro
QMAKE_TARGET  = mezzoAnalyzer
DESTDIR       = Debug/
TARGET        = libmezzoAnalyzer.so.1.0.0
TARGETA       = Debug/libmezzoAnalyzer.a
TARGETD       = libmezzoAnalyzer.so.1.0.0
TARGET0       = libmezzoAnalyzer.so
TARGET1       = libmezzoAnalyzer.so.1
TARGET2       = libmezzoAnalyzer.so.1.0

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile  Debug/$(TARGET)

Debug/$(TARGET): ui_odcheckdlg.h $(OBJECTS) $(SUBLIBS) $(OBJCOMP)  
	@$(CHK_DIR_EXISTS) Debug/ || $(MKDIR) Debug/ 
	-$(DEL_FILE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2)
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS) $(OBJCOMP)
	-ln -s $(TARGET) $(TARGET0)
	-ln -s $(TARGET) $(TARGET1)
	-ln -s $(TARGET) $(TARGET2)
	-$(DEL_FILE) Debug/$(TARGET)
	-$(DEL_FILE) Debug/$(TARGET0)
	-$(DEL_FILE) Debug/$(TARGET1)
	-$(DEL_FILE) Debug/$(TARGET2)
	-$(MOVE) $(TARGET) $(TARGET0) $(TARGET1) $(TARGET2) Debug/



staticlib: $(TARGETA)

$(TARGETA): ui_odcheckdlg.h $(OBJECTS) $(OBJCOMP) 
	-$(DEL_FILE) $(TARGETA) 
	$(AR) $(TARGETA) $(OBJECTS)

Makefile: mezzoAnalyzer.pro  /usr/lib/qt4/mkspecs/linux-g++/qmake.conf /usr/lib/qt4/mkspecs/common/unix.conf \
		/usr/lib/qt4/mkspecs/common/g++.conf \
		/usr/lib/qt4/mkspecs/common/linux.conf \
		/usr/lib/qt4/mkspecs/qconfig.pri \
		/usr/lib/qt4/mkspecs/features/qt_functions.prf \
		/usr/lib/qt4/mkspecs/features/qt_config.prf \
		/usr/lib/qt4/mkspecs/features/exclusive_builds.prf \
		/usr/lib/qt4/mkspecs/features/default_pre.prf \
		/usr/lib/qt4/mkspecs/features/release.prf \
		/usr/lib/qt4/mkspecs/features/default_post.prf \
		/usr/lib/qt4/mkspecs/features/warn_on.prf \
		/usr/lib/qt4/mkspecs/features/qt.prf \
		/usr/lib/qt4/mkspecs/features/unix/thread.prf \
		/usr/lib/qt4/mkspecs/features/moc.prf \
		/usr/lib/qt4/mkspecs/features/resources.prf \
		/usr/lib/qt4/mkspecs/features/uic.prf \
		/usr/lib/qt4/lib/libQtCore.prl \
		/usr/lib/qt4/lib/libQtGui.prl \
		/usr/lib/qt4/lib/libQtNetwork.prl \
		/usr/lib/qt4/lib/libQt3Support.prl \
		/usr/lib/qt4/lib/libQtSql.prl \
		/usr/lib/qt4/lib/libQtXml.prl \
		/usr/lib/qt4/lib/libQtDesigner.prl \
		/usr/lib/qt4/lib/libQtSvg.prl
	$(QMAKE) -unix -o Makefile mezzoAnalyzer.pro
/usr/lib/qt4/mkspecs/common/unix.conf:
/usr/lib/qt4/mkspecs/common/g++.conf:
/usr/lib/qt4/mkspecs/common/linux.conf:
/usr/lib/qt4/mkspecs/qconfig.pri:
/usr/lib/qt4/mkspecs/features/qt_functions.prf:
/usr/lib/qt4/mkspecs/features/qt_config.prf:
/usr/lib/qt4/mkspecs/features/exclusive_builds.prf:
/usr/lib/qt4/mkspecs/features/default_pre.prf:
/usr/lib/qt4/mkspecs/features/release.prf:
/usr/lib/qt4/mkspecs/features/default_post.prf:
/usr/lib/qt4/mkspecs/features/warn_on.prf:
/usr/lib/qt4/mkspecs/features/qt.prf:
/usr/lib/qt4/mkspecs/features/unix/thread.prf:
/usr/lib/qt4/mkspecs/features/moc.prf:
/usr/lib/qt4/mkspecs/features/resources.prf:
/usr/lib/qt4/mkspecs/features/uic.prf:
/usr/lib/qt4/lib/libQtCore.prl:
/usr/lib/qt4/lib/libQtGui.prl:
/usr/lib/qt4/lib/libQtNetwork.prl:
/usr/lib/qt4/lib/libQt3Support.prl:
/usr/lib/qt4/lib/libQtSql.prl:
/usr/lib/qt4/lib/libQtXml.prl:
/usr/lib/qt4/lib/libQtDesigner.prl:
/usr/lib/qt4/lib/libQtSvg.prl:
qmake:  FORCE
	@$(QMAKE) -unix -o Makefile mezzoAnalyzer.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/mezzoAnalyzer1.0.0 || $(MKDIR) .tmp/mezzoAnalyzer1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/mezzoAnalyzer1.0.0/ && $(COPY_FILE) --parents src/odcheckerdlg.h .tmp/mezzoAnalyzer1.0.0/ && $(COPY_FILE) --parents src/odcheckerdlg.cpp .tmp/mezzoAnalyzer1.0.0/ && $(COPY_FILE) --parents ui/odcheckdlg.ui .tmp/mezzoAnalyzer1.0.0/ && (cd `dirname .tmp/mezzoAnalyzer1.0.0` && $(TAR) mezzoAnalyzer1.0.0.tar mezzoAnalyzer1.0.0 && $(COMPRESS) mezzoAnalyzer1.0.0.tar) && $(MOVE) `dirname .tmp/mezzoAnalyzer1.0.0`/mezzoAnalyzer1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/mezzoAnalyzer1.0.0


yaccclean:
lexclean:
clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Debug/$(TARGET0) Debug/$(TARGET1) Debug/$(TARGET2) $(TARGETA)
	-$(DEL_FILE) Makefile


/usr/lib/qt4/bin/moc:
	(cd $(QTDIR)/src/tools/moc && $(MAKE))

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_odcheckerdlg.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_odcheckerdlg.cpp
moc_odcheckerdlg.cpp: ui_odcheckdlg.h \
		src/odcheckerdlg.h \
		/usr/lib/qt4/bin/moc
	/usr/lib/qt4/bin/moc $(DEFINES) $(INCPATH) src/odcheckerdlg.h -o moc_odcheckerdlg.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_odcheckdlg.h
compiler_uic_clean:
	-$(DEL_FILE) ui_odcheckdlg.h
ui_odcheckdlg.h: ui/odcheckdlg.ui
	/usr/lib/qt4/bin/uic ui/odcheckdlg.ui -o ui_odcheckdlg.h

compiler_clean: compiler_moc_header_clean compiler_rcc_clean compiler_image_collection_clean compiler_moc_source_clean compiler_uic_clean 

####### Compile

odcheckerdlg.o: src/odcheckerdlg.cpp src/odcheckerdlg.h \
		ui_odcheckdlg.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o odcheckerdlg.o src/odcheckerdlg.cpp

moc_odcheckerdlg.o: moc_odcheckerdlg.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_odcheckerdlg.o moc_odcheckerdlg.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

