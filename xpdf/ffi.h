//========================================================================
//
// pdftotext.cc
//
// Copyright 1997-2013 Glyph & Cog, LLC
//
//========================================================================

#include <aconf.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#ifdef DEBUG_FP_LINUX
#  include <fenv.h>
#  include <fpu_control.h>
#endif
#include "gmem.h"
#include "gmempp.h"
#include "parseargs.h"
#include "GString.h"
#include "GList.h"
#include "GlobalParams.h"
#include "Object.h"
#include "Stream.h"
#include "Array.h"
#include "Dict.h"
#include "XRef.h"
#include "Catalog.h"
#include "Page.h"
#include "PDFDoc.h"
#include "TextOutputDev.h"
#include "CharTypes.h"
#include "UnicodeMap.h"
#include "TextString.h"
#include "Error.h"
#include "config.h"

static int firstPage = 1;
static int lastPage = 0;
static GBool physLayout = gFalse;
static GBool simpleLayout = gFalse;
static GBool simple2Layout = gFalse;
static GBool tableLayout = gFalse;
static GBool linePrinter = gFalse;
static GBool rawOrder = gFalse;
static double fixedPitch = 0;
static double fixedLineSpacing = 0;
static GBool clipText = gFalse;
static GBool discardDiag = gFalse;
static char textEncName[128] = "";
static char textEOL[16] = "";
static GBool noPageBreaks = gFalse;
static GBool insertBOM = gFalse;
static double marginLeft = 0;
static double marginRight = 0;
static double marginTop = 0;
static double marginBottom = 0;
static char ownerPassword[33] = "\001";
static char userPassword[33] = "\001";
static GBool verbose = gFalse;
static GBool quiet = gFalse;
static char cfgFileName[256] = "";
static GBool listEncodings = gFalse;
static GBool printVersion = gFalse;
static GBool printHelp = gFalse;

#ifdef __cplusplus
extern "C" {
#endif

// Use platform-specific export macro
#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT __attribute__((visibility("default")))
#endif

// Your wrapper functions
EXPORT const char* pdftotext(char* pdfPath);

#ifdef __cplusplus
}
#endif

