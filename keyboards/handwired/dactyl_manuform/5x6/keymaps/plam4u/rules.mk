# Automatically update the keymap visualization when compiling
.PHONY: %
%:
	keymapviz -k dactyl_manuform5x6 -t fancy -r keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymap.c -c keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymapviz.toml > /dev/null

TAP_DANCE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes

COMMAND_ENABLE = no
COMBO_ENABLE = no
CONSOLE_ENABLE = no

