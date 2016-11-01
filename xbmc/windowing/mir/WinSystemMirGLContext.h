#pragma once

#ifndef WINDOW_SYSTEM_MIR_GL_CONTEXT_H_
#define WINDOW_SYSTEM_MIR_GL_CONTEXT_H_

#include "WinSystemMir.h"
#include "GLContextEGL.h"
#include "rendering/gl/RenderSystemGL.h"
#include "utils/GlobalsHandling.h"

class CWinSystemMirGLContext : public CWinSystemMir, public CRenderSystemGL
{
public:
  CWinSystemMirGLContext() = default;
  virtual ~CWinSystemMirGLContext() = default;

  bool CreateNewWindow(const std::string& name,
                       bool fullScreen,
                       RESOLUTION_INFO& res,
                       PHANDLE_EVENT_FUNC userFunction) override;

  bool SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays) override;
  bool IsExtSupported(const char* extension) override;

protected:
  void SetVSyncImpl(bool enable) override;
  void PresentRenderImpl(bool rendered) override;

private:
  CGLContextEGL m_pGLContext;

};

#if defined(HAS_GL)
XBMC_GLOBAL_REF(CWinSystemMirGLContext, g_Windowing);
#define g_Windowing XBMC_GLOBAL_USE(CWinSystemMirGLContext)
#endif

#endif // WINDOW_SYSTEM_MIR_GL_CONTEXT_H_
