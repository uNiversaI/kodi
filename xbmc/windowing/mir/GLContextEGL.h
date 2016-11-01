#pragma once

#include <mir_toolkit/mir_client_library.h>
#include "EGL/egl.h"

class CGLContextEGL
{
public:
  CGLContextEGL();
  virtual ~CGLContextEGL();

  bool CreateDisplay(MirConnection* connection,
                     EGLint renderable_type,
                     EGLint rendering_api);

  bool CreateSurface(MirSurface* surface);
  bool CreateContext();
  void Destroy();
  void Detach();
  void SetVSync(bool enable);
  void SwapBuffers();
  void QueryExtensions();

  //bool IsExtSupported(const char* extension) const;

  EGLDisplay m_eglDisplay;
  EGLSurface m_eglSurface;
  EGLContext m_eglContext;
  EGLConfig m_eglConfig;

  //std::string m_extPrefix;
  //std::string m_extensions;
};
