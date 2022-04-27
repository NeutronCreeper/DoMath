# /prime
This directory includes a set of Cpp header files that help with prime numbers.
***
## prime.h
This Cpp header file includes:
>bool prime(unsigned short);
- return whether a positive intis a prime number.
>bool prime(unsigned long);
- return whether a positive long int is a prime number.
>long* getPrimeFactors(unsigned long);
- return an array of prime factors of a positive long int. Index[0] is the number of prime factors, indices from [1] are the value of prime factors.
***
## primes8.h
This C header file includes:
>const unsigned char primes8[54];
- an array that saves prime numbers from 0 to 255.
***
## primes16.h
This C header file includes:
>const unsigned short primes16[6542];
- an array that saves prime numbers from 0 to 65535.
***
## _cmds.h
This Cpp header file includes built-in commands for users.
Including:
>void isprime(int);
- command to judge whether an int is prime.
>void factorize(int);
- command to factorize a non-prime int.
***
## prime.md
Documentation for this directory.
***
Tntea. Modified on Apr.27th,2022.