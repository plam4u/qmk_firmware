#pragma once

#define USE_SERIAL
#define MASTER_LEFT

#define TAPPING_TERM 175
#define TAPPING_TOGGLE 2
#define TAPPING_FORCE_HOLD_PER_KEY

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define LEADER_PER_KEY_TIMING
#define LEADER_NO_TIMEOUT

#define COMBO_TERM 50

#define DYNAMIC_MACRO_NO_NESTING

#define MK_COMBINED
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 10
#define MOUSEKEY_INITIAL_SPEED 50
#define MK_C_OFFSET_UNMOD	12
#define MK_C_INTERVAL_UNMOD	16
#define MK_C_OFFSET_0	    16
#define MK_C_INTERVAL_0	    16
#define MK_C_OFFSET_1	    48
#define MK_C_INTERVAL_1	    16
#define MK_C_OFFSET_2	    96
#define MK_C_INTERVAL_2	    16
#define MK_W_OFFSET_UNMOD	1
#define MK_W_INTERVAL_UNMOD	40
#define MK_W_OFFSET_0	    1
#define MK_W_INTERVAL_0	    60
#define MK_W_OFFSET_1	    1
#define MK_W_INTERVAL_1	    40
#define MK_W_OFFSET_2	    1
#define MK_W_INTERVAL_2	    20

