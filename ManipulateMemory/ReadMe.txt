A program that allows the user to:
        1. Allocate a  block of memory to store a specified number of integers
        2. Store a value at a specified index of the allocated block of memory
        3. Get the value store at the specified index of the memory block
   	Memory is freed after the above instructions are carried out and the quit option is selected.




** Notes for the corresponding code: Assignment4-1.c

After some testing, the following has been discovered:
- Values can be to assigned to an index outside the amount of memory specified
    - Values can be assigned to indices even when memory is not allocated
- When you try to get a value from an index that data hasn't been stored in
  you get '0' (zero).
- If you try to get a value outside the memory specified without having assigned
  a value there, you get some random number (either positive or negative).
- If option 1 (Allocate) is run, after memory has been previously allocated and
  values stored within, the values are overwritten with '0'
