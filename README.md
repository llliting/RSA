# RSA 
This project first builds a "ReallyLongInt" data type that can hold binary numbers using vector. The "ReallyLongInt" data type implements a broad range of operations from basic arithemetic operations like addition, subtraction, multiplication, and subtraction to more mathematical functions such as isPrime and exponention. The second half of project utilizes ReallyLongInt's advantage of supporting large number to realize the RSA public key cryptophic system. 



## Running the program  

### Keygen
The first step of the encryption/decryption process is to generate public and private keys. The keygen file takes in two prime numbers to calculate the keys and store the keys in two separate files. 
```
$ make
$ ./keygen.exe <primenumber1> <primenumber2> <publickeyfile> <privatekeyfile>
```


### Encrypt
Encrypt takes in the public key file and an input text file. Then it runs the encryption process and stores the output cipher text.
```
$ ./encrypt.exe <publickeyfile> <inputtextfile> <outputcipherfile> 
``` 

### Decrypt
Similar to the encryption, the decryption takes in the private key file and decodes the ciphertext.
```
$ ./decrypt.exe <privatekeyfile> <cipherfile> <decryptedfile> 
``` 

### Unit Testing
Unit tests with Catch2 are utilized to test the project's correctness. 
<br />In terminal, type in `make coverage` to run the coverage tests of "ReallyLongInt.cpp" and "numberTheory.cpp." The coverage test result are stored in rli and nt folders as "index.html."
<br />To use the debug mode, type in `make debug`.


## Current Issues
* when the user tries to input two prime numbers smaller than 11 and 13, the decryption process does not work. 
* number theory cannot correctly calculate x and y  when the two numbers include at least one negative number.
