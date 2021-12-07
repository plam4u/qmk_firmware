# Automatically update the keymap visualization when compiling
.PHONY: %
%:
	keymapviz -k dactyl_manuform5x6 -t fancy -r keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymap.c -c keyboards/handwired/dactyl_manuform/5x6/keymaps/plam4u/keymapviz.toml > /dev/null

COMBO_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE = yes
DYNAMIC_MACRO_ENABLE = yes
TAP_DANCE_ENABLE = yes

