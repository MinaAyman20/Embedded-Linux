
# Embedded-Linux Task4

# Descripsion 
in this file we will create a static Libirary for DIO and PORT Drivers in MCAL Layer

# Steps
at first we need to add avr-gcc , avr-ar , avr-objdump , avr-objcopy int our PATH 

## 1) open .bashrc 
```bash
vim ~/.bashrc
```
## 2) add add avr-gcc , avr-ar , avr-objdump , avr-objcopy int our PATH 
```bash
PATH=$PATH:~/x-tools/avr/bin:~/x-tools/avr/bin/avr-ar:~/x-tools/avr/bin/avr-objdump:~/x-tools/avr/bin/avr-objcopy
```

## 3) The next step in your project directory which include :

   * LIB
   * MCAL
     * DIO
     * PORT
   * APP

   In DIO directory we will generate .o file including by own Libiraries and PORT libraries as DIO driver depends on PORT driver

   ```bash
   avr-gcc -c DIO.c -I ../PORT -I ../../LIB -o DIO.o
   ```
   
   In PORT directory we will generate .o file by their own files and nedded libiraries from LIB

   ```bash
   avr-gcc -c MPort_prog.c  -I ../../LIB -o MPort_prog.o
   ```
   
   Generate MPort_config.o for build it with main.c file
   ```bash
   avr-gcc -c MPort_config.c -I . -I ../../LIB -o MPort_config.o
   ```

3. In MCAL directory

   We will make a static library for MCAL drivers

   ```bash
   avr-ar -rcs libmcal.a DIO/DIO.o PORT/MPort_prog.o
   ```

4. In APP directory

   We will generate main.o to include the header library to symbol table

   ```bash
   avr-gcc -c main.c -I ../MCAL/DIO/ -I ../MCAL/PORT/ -I ../LIB/
   ```

5. Generate the executable by linking configuration files and static library of MCAL

   ```bash
   avr-gcc -mmcu=atmega32 -o main.elf main.o ../MCAL/PORT/MPort_config.o ../MCAL/libmcal.a 
   ```

   for    ``` -mmcu=atmega32 ``` flag that specify that the which the elf work on is atmega 32 
   
6. to Generate the hex file you need to use avr-objcopy beacause it can 
 ```bash
avr-objcopy -j .text -j .data -O ihex main.elf main.hex
 ```
 The -j option indicates that we want the information from the .text .data Sections 
 
 7. run the hex file on Proutes 
 
  
 
 ![proutes Linux](https://github.com/MinaAyman20/Embedded-Linux/assets/150968110/bab84b33-6338-4216-873d-cbf6580ee250)

 
 
 
 

