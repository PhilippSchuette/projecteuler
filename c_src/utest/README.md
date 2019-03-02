# UTest

## Overview
`utest.c` implements a simple unit testing framework in `C`. The code is fairly well documented and bug fixes and improvements are welcome. Currently, assertions for `long`, `long *` equality and inequality are supported. A `boolean` type and a corresponding assertion are defined, too.

## Potentially Useful
Support of `double` would be useful. `structs` could be asserted via a user-provided comparison function. The source code is quite repetitive at times and a `FIXME` in `utest.c` describes a way to remove some of the boilerplate code to improve this.
