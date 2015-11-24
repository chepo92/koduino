/**
 * @authors Avik De <avikde@gmail.com>

  This file is part of koduino <https://github.com/avikde/koduino>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation, either
  version 3 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, see <http://www.gnu.org/licenses/>.
 */
#ifndef DxlNode_h
#define DxlNode_h

#include <Arduino.h>

class DxlNode {
public:
  // members
  const uint8_t DE, myAddress;
  USARTClass& Ser;
  const bool isMaster;
  
  // incoming packet
  uint8_t packet[32];

  // functions
  DxlNode(uint8_t rts, USARTClass& ser, uint8_t myAddress) : DE(rts), myAddress(myAddress), Ser(ser), isMaster(false) {}
  DxlNode(uint8_t rts, USARTClass& ser) : DE(rts), myAddress(0), Ser(ser), isMaster(true) {}


  void init();
  // instErr can be instruction (instruction packet) or error code (status packet)
  // params is of length N
  void sendPacket(uint8_t id, uint8_t instErr, uint8_t N, uint8_t *params);

  // Update function that should be called as often as possible
  bool listen();
  bool checkPacket();


protected:
  void setTX();
  void setRX();
  uint8_t writeByte(uint8_t c);
};


#endif