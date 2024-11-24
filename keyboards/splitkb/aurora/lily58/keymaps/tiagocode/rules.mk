# Copyright 2022 splitkb.com <support@splitkb.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

OLED_ENABLE = yes

BOOTLOADER = caterina
# Tap a key and you get its character. Tap a key, but hold it slightly longer and you get its shifted state
AUTO_SHIFT_ENABLE = yes
# Enables Link Time Optimization (LTO) when compiling the keyboard
LTO_ENABLE = yes
# Enables the words per minute (WPM) counter
ENCODER_ENABLE = no
# Enables tap dance
TAP_DANCE_ENABLE = no