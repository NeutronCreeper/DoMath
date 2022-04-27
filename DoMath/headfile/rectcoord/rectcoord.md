# /prime
This directory includes a set of Cpp header files that declares a simple rectangular coordinate.
***
## rectcoord.h
>template<typename>class point{};
>>private: typename x,y;
- coordinates of a point.
>>public: point(typename=0,typename=0);
- 
>>public: void operator()(typename=0,typename=0);
- 
>>public: void operator=(const point<typename>&);
- 
>>public: bool operator==(const point<typename>&);
- 
>>public: void operator+=(const point<typename>&);
- 
>>public: void operator-=(const point<typename>&);
- 
>>public: point operator+(const point<typename>&);
- 
>>public: point operator-(const point<typename>&);
- 
>>public: friend std::ostream& operator<<(std::ostream&,const point<typename>&);
- 
>>public: typename getx();
- 
>>public: typename gety();
- 
***
## _cmds.h
This Cpp header file includes built-in commands for users.
Including:
>void isprime(int);
- command to judge whether an int is prime.
>void factorize(int);
- command to factorize a non-prime int.
***
## rectcoord.md
Documentation for this directory.
***
Tntea. Modified on Apr.27th,2022.