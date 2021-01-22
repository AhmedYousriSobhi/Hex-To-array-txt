# Hex-To-array-txt
### C code to convert Hex file to array Txt file.
### This code is used to Covert Hex file to Txt file, so you can easily extract hex bytes into array in 'txt' file.
### So this txt file would be input in bootloader code.
## Code Idea:
 - First you need to understand [Intel Hex Format](https://en.wikipedia.org/wiki/Intel_HEX)
 - This code is simple just open the hex file: 
   - Reads every line byte by byte.
   - Check the number of data bytes in this line and reads these data.
   - Store these data in the output txt file which i named OutputArray.txt and fill the reset of bytes by 0xFF until the code size is equivlent to const integer * PAGE_SIZE in ATmega-16. The Page size in AVR is 128 bytes = 64 word.
   - The OutputArray.txt file contains the Data bytes of the Application code, Code size, and number of pages needed for this code in the flash memory.
   
## CMD Command:
![CMD](https://user-images.githubusercontent.com/66730765/103922233-22389600-511c-11eb-9613-85dd6be1f21b.PNG)

## .HEX File:
![Hex file](https://user-images.githubusercontent.com/66730765/103922260-2c5a9480-511c-11eb-9845-d17ab77224eb.PNG)

## .TXT File:
![txt file](https://user-images.githubusercontent.com/66730765/103922331-43998200-511c-11eb-9c28-1e240584815b.PNG)

