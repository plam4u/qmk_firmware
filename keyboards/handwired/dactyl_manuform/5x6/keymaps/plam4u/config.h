#pragma once

#define USE_SERIAL
#define MASTER_LEFT

#define TAPPING_TERM 200
#define COMBO_TERM 50
#define DYNAMIC_MACRO_NO_NESTING // No recursion

// #define TAPPING_FORCE_HOLD
// #define IGNORE_MOD_TAP_INTERRUPT
// #define PERMISSIVE_HOLD
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

// #define MOUSEKEY_DELAY 300 // Delay between pressing a movement key and cursor movement
// #define MOUSEKEY_INTERVAL 50 // Time between cursor movements in milliseconds
// #define MOUSEKEY_MOVE_DELTA 5 // Step size
// #define MOUSEKEY_MAX_SPEED 10 // Maximum cursor speed at which acceleration stops
// #define MOUSEKEY_TIME_TO_MAX 20 // Time until maximum cursor speed is reached
// #define MOUSEKEY_WHEEL_DELAY 300 // Delay between pressing a wheel key and wheel movement
// #define MOUSEKEY_WHEEL_INTERVAL 100 // Time between wheel movements
// #define MOUSEKEY_WHEEL_MAX_SPEED 8 // Maximum number of scroll steps per scroll action
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 40 // Time until maximum scroll speed is reached

#define MK_KINETIC_SPEED // undefined	Enable kinetic mode
// #define MOUSEKEY_DELAY 16 // Delay between pressing a movement key and cursor movement
// MOUSEKEY_INTERVAL 8 // Time between cursor movements in milliseconds
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA	10 // 25 // Step size for accelerating from initial to base speed
#define MOUSEKEY_INITIAL_SPEED 50 // 100 // Initial speed of the cursor in pixel per second
// MOUSEKEY_BASE_SPEED 1000 // Maximum cursor speed at which acceleration stops
// MOUSEKEY_DECELERATED_SPEED 400 // Decelerated cursor speed
// MOUSEKEY_ACCELERATED_SPEED 3000 // Accelerated cursor speed
// MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 16 // Initial number of movements of the mouse wheel
// MOUSEKEY_WHEEL_BASE_MOVEMENTS 32 // Maximum number of movements at which acceleration stops
// MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 48 // Accelerated wheel movements
// MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8 // Decelerated wheel movements

// Mouse Keys: Constant mode
// #define MK_3_SPEED
// #define MK_MOMENTARY_ACCEL

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

