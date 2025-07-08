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

#define EXAMPLE_VERSION                ((FDX_VERSION_MAJOR<<16)|(FDX_VERSION_MINOR<<8)|(FDX_VERSION_PATCH)|(FDX_VERSION_STATE << 24))

#define EXAMPLE_VERSION_CHECK(FDX_VERSION_MAJOR, FDX_VERSION_MINOR, FDX_VERSION_PATCH, FDX_VERSION_STATE) \
    (((EXAMPLE_VERSION_MAJOR)<<16)|((FDX_VERSION_MINOR)<<8)|(FDX_VERSION_PATCH)|((FDX_VERSION_STATE) << 24))

// Macro utils
#define EXAMPLE_STRINGIFY(x) #x
#define EXAMPLE_TOSTRING(x) FDX_STRINGIFY(x)

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

#if EXAMPLE_DEV
#	include <iostream>
#	define EXAMPLE_Debug(_type, _msg) std::cout << "[ FINDX MESSAGE: " + std::string(_type) + " ] " + std::string(_msg) + "\n";
#else
#	define EXAMPLE_Debug(_type, _msg)
#endif

