/**
 * EXAMPLEpredefines.h - pcannonProjectStandards
 * Predefines for C and C++ projects
 * STD Information: 20250723 - 1.0S
 */

#pragma once

// Project setup
#define EXAMPLE_DEFAULT_CPP_STD			201103L

// Versioning
#define EXAMPLE_VERSION_MAJOR            0
#define EXAMPLE_VERSION_MINOR            0
#define EXAMPLE_VERSION_PATCH            0

#define EXAMPLE_VERSION_STD              0

// Version states:
// * dev
// * beta
// * build
#define EXAMPLE_VERSION_STATE          "dev"

#define EXAMPLE_VERSION                ((EXAMPLE_VERSION_MAJOR<<16)|(FDX_VERSION_MINOR<<8)|(FDX_VERSION_PATCH)|(FDX_VERSION_STATE << 24))

#define EXAMPLE_VERSION_CHECK(EXAMPLE_VERSION_MAJOR, FDX_VERSION_MINOR, FDX_VERSION_PATCH, FDX_VERSION_STATE) \
    (((EXAMPLE_VERSION_MAJOR)<<16)|((EXAMPLE_VERSION_MINOR)<<8)|(FDX_VERSION_PATCH)|((FDX_VERSION_STATE) << 24))

// Macro utils
#define EXAMPLE_STRINGIFY(x) #x
#define EXAMPLE_TOSTRING(x) EXAMPLE_STRINGIFY(x)

#ifndef EXAMPLE_DEV
#   define EXAMPLE_DEV true
#endif

#ifdef WIN32
#	define EXAMPLE_OS_WIN32
#elif defined(__APPLE__) || defined(__MACH__) || defined(Macintosh)
#	define EXAMPLE_OS_MACOS
#elif defined(__linux__) || defined(__unix) || defined(__unix__)
#	define EXAMPLE_OS_UNIX_LINUX
#elif defined(__FreeBSD__)
#	define EXAMPLE_OS_FREEBSD
#else
#	error "Current platform is not supported"
#endif // defined(WIN32) // Platform check

