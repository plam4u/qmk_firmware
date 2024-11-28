/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define USE_SERIAL
#define MASTER_LEFT

#define TAPPING_TERM 200
#define COMBO_TERM 50
#define DYNAMIC_MACRO_NO_NESTING // No recursion
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

#define MK_KINETIC_SPEED
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA	10 // 25 // Step size for accelerating from initial to base speed
#define MOUSEKEY_INITIAL_SPEED 50 // 100 // Initial speed of the cursor in pixel per second

#define MK_C_OFFSET_UNMOD	4
#define MK_C_INTERVAL_UNMOD	16
#define MK_C_OFFSET_0	    12
#define MK_C_INTERVAL_0	    16
#define MK_C_OFFSET_1	    32
#define MK_C_INTERVAL_1	    16
#define MK_C_OFFSET_2	    64
#define MK_C_INTERVAL_2	    16

#define MK_W_OFFSET_UNMOD	1
#define MK_W_INTERVAL_UNMOD	40
#define MK_W_OFFSET_0	    1
#define MK_W_INTERVAL_0	    360
#define MK_W_OFFSET_1	    1
#define MK_W_INTERVAL_1	    120
#define MK_W_OFFSET_2	    1
#define MK_W_INTERVAL_2	    20

