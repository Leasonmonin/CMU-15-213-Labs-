/* 
 * CS:APP Data Lab 
 * 
 * < Leason >
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */

#逻辑与或非 位运算与或取反异或  负数补码 掩码 符号位巧用
#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    /* Use ~ and & constuct NAND gate to calculate XOR */
    int temp = x & (~y) ;
    int temp2 = y & (~x) ;
    int result = temp | temp2 ;
    return result ;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    /* Tmin is 0b1000...0, so doing bit shift on 1 */
    int result = 1<<31 ; 
    return result ; 
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    /* Tmax is 0b0111...1, it is Tmin - 1. Do comparsion with Tmax */
    return !(x ^ ~(1<<31)); 
    
}
    //直接和max作比较 ； 利用Tmin-1=Tmax的性质 但是要排除-1这个答案 
    //所以标答是return !(~((x + 1) + x) | !(x + 1)); 
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    /* The simplest number satisfied the requirement is 0xAAA..A, so make it and do comparision */
    int mask = 0XAA + (0XAA << 8) + (0XAA << 16) + (0XAA << 24 ) ;
    return !((x&mask)^mask); //如果偶数位和奇数位都为1，结果会出错；先保留所有为1的位在和mask比较    
    //return  !(x ^ mask ) ; 
    
}
   //构造 合适掩码 比较 
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    /* Doing two's complement negation */
    return ~x + 1 ; 
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    /* Compare the hex ten's digit and hex one's digit */
    int ten = !((x>>4) ^ 3); 
    // compare one's digit greater than 8 or not
    int one = !((9+~(x & 0X0F)+1)>>31) ; //?
    return ten & one ; 
}
   //移位比较目标值 ；取反加1代替减法
/* 
 * conditional - same as x ? y : z  //位运算实现if选择
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    /* Use !x-1 and !!x-1 as identifier to make sure it only satisfy one side, other side is 0*/
    int mask1 = !x - 1;
    int mask2 = !!x - 1; // mask2=~mask1 is also established
    return (mask1 & y) | (mask2 & z);
}
//用x构造掩码来做比较 ！x=0 ，y ，此时y&全1，-1是全1； or z
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */

int isLessOrEqual(int x, int y) {
    /* Solve it case by case */
    int mark = (x>>31) ^ (y>>31) ; //结果全1 异号；结果是0 同号；
    int mark2 = ~mark ; //结果全1 同号；结果是0 异号；
    
    int temp = x >> 31; // 全1或者0 

    // mark = temp = 1 x负数 异号 结果为1 111 or mark = 0 ，temp = 1，x负数 同号 计算 y+(~x+1) 结果和全0作比较? >0 return 1 否则0 0101或者0110 ;
    // mark = temp = 0 x为正 同号 计算y+(~x+1)  结果和全0作比较>0 0001 0010 return 1 否则0 or x为正数 异号 结果为0 100;
    
    int sub = ( y+(~x+1) ) >>31; //全1或者0  

    return (mark & temp ) | ((~sub) & mark2) ;
}
   // 匹配上掩码和对应的判断标准，然后再处理分类
//4
/* 
 * logicalNeg -
 
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    /* 0 is the only number that is "positive" after its negation */
    int result = x |(~x)+1 ;
    return (result>>31)+1; //取符号位
}
//remenmber There are two number that is same as itself after the negation, $T_{min}$ and 0. 
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
    // x 是正数 or x 是负数 -取符号位
    int Isnegative = x>>31 ;
    x = x ^ Isnegative;
    int k = 0;
    int hasabit = 0;
  
    hasabit = !!(x & 0xFFFF0000);
    k += hasabit << 4;
    x = x >>(hasabit << 4);

    hasabit = !!( x & 0x0000FF00);
    k += hasabit << 3;
    x = x >>(hasabit << 3);

    hasabit = !!( x  & 0x000000F0);
    k += hasabit << 2;
    x = x >>(hasabit << 2);

    hasabit = !!( x  & 0x0000000C);
    k += hasabit << 1;
    x = x >>(hasabit << 1);

    hasabit = !!( x & 0x00000002);
    k += hasabit << 0;
    x = x >> hasabit;

    return k+x+1;

    //二分法 掩码 移位运算
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    int S = uf>>31 ;
    int E = (uf>>23) & 0XFF ;
    int Frac = uf & 0X7FFFFF ;
    int k = 8;

    if (E == 0){
        Frac = Frac <<1 ;
        if(Frac >> 23){
            E=1;
            Frac = Frac & 0x7FFFFF;
        }
    } else if(E == 255){
        return uf;
    } else{
        E = E+1;
    }
        
    return (S<<31)|(E<<23)|Frac ;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int S = uf>>31 ;
    int Exp = (uf>>23) & 0XFF ;
    int Frac = uf & 0X7FFFFF ;
    int E;
    int temp;

    if (Exp == 255){
        return 0x80000000u;
    } else if (Exp == 0){
        E = -126; 
        temp =Frac;
    } else {
        E = Exp-127 ;
        int temp = (1<<23)| Frac ;
    } 

    if (E < 0) return 0;
    if (E >= 31) return 0x80000000u;

    int result ;

    if (E>23){
      result = temp <<(E-23) ; 
    }else if (E<23) {
      result = temp >>(23-E) ;
    } else result = temp ; 
    
    if (S) result = -result ;
    return result; 
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precisioshurun floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) { 
    if (x<-149){
        return 0;
    } else if (x>127){
        return  0x7F800000;
    } else if (x>= -126){
        return (x+127)<<23;
    } else {
        return 1<<(x+149);
    }
}
