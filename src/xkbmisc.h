/*
Copyright 2009  Dan Nicholson

Permission is hereby granted, free of charge, to any person obtaining a
copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the names of the authors or their
institutions shall not be used in advertising or otherwise to promote the
sale, use or other dealings in this Software without prior written
authorization from the authors.
*/

#ifndef _XKBMISC_H_
#define _XKBMISC_H_

#include <X11/X.h>
#include <X11/Xdefs.h>
#include <X11/extensions/XKBstrcommon.h>
#include <X11/extensions/XKBrulescommon.h>
#include "X11/extensions/XKBcommon.h"

extern char *
XkbcKeysymToString(KeySym ks);

extern KeySym
XkbcStringToKeysym(const char *s);

/***====================================================================***/

extern Bool
XkbcComputeEffectiveMap(XkbcDescPtr xkb, XkbKeyTypePtr type,
                        unsigned char *map_rtrn);

/***====================================================================***/

extern int
XkbcInitCanonicalKeyTypes(XkbcDescPtr xkb, unsigned which, int keypadVMod);

extern Bool
XkbcVirtualModsToReal(XkbcDescPtr xkb, unsigned virtual_mask,
                      unsigned *mask_rtrn);

extern void
XkbcEnsureSafeMapName(char *name);

extern unsigned
_XkbcKSCheckCase(KeySym sym);

#define XkbcKSIsLower(k) (_XkbcKSCheckCase(k) & _XkbKSLower)
#define XkbcKSIsUpper(k) (_XkbcKSCheckCase(k) & _XkbKSUpper)

extern Bool
XkbcNameMatchesPattern(char *name, char *ptrn);

/***====================================================================***/

extern char *
XkbcAtomGetString(Atom atom);

extern Atom
XkbcInternAtom(char *name, Bool onlyIfExists);

/***====================================================================***/

extern char *
XkbcAtomText(Atom atm);

extern char *
XkbcVModIndexText(XkbcDescPtr xkb, unsigned ndx);

extern char *
XkbcVModMaskText(XkbcDescPtr xkb, unsigned modMask, unsigned mask);

extern char *
XkbcModIndexText(unsigned ndx);

extern char *
XkbcModMaskText(unsigned mask, Bool cFormat);

extern char *
XkbcConfigText(unsigned config);

extern char *
XkbcGeomFPText(int val);

extern char *
XkbcActionTypeText(unsigned type);

extern char *
XkbcKeysymText(KeySym sym);

extern char *
XkbcKeyNameText(char *name);

extern char *
XkbcSIMatchText(unsigned type);

#endif /* _XKBMISC_H_ */
