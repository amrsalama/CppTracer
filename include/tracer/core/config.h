#ifndef INCLUDE_TRACER_CORE_CONFIG_H_
#define INCLUDE_TRACER_CORE_CONFIG_H_

// Copyright © 2016.
// Contributors to this file are:
//    Amr Salama <amr.mo.salama@gmail.com>,
//    ...
//
// General project configuration file,
// defines OS type, compiler type, ...
// to be used with system-specific code needs conditional includes.

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) || defined(__WIN32__) || defined(_WIN64) || defined(__WINDOWS__) || defined(__TOS_WIN__)
#define OS_WINDOWS
#endif

#endif  // INCLUDE_TRACER_CORE_CONFIG_H_
