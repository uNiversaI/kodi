#include "WinSystemMirGLESContext.h"

#if defined(HAS_GLES)

bool CWinSystemMirGLESContext::CreateNewWindow(const std::string& name,
                                               bool fullScreen,
                                               RESOLUTION_INFO& res,
                                               PHANDLE_EVENT_FUNC userFunction)
{
  if (!m_pGLContext.CreateDisplay(m_connection,
                                  EGL_OPENGL_ES2_BIT,
                                  EGL_OPENGL_ES_API))
  {
    return false;
  }

  m_pixel_format = mir_connection_get_egl_pixel_format(m_connection,
                                                       m_pGLContext.m_eglDisplay,
                                                       m_pGLContext.m_eglConfig);

  CWinSystemMir::CreateNewWindow(name, fullScreen, res, userFunction);

  if (!m_pGLContext.CreateSurface(m_surface))
  {
    return false;
  }

  if (!m_pGLContext.CreateContext())
  {
    return false;
  }

  return SetFullScreen(fullScreen, res, false);
}

bool CWinSystemMirGLESContext::SetFullScreen(bool fullScreen, RESOLUTION_INFO& res, bool blankOtherDisplays)
{
  auto ret = CWinSystemMir::SetFullScreen(fullScreen, res, blankOtherDisplays);

  if (ret)
  {
    return CRenderSystemGLES::ResetRenderSystem(res.iWidth, res.iHeight, fullScreen, 0);
  }

  return ret;
}

void CWinSystemMirGLESContext::SetVSyncImpl(bool enable)
{
  m_pGLContext.SetVSync(enable);
}

void CWinSystemMirGLESContext::PresentRenderImpl(bool rendered)
{
  if (rendered)
  {
    m_pGLContext.SwapBuffers();
  }
}

// FIXME Implement
bool CWinSystemMirGLESContext::IsExtSupported(const char* extension)
{
  return false;
}

#endif
