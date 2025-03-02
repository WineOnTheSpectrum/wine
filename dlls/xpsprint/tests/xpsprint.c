/*
 * xpsprint test
 *
 * Copyright 2025 Damien Zammit
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

#define COBJMACROS
#define CONST_VTABLE

#include <wine/test.h>
#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

#include "windef.h"
#include "winbase.h"
#include "objbase.h"
#include "ocidl.h"

#include "xpsprint.h"

#ifdef __i386__
static const BOOL abi_supports_stdcall = TRUE;
#else
static const BOOL abi_supports_stdcall = FALSE;
#endif

static void test_StartXpsPrintJob(void)
{
    LPCWSTR printerName = L"printer";
    LPCWSTR jobName = L"printjob";
    LPCWSTR outputFileName = L"printjob.xps";
    HANDLE progressEvent = NULL;
    HANDLE completionEvent = NULL;
    UINT8 printablePages[3] = { 1, 2, 3 };
    UINT8 *printablePagesOn = &printablePages[0];
    UINT32 printablePagesOnCount = 3;

    HRESULT hr;

    hr = StartXpsPrintJob(printerName, jobName, outputFileName,
			  progressEvent, completionEvent,
			  printablePagesOn, printablePagesOnCount,
			  NULL, NULL, NULL);
    ok(hr == E_NOTIMPL, "Unexpected hr %#lx.\n", hr);
}

START_TEST(xpsprint)
{
    test_StartXpsPrintJob();
}
