# Welcome to my fork of [raylib v4.2.0](https://github.com/raysan5/raylib/releases/tag/4.2.0)
this fork of raylib (with raylib-cpp) focuses on overall compatibility, repositiory size, and adding some much needed quality of life functions.

# FAQ
## Why v4.2.0?
this is currently the latest version of raylib that supports [raylib-cpp](https://github.com/RobLoach/raylib-cpp), 
some functions were changed and raylib-cpp has yet to update. also not much has changed between master and v4.2.0.

## Why does repositiory size matter?
i've been downloading and changing versions of raylib too much and the wait between builds has become unbearable.

## What did you remove?
- [examples folder](https://github.com/raysan5/raylib/tree/master/examples)
- documentation markdown files (e.g. CHANGELOG, HISTORY.md, ROADMAP.md)
- [raylib parser output](https://github.com/raysan5/raylib/tree/master/parser/output)
- unused images as a result of the cleanup

in total the repository shrank by ~10 MB.

## What OS compatability problems does raylib have?
raylib cannot compile on windows if windows.h is included because of naming conflicts. you might have encountered something like this if you have tried:

```
raylib.h:237:3: error: redefinition of 'RayRectangle' as different kind of symbol
} RayRectangle;
  ^
C:\Program Files (x86)\Windows Kits\10\\include\10.0.22000.0\\um\wingdi.h:4561:24: note: previous definition is here
WINGDIAPI BOOL WINAPI RayRectangle(_In_ HDC hdc, _In_ int left, _In_ int top, _In_ int right, _In_ int bottom);
```

this was a problem for me because a library I was using required it.

## What changes were made to counter this?
a few structs/functions were renamed. (Usually prefixed by 'Ray')

e.g.
- Rectangle -> RayRectangle
- DrawText -> RayDrawText
- CloseWindow -> RayCloseWindow
- LoadImage -> RayLoadImage
- ShowCursor -> RayShowCursor
- PlaySound -> RayPlaySound

also some [under the hood changes](https://github.com/raysan5/raylib/issues/1217#issuecomment-1219728255) to the rmath module

## How do I use this without documentation?
most of the raylib (and raylib-cpp) documentation is the same, just replace the old name with the new name.
for an example look at [my game](https://github.com/mgurga/quadrabeat) which uses this library.

## Can I add functions that were denied from official raylib??>
OF COURSE! as long as it's not too destructive.
