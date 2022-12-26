#!/usr/bin/env bash
qmk compile -kb splitkb/kyria/rev1 -km alf_dpx

make splitkb/kyria/rev2:alf_dpx:dfu-split-left