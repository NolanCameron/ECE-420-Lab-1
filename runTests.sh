#!/bin/bash

sizes=(2x2 2x2 4x4 4x4 4x4 9x9 9x9 16x16 16x16 16x16 100x100 100x100 100x100 100x100) 
threads=(1 4 1 4 16 1 9 1 4 16 1 4 25 100)

# Test 1 - 2x2 matrix with 1 thread
# Test 2 - 2x2 matrix with 4 threads
# Test 3 - 4x4 matrix with 1 thread 
# Test 4 - 4x4 matrix with 4 threads
# Test 5 - 4x4 matrix with 16 threads
# Test 6 - 9x9 matrix with 1 thread
# Test 7 - 9x9 matrix with 9 threads


# Test 8 - 16x16 matrix with 1 thread
# Test 9 - 16x16 matrix with 4 threads
# Test 10 - 16x16 matrix with 16 thread
# Test 11 - 100x100 matrix with 1 thread
# Test 12 - 100x100 matrix with 4 threads
# Test 13 - 100x100 matrix with 25 threads
# Test 14 - 100x100 matrix with 100 threads



echo "=========== KNOWN CASE TESTS ==========="
make
make matrixgen
rm diff*
rm serial*

for i in {0..6} 
do
echo " ----- Executing Test $i -----"
cp test${sizes[i]}in.txt data_input
./main ${threads[i]}
cp data_output test${sizes[i]}_t${threads[i]}out.txt
echo "${threads[i]}" >> diffknown${sizes[i]}.txt
diff -w test${sizes[i]}out.txt test${sizes[i]}_t${threads[i]}out.txt >> diffknown${sizes[i]}.txt
done


 echo "=========== UNKNOWN CASE TESTS ==========="

 for i in {0..13}
 do
 echo " ----- Executing Test $i -----"
 echo "${threads[i]}" >> diff${sizes[i]}.txt
 if [ $i -eq 0 ]; then
 ./matrixgen -s"2"
 ./main 1
 cp data_output serialout2x2.txt
 elif [ $i -eq 2 ]; then
  ./matrixgen -s"4"
   ./main 1
 cp data_output serialout4x4.txt
 elif [ $i -eq 5 ]; then
  ./matrixgen -s"9"
   ./main 1
 cp data_output serialout9x9.txt
 elif [ $i -eq 7 ]; then
  ./matrixgen -s"16"
   ./main 1
 cp data_output serialout16x16.txt
 elif [ $i -eq 10 ]; then
  ./matrixgen -s"100"
   ./main 1
 cp data_output serialout100x100.txt
 else
 ./main ${threads[i]}
 diff data_output serialout${sizes[i]}.txt >> diff${sizes[i]}.txt
 fi
 
done