/*
  Copyright (C) 2014 Alik <aliktab@gmail.com> 

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __COLORLED__
#define __COLORLED__

#include <inttypes.h>
#include <limits.h>


#define C565TO888(c) (((c << 8) & 0xf80000) | ((c << 5) & 0x00fc00) | ((c << 3) & 0x0000f8))
#define C888(r, g, b) (((r << 16) & 0xff0000) | ((g << 8) & 0x00ff00) | ((b) & 0x0000ff))


class ColorLED
{
public:

  ColorLED(uint8_t _l, uint8_t _r, uint8_t _g, uint8_t _b) 
    : L(_l), R(_r), G(_g), B(_b) {}

  void set_L(uint8_t _l) { L = _l; }
  void set_C(uint8_t _r, uint8_t _g, uint8_t _b) { R = _r; G = _g; B = _b; }

  uint8_t get_L() const { return L; }
  uint8_t get_R() const { return R; }
  uint8_t get_G() const { return G; }
  uint8_t get_B() const { return B; }

  uint16_t get_R_PWM_16() const { return L * R; }
  uint16_t get_G_PWM_16() const { return L * G; }
  uint16_t get_B_PWM_16() const { return L * B; }

  ColorLED operator +(const ColorLED & _value) { }

private:

  uint8_t L;
  uint8_t R;
  uint8_t G;
  uint8_t B;
};

#endif // __COLORLED__
