#include "wlcjs.h"

namespace wlcjs {

#define CASE(E, T) case E: return T;

#define ENUM_TEXT(TYPE, ...) \
  const char* enum_to_string(enum wlc_ ## TYPE type) {\
    switch (type) {\
      __VA_ARGS__\
      default: return "unknown";\
    }\
  }

ENUM_TEXT(log_type,
  CASE(WLC_LOG_INFO, "info")
  CASE(WLC_LOG_WARN, "warn")
  CASE(WLC_LOG_ERROR, "error")
  CASE(WLC_LOG_WAYLAND, "wayland")
);

ENUM_TEXT(backend_type,
  CASE(WLC_BACKEND_NONE, "none")
  CASE(WLC_BACKEND_DRM, "drm")
  CASE(WLC_BACKEND_X11, "x11")
);

}