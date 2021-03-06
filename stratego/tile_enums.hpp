#pragma once

enum class Type : uint8_t  {
        EMPTY = 0x00,
        MARSHAL = 0x01,
        GENERAL = 0x02,
        COLONEL = 0x03,
        MAJOR = 0x04,
        CAPTAIN = 0x05,
        LIEUTENANT = 0x06,
        SERGEANT = 0x07,
        SAPPER = 0x08,
        SCOUT = 0x09,
        SPY = 0x0A,
        BOMB = 0x0B,
        FLAG = 0x0C,
        IMPASSABLE = 0x0D
};

enum class Color : uint8_t {
        NONE = 0x00,
        BLUE = 0x01,
        RED = 0x02
};

enum class Button : uint8_t {
    NONE = 0x00,
    DONE_PLACING = 0x19
};
