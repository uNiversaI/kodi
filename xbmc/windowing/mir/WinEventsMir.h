#pragma once

#ifndef WINDOW_SYSTEM_EVENTS_MIR_H_
#define WINDOW_SYSTEM_EVENTS_MIR_H_

#include <mir_toolkit/mir_client_library.h>

#include "../WinEvents.h"
#include <queue>

extern void MirHandleEvent(MirSurface* surface, MirEvent const* ev, void* context);

class CWinEventsMir : public IWinEvents
{
public:
  virtual ~CWinEventsMir() {};
  bool MessagePump() override;
  size_t GetQueueSize() override;
  void  MessagePush(XBMC_Event* ev);

private:
  std::queue<XBMC_Event> events;
};

#endif // WINDOW_SYSTEM_EVENTS_MIR_H_
