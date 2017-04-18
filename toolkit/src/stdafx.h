// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

// First we need to know which system we are on.
// I don't know all of the common defines used and I can only test windows - Matt
#ifdef _WIN32
#define PT_WINDOWS
#endif // _WIN32

#ifdef PT_WINDOWS
#if ! defined(WIN32_LEAN_AND_MEAN)
#define WIN32_LEAN_AND_MEAN
#endif
#include <Windows.h>
#include "targetver.h"
#endif // PT_WINDOWS

#include <iostream>
#include <tchar.h>
#include <string>
#include <vector>
#include <memory>
#include <thread>
#include <chrono>
#include <mutex>

//#include <apathy.hpp>
//#include <brotli\decode.h>

#include "FileLoader.h"

#include "Scripting.h"