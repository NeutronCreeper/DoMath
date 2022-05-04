# /samkhya
This directory includes a set of Cpp header files that help with samkhya.
***
## samkhya.h
This Cpp header file includes:
>bool ifpow(const long&,const unsigned char=2);
- returns whether 1 long int is the power of a certain number.
>short gcd(short,short);
- returns greatest common diviser of 2 int.
>long gcdl(long,long);
- returns greatest common diviser of 2 long int.
>inline short lcm(short,short);
- returns least common multiple of 2 int.
>inline long lcml(long&,long&);
- returns least common multiple of 2 long int.
***
## _cmds.h
This Cpp header file includes built-in commands for users.
Including:
>namespace samkhya_cmds{}
>>void issqr(int);
- command to judge whether a long int is a square number.
>>void ispow(int);
- command to judge whether a long int is the certain int power of an int.
>>void GCD(int);
- command to calculate greatest common diviser of 2 long int.
>>void LCM(int);
- command to calculate least common multiple of 2 long int.
***
## samkhya.md
Documentation for this directory.
***
Tntea. Modified on Apr.27th,2022.