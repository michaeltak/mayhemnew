/*
 * Copyright (C) 2015 Jared Boone, ShareBrained Technology, Inc.
 * Copyright (C) 2017 Furrtek
 *
 * This file is part of PortaPack.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#include "tone_key.hpp"
#include "string_format.hpp"

namespace tonekey {
	
const tone_key_t tone_keys[] = {
	{ "0 XZ", 67.000 },
	{ "1 WZ", 69.400 },
	{ "2 XA", 71.900 },
	{ "3 WA", 74.400 },
	{ "4 XB", 77.000 },
	{ "5 WB", 79.700 },
	{ "6 YZ", 82.500 },
	{ "7 YA", 85.400 },
	{ "8 YB", 88.500 },
	{ "9 ZZ", 91.500 },
	{ "10 ZA", 94.800 },
	{ "11 1ZB", 97.400 },
	{ "12 21Z", 100.000 },
	{ "13 1A", 103.500 },
	{ "14 1B", 107.200 },
	{ "15 2Z", 110.900 },
	{ "16 2Z", 114.800 },
	{ "17 2B", 118.800 },
	{ "18 3Z", 123.000 },
	{ "19 3A", 127.300 },
	{ "20 3B", 131.800 },
	{ "21 4Z", 136.500 },
	{ "22 4A", 141.300 },
	{ "23 4B", 146.200 },
	{ "24 5Z", 151.400 },
	{ "25 5A", 156.700 },
	{ "40 --", 159.800 },
	{ "26 5B", 162.200 },
	{ "41 --", 165.500 },
	{ "27 6Z", 167.900 },
	{ "42 --", 171.300 },
	{ "28 6A", 173.800 },
	{ "43 --", 177.300 },
	{ "29 6B", 179.900 },
	{ "44 --", 183.500 },
	{ "30 7Z", 186.200 },
	{ "45 --", 189.900 },
	{ "31 7A", 192.800 },
	{ "46 --", 196.600 },
	{ "47 --", 199.500 },
	{ "32 M1", 203.500 },
	{ "48 8Z", 206.500 },
	{ "33 M2", 210.700 },
	{ "34 M3", 218.100 },
	{ "35 M4", 225.700 },
	{ "49 9Z", 229.100 },
	{ "36 --", 233.600 },
	{ "37 --", 241.800 },
	{ "38 --", 250.300 },
	{ "50 0Z", 254.100 },
	{ "Axient 28kHz", 28000.0 },
	{ "Sennheiser 32.768k", 32768.0 },
	{ "Sennheiser 32kHz", 32000.0 },
	{ "Shure 19kHz", 19000.0 }
};

void tone_keys_populate(OptionsField& field) {
	using option_t = std::pair<std::string, int32_t>;
	using options_t = std::vector<option_t>;
	options_t tone_key_options;
	std::string tone_name;
	
	tone_key_options.emplace_back(std::make_pair("None", 0));
	for (size_t c = 0; c < KEY_TONES_NB; c++) {
		if (c < 50)
			tone_name = "CTCSS " + tone_keys[c].first;
		else
			tone_name = tone_keys[c].first;
		tone_key_options.emplace_back(tone_name, c);
	}
	field.set_options(tone_key_options);
}

}
