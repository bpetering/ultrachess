#ifndef MACROS_H
#define MACROS_H


#define digit_to_int(c) (c - 0x30)

#define int_to_digit(n) (n + 0x30)

#define is_file(c) (c >= 'a' && c <= 'h')

#define is_rank(c) (c >= '1' && c <= '8')

#define is_piece(c) (c == 'K' || c == 'Q' || c == 'R' || c == 'B' || c == 'N')

#define is_capture(c) (c == 'x' || c == ':')

#define is_check(c) (c == '+')

#endif
