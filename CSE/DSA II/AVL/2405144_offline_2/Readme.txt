CSE 208 - Data Structures and Algorithms II Sessional
Assignment 2: AVL Trees and Interval Scheduling


FILES INCLUDED
--------------
1. AVLTree.cpp
2. IntervalScheduler.cpp
3. timing_report.txt
4. Readme.txt


COMPILATION
-----------

AVL Tree:
g++ -std=c++17 AVLTree.cpp -o avl_tree

Interval Scheduler:
g++ -std=c++17 IntervalScheduler.cpp -o interval_scheduler


EXECUTION
---------

Both programs take the input filename and output filename as command-line
arguments.

AVL Tree:
./avl_tree <input-file> <output-file>

Example:
./avl_tree testcase_avl.txt output_avl.txt

Interval Scheduler:
./interval_scheduler <input-file> <output-file>

Example:
./interval_scheduler testcase_large_interval.txt output_interval.txt


OUTPUT AND TIMING
-----------------

The result of every operation is written to the output file supplied through
the second command-line argument.

The timing summary is printed separately to the standard output. It can be
viewed in the terminal or redirected to a text file when preparing
timing_report.txt.

Example:
"AVL" | Set-Content timing_report.txt
.\avl_tree.exe testcase_avl.txt output_avl.txt | Add-Content timing_report.txt

"" | Add-Content timing_report.txt
"Interval Scheduler" | Add-Content timing_report.txt
.\interval_scheduler.exe testcase_large_interval.txt output_large_interval.txt | Add-Content timing_report.txt

Get-Content timing_report.txt

IMPLEMENTATION SUMMARY
----------------------

AVLTree.cpp:
- Implements AVL insertion, deletion, search, and traversal.
- Performs LL, RR, LR, and RL rotations when rebalancing is needed.
- Search, insertion, and deletion take O(log n) worst-case time.
- Traversal takes O(n) time.

IntervalScheduler.cpp:
- Implements an AVL-based interval scheduler.
- Each node stores maxEnd in addition to its height.
- Supports ADD, REMOVE, UPDATE, CONFLICT, OVERLAPS, AT, and NEXT.
- maxEnd is maintained after insertion, deletion, update, and rotation.
- OVERLAPS and AT use maxEnd-based pruning.


NOTES
-----
- The programs require a C++17-compatible compiler.
- No absolute file path or IDE-specific configuration is used.
- Executable files, object files, build folders, and test-case files are not
  included in the submission folder.