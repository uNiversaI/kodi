SRCS=WinSystemMir.cpp \
     WinSystemMirGLESContext.cpp \
     WinSystemMirGLContext.cpp \
     WinEventsMir.cpp \
     GLContextEGL.cpp \

LIB=windowing_MIR.a

include ../../../Makefile.include
-include $(patsubst %.cpp,%.P,$(patsubst %.c,%.P,$(SRCS)))
