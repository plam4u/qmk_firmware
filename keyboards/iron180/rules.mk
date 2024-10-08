# MCU name
MCU = STM32F072

# Bootloader selection
BOOTLOADER = stm32-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes       # Enable keyboard backlight functionality
BACKLIGHT_DRIVER = pwm
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
ENCODER_ENABLE = no

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
