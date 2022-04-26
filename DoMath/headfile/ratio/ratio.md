# /ratio
This directory includes a set of Cpp header files that process ratio numbers.
## ratio.h
This Cpp header file includes:
>*class* ratio
- A ratio number is expressed like (long)/(unsigned short).
>> private: long p=0;unsigned short q=1;
- Private member "p" and "q" express the value of a ratio number (p/q).
>>public: ratio();
- Construction function for class "ratio".
- You can pass 2 arguments as (long)p=0/(unsigned short)q=1, or pass 1 argument to copy-construct.
>>public: void operator();
- Used as valuation operator.
- You can pass 2 arguments as (long)p=0/(unsigned short)q=1, or pass 1 argument to valuate, as well.
>>public: long getp();
- Returns the denominator.
>>public: unsigned short getq();
- Returns the numerator.
>>public: void operator=();
- Valuation operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: bool operator==();
- Equivalence operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: void operator+=();
- Adding operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: void operator-=();
- Subtracting operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: void operator*=();
- Multiplying operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: void operator/=();
- Dividing operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: void operator+();
- Addition operator.
- You can pass 2 arguments. The first must be ratio, the next can be ratio or short.
>>public: void operator-();
- Subtraction operator.
- You can pass 2 arguments. The first must be ratio, the next can be ratio or short.
>>public: void operator*();
- Multiple operator.
- You can pass 2 arguments. The first must be ratio, the next can be ratio or short.
>>public: void operator/();
- Division operator.
- You can pass 2 arguments. The first must be ratio, the next can be ratio or short.
>>public: void operator++();
- Increment operator.
>>public: void operator--();
- Decrement operator.
>>public: bool operator>();
- Greater-than operator.
- You can pass 1 ratio argument or 1 short argument.
>>public: bool operator<();
- Smaller-than operator.
- You can pass 1 ratio argument or 1 short argument.
>>friend std::ostream& operator<<();
- std::ostream operator.
>>friend std::istream& operator>>();
- std::istream operator.
>>public: explicit operator int();
- Converting operator to int.
>>public: explicit operator float();
- Converting operator to float.
>>public: explicit operator double();
- Converting operator to double.
>>public: void simplify();
- Simplifies a ratio number.
- Is automatically invoked.
>>public: void from float();
- Convert float to ratio.