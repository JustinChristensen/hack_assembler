/* C code produced by gperf version 3.0.3 */
/* Command-line: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/gperf in/gen_comp  */
/* Computed positions: -k'1-3' */

#if !((' ' == 32) && ('!' == 33) && ('"' == 34) && ('#' == 35) \
      && ('%' == 37) && ('&' == 38) && ('\'' == 39) && ('(' == 40) \
      && (')' == 41) && ('*' == 42) && ('+' == 43) && (',' == 44) \
      && ('-' == 45) && ('.' == 46) && ('/' == 47) && ('0' == 48) \
      && ('1' == 49) && ('2' == 50) && ('3' == 51) && ('4' == 52) \
      && ('5' == 53) && ('6' == 54) && ('7' == 55) && ('8' == 56) \
      && ('9' == 57) && (':' == 58) && (';' == 59) && ('<' == 60) \
      && ('=' == 61) && ('>' == 62) && ('?' == 63) && ('A' == 65) \
      && ('B' == 66) && ('C' == 67) && ('D' == 68) && ('E' == 69) \
      && ('F' == 70) && ('G' == 71) && ('H' == 72) && ('I' == 73) \
      && ('J' == 74) && ('K' == 75) && ('L' == 76) && ('M' == 77) \
      && ('N' == 78) && ('O' == 79) && ('P' == 80) && ('Q' == 81) \
      && ('R' == 82) && ('S' == 83) && ('T' == 84) && ('U' == 85) \
      && ('V' == 86) && ('W' == 87) && ('X' == 88) && ('Y' == 89) \
      && ('Z' == 90) && ('[' == 91) && ('\\' == 92) && (']' == 93) \
      && ('^' == 94) && ('_' == 95) && ('a' == 97) && ('b' == 98) \
      && ('c' == 99) && ('d' == 100) && ('e' == 101) && ('f' == 102) \
      && ('g' == 103) && ('h' == 104) && ('i' == 105) && ('j' == 106) \
      && ('k' == 107) && ('l' == 108) && ('m' == 109) && ('n' == 110) \
      && ('o' == 111) && ('p' == 112) && ('q' == 113) && ('r' == 114) \
      && ('s' == 115) && ('t' == 116) && ('u' == 117) && ('v' == 118) \
      && ('w' == 119) && ('x' == 120) && ('y' == 121) && ('z' == 122) \
      && ('{' == 123) && ('|' == 124) && ('}' == 125) && ('~' == 126))
/* The character set is not based on ISO-646.  */
error "gperf generated tables don't work with this execution character set. Please report a bug to <bug-gnu-gperf@gnu.org>."
#endif

#line 10 "in/gen_comp"

#include "../types/_cg_inst.h"
#include <string.h>
/* maximum key range = 63, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
static unsigned int
comp_hash (str, len)
     register const char *str;
     register unsigned int len;
{
  static const unsigned char asso_values[] =
    {
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 15, 64, 64, 64, 64,  3, 64,
      64, 64, 64, 15, 64,  0, 64, 64, 25, 30,
       0, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64,  5, 25, 64, 10, 13,
      64, 64, 64, 64, 64, 64, 64,  0, 20, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 25, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64, 64, 64, 64,
      64, 64, 64, 64, 64, 64, 64
    };
  register unsigned int hval = len;

  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]+1];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval;
}

const struct cg_inst *
lookup_comp (str, len)
     register const char *str;
     register unsigned int len;
{
  enum
    {
      TOTAL_KEYWORDS = 28,
      MIN_WORD_LENGTH = 1,
      MAX_WORD_LENGTH = 3,
      MIN_HASH_VALUE = 1,
      MAX_HASH_VALUE = 63
    };

  static const struct cg_inst wordlist[] =
    {
#line 34 "in/gen_comp"
      {"M",      0x70},
#line 36 "in/gen_comp"
      {"-M",     0x73},
#line 38 "in/gen_comp"
      {"M-1",    0x72},
#line 20 "in/gen_comp"
      {"A",      0x30},
#line 24 "in/gen_comp"
      {"-A",     0x33},
#line 28 "in/gen_comp"
      {"A-1",    0x32},
#line 19 "in/gen_comp"
      {"D",      0xc},
#line 23 "in/gen_comp"
      {"-D",     0xf},
#line 27 "in/gen_comp"
      {"D-1",    0xe},
#line 41 "in/gen_comp"
      {"M-D",    0x47},
#line 35 "in/gen_comp"
      {"!M",     0x71},
#line 37 "in/gen_comp"
      {"M+1",    0x77},
#line 31 "in/gen_comp"
      {"A-D",    0x7},
#line 22 "in/gen_comp"
      {"!A",     0x31},
#line 26 "in/gen_comp"
      {"A+1",    0x37},
#line 16 "in/gen_comp"
      {"0",      0x2a},
#line 21 "in/gen_comp"
      {"!D",     0xd},
#line 25 "in/gen_comp"
      {"D+1",    0x1f},
#line 17 "in/gen_comp"
      {"1",      0x3f},
#line 18 "in/gen_comp"
      {"-1",     0x3a},
#line 40 "in/gen_comp"
      {"D-M",    0x53},
#line 42 "in/gen_comp"
      {"D&M",    0x40},
#line 30 "in/gen_comp"
      {"D-A",    0x13},
#line 32 "in/gen_comp"
      {"D&A",    0x0},
#line 39 "in/gen_comp"
      {"D+M",    0x42},
#line 29 "in/gen_comp"
      {"D+A",    0x2},
#line 43 "in/gen_comp"
      {"D|M",    0x55},
#line 33 "in/gen_comp"
      {"D|A",    0x15}
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      unsigned int key = comp_hash (str, len);

      if (key <= MAX_HASH_VALUE && key >= MIN_HASH_VALUE)
        {
          register const struct cg_inst *resword;

          switch (key - 1)
            {
              case 0:
                resword = &wordlist[0];
                goto compare;
              case 1:
                resword = &wordlist[1];
                goto compare;
              case 2:
                resword = &wordlist[2];
                goto compare;
              case 5:
                resword = &wordlist[3];
                goto compare;
              case 6:
                resword = &wordlist[4];
                goto compare;
              case 7:
                resword = &wordlist[5];
                goto compare;
              case 10:
                resword = &wordlist[6];
                goto compare;
              case 11:
                resword = &wordlist[7];
                goto compare;
              case 12:
                resword = &wordlist[8];
                goto compare;
              case 15:
                resword = &wordlist[9];
                goto compare;
              case 16:
                resword = &wordlist[10];
                goto compare;
              case 17:
                resword = &wordlist[11];
                goto compare;
              case 20:
                resword = &wordlist[12];
                goto compare;
              case 21:
                resword = &wordlist[13];
                goto compare;
              case 22:
                resword = &wordlist[14];
                goto compare;
              case 25:
                resword = &wordlist[15];
                goto compare;
              case 26:
                resword = &wordlist[16];
                goto compare;
              case 27:
                resword = &wordlist[17];
                goto compare;
              case 30:
                resword = &wordlist[18];
                goto compare;
              case 31:
                resword = &wordlist[19];
                goto compare;
              case 32:
                resword = &wordlist[20];
                goto compare;
              case 35:
                resword = &wordlist[21];
                goto compare;
              case 37:
                resword = &wordlist[22];
                goto compare;
              case 40:
                resword = &wordlist[23];
                goto compare;
              case 47:
                resword = &wordlist[24];
                goto compare;
              case 52:
                resword = &wordlist[25];
                goto compare;
              case 57:
                resword = &wordlist[26];
                goto compare;
              case 62:
                resword = &wordlist[27];
                goto compare;
            }
          return 0;
        compare:
          {
            register const char *s = resword->name;

            if (*str == *s && !strcmp (str + 1, s + 1))
              return resword;
          }
        }
    }
  return 0;
}
