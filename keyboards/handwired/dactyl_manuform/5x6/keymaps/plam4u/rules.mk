# Automatically update the keymap visualization when compiling
# .PHONY: %
# %:
# 	keymapviz -k dactyl_manuform5x6 -t fancy -r keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymap.c -c keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymapviz.toml > /dev/null

# Enabled

DYNAMIC_MACRO_ENABLE = yes
LEADER_ENABLE = yes
MOUSEKEY_ENABLE = yes
PROGRAMMABLE_BUTTON_ENABLE = yes
SEND_STRING_ENABLE = yes
TAP_DANCE_ENABLE = yes

# Disabled

COMBO_ENABLE = no
