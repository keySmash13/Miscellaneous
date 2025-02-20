This program takes an inputted number in any base from 2-9 and converts it into decimal. It will also determine which of the inputs has the highest value.

## To run the program
Type this to start inputting values:
```bash
g++ program1.cc
./a.out
```

## The formatted input is as follows:
```bash
number base y/n
```
number: the number you would like converted  
base: the base that the number is in  
y/n: choose if you would like to enter another number  

For example, this input:
```bash
-1101 2 y
1205 6 y
7517 9 n
```

Will have the output:
```bash
-13
293
5524
Of the 3 values input, the 3rd value entered (5524) was the largest
```

## To run pre-determined tests
Type this, with X being any number from 1 to 6:
```bash
make testX
```

## Once you are done
Type this to clean up any unneccesary files:
```bash
make clean
```
