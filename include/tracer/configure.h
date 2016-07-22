#ifndef INCLUDE_TRACER_CONFIGURE_H_
#define INCLUDE_TRACER_CONFIGURE_H_

#if defined(__WIN32__)
    || defined(_WIN32)
    || defined(WIN32)
    || defined(_WIN64)
    || defined(__WINDOWS__)
    || defined(__TOS_WIN__)
#define OS_WINDOWS
#endif

#endif  // INCLUDE_TRACER_CONFIGURE_H_
