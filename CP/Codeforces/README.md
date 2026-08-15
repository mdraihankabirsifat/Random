# Codeforces Solution Organization Guide

This directory stores competitive-programming sources grouped by their primary
algorithm or technique. It contains both officially verified Codeforces
solutions and a smaller descriptively named practice set whose exact online
problem could not be verified.

Future Codex runs should read this file first and follow the workflow below.

## Work completed so far

The initial pass inventoried 306 source files from `../batch_1/` and
`../batch_2/`:

- 268 solutions were matched to official Codeforces problem records.
- Each verified solution received its canonical Codeforces URL, exact official
  title, and a concise revision description.
- Verified solutions were classified by the technique used in the source and
  numbered independently inside each topic folder.
- 750 unused macro definitions were removed from 70 verified files while
  preserving direct and transitive macro dependencies.
- Normalized pre-change hashes confirmed that no solution logic was changed.

A later pass organized the 37 formerly unresolved files from `Misc/`:

- Every file received a descriptive code-based filename and one primary topic.
- No Codeforces URL or official-problem header was added to these files.
- Empty or incomplete sources use `_Draft` or `_Data` in their names.
- SHA-256 verification confirmed all 37 files remained byte-identical.
- `Misc/` is now empty.
- `A_curr/307_.cpp` remains the only pending source.

The syntax baseline contains two pre-existing failures:

- `Math/28_Sum_of_Round_Numbers.c`
- `Constructive_Algorithms/31_Binary_String_Enumeration_Data.c`

The second file contains raw binary-string data rather than compilable C code.
Do not silently repair either file during an organization pass.

## Current source counts

| Topic | Files |
| --- | ---: |
| Array | 2 |
| Binary_Search | 1 |
| Bit_Manipulation | 9 |
| Brute_Force | 12 |
| Constructive_Algorithms | 32 |
| Data_Structures | 6 |
| Dynamic_Programming | 9 |
| Game_Theory | 13 |
| Geometry | 8 |
| Graph | 1 |
| Greedy | 61 |
| Hashing | 11 |
| Implementation | 16 |
| Math | 45 |
| Number_Theory | 15 |
| Prefix_Sum | 11 |
| Simulation | 5 |
| Sorting | 14 |
| Stack | 1 |
| String | 28 |
| Sweep_Line | 1 |
| Tree | 1 |
| Two_Pointers | 3 |
| **Categorized total** | **305** |
| A_curr (pending) | 1 |
| **All sources** | **306** |

These counts are a historical snapshot. Always rescan the filesystem because
new solutions may have been added.

## Descriptively categorized sources

The following 37 files are organized by implementation technique but are not
verified as Codeforces problems. Their filenames are descriptive rather than
official titles, and they intentionally have no Codeforces URL header:

- `Sorting/12_Anagram_Check.cpp`
- `Stack/1_Balanced_Parentheses.cpp`
- `Prefix_Sum/7_Breed_Counting_Draft.cpp`
- `Prefix_Sum/8_Breed_Counting.cpp`
- `Sorting/13_Parity_Based_Sorting.cpp`
- `Constructive_Algorithms/30_Cake_Assignment_Draft.cpp`
- `String/24_Uppercase_Words_Line_by_Line.cpp`
- `Data_Structures/6_Distinct_Chemicals_in_Reactions.cpp`
- `Sorting/14_Sort_String_in_Descending_Order.cpp`
- `Bit_Manipulation/9_Counting_Bits.cpp`
- `Number_Theory/15_Smallest_Prime_Not_Dividing_All_Elements.cpp`
- `Hashing/10_Efficient_Frequency_Draft.cpp`
- `Dynamic_Programming/6_Minimum_Cost_Nondecreasing_Array.cpp`
- `Implementation/15_Income_Tax_Calculator.c`
- `Simulation/4_Josephus_Problem_I.cpp`
- `Constructive_Algorithms/31_Binary_String_Enumeration_Data.c`
- `String/25_Nth_Digit_of_a_Number.c`
- `String/26_Palindrome_Number.cpp`
- `String/27_Palindrome_String.cpp`
- `Dynamic_Programming/7_Pascals_Triangle_Draft.cpp`
- `Constructive_Algorithms/32_Partition_by_Maximum_Value.cpp`
- `String/28_String_Pattern_Detector_Draft.cpp`
- `Prefix_Sum/9_Subarray_Divisibility.cpp`
- `Prefix_Sum/10_Subarray_Sums_II.cpp`
- `Implementation/16_Empty_Test_Template.cpp`
- `Two_Pointers/3_Trapping_Rain_Water_Draft.cpp`
- `Dynamic_Programming/8_Tribonacci_Number_Draft.c`
- `Hashing/11_Triple_Draft.cpp`
- `Array/1_Three_Consecutive_Equal_Elements.c`
- `Array/2_Elements_Below_Maximum.cpp`
- `Tree/1_Absolute_Binary_Tree.cpp`
- `Brute_Force/12_Being_the_Best_Faculty_Brute_Force.cpp`
- `Sweep_Line/1_Being_the_Best_Faculty_Sweep_Line.cpp`
- `Prefix_Sum/11_Reverse_2D_Prefix_Sum.cpp`
- `Dynamic_Programming/9_Count_Bracket_Subsequences_by_Balance.cpp`
- `Math/45_Group_Size_Difference.cpp`
- `Simulation/5_Cyclic_Binary_Swap_Simulation.cpp`

## Incoming solutions

`A_curr/` is the active incoming area. `Misc/` may be reused temporarily
when a source cannot yet be identified or classified.

If a problem cannot be confidently matched to Codeforces:

- Never invent a Codeforces title, URL, or official problem description.
- Leave it pending unless the user explicitly requests descriptive
  classification.
- When descriptive classification is requested, derive the filename and topic
  from the implementation and clearly document that it is unverified.

## Required header for verified Codeforces problems

Every officially verified `.cpp` or `.c` solution must begin with its
canonical problem URL followed immediately by a short revision block:

```cpp
// https://codeforces.com/problemset/problem/4/A
/*
Problem: Watermelon

Determine whether a watermelon of weight w can be split into two
positive parts that both have even weight.
*/
```

Header rules:

- Use the exact official Codeforces title and capitalization.
- Write a concise two- or three-line paraphrase; never copy the full statement.
- Put the canonical URL on the absolute first line.
- Do not add a second header when a valid one already exists.
- Do not apply this header format to descriptively classified, unverified files.

## Topic classification

Assign each source to exactly one primary-topic folder based on the technique
actually used in that source. Reuse these established names:

```text
Array/
Binary_Search/
Bit_Manipulation/
Brute_Force/
Constructive_Algorithms/
Data_Structures/
Dynamic_Programming/
Game_Theory/
Geometry/
Graph/
Greedy/
Hashing/
Implementation/
Math/
Number_Theory/
Prefix_Sum/
Simulation/
Sorting/
Stack/
String/
Sweep_Line/
Tree/
Two_Pointers/
```

Do not create aliases such as `DP/`, `DynamicProgramming/`, or
`Bit_manipulation/`. Add a category only when a real source clearly requires
a primary technique not represented above.

## Filename convention

Each topic folder has an independent contiguous sequence:

```text
Bit_Manipulation/
  1_Bitwise_Reversion.cpp
  2_Boneca_Ambalabu.cpp
  ...
  9_Counting_Bits.cpp
```

Verified Codeforces files use:

```text
<serial>_<Exact_Codeforces_Title_With_Underscores>.<cpp-or-c>
```

Descriptively classified files use:

```text
<serial>_<Clear_Code_Based_Title_With_Underscores>.<cpp-or-c>
```

Filename rules:

- Restart numbering at `1` in every topic folder.
- Keep serials contiguous with no duplicates.
- Append new sources after the folder's current highest serial.
- Preserve the source-language extension.
- Keep separate files even when they solve the same problem.
- Use `_Draft` for empty or incomplete sources and `_Data` for a file that
  contains data rather than compilable source.
- During bulk migration, preserve the old numeric order when assigning serials.
- Sanitize Windows-forbidden punctuation without changing an official title in
  the verified file's in-source header.

## Workflow for future Codex runs

1. Read this README and any repository instructions.
2. Inventory every `.cpp` and `.c` file in `A_curr/`, `Misc/`, and the
   existing topic folders before editing.
3. Record the starting source count, file hashes, and syntax baseline.
4. Identify each problem from its filename and implementation. For a claimed
   Codeforces solution, verify the exact title and URL using official records.
5. Complete the classification and collision-free rename plan before moving.
6. Add the canonical header only to officially verified Codeforces solutions.
7. Remove unused macros only when explicitly requested, preserving dependency
   chains between retained macros.
8. Move each source into one primary-topic folder and keep serials contiguous.
9. Update this README's counts and unverified-source record.
10. Verify counts, paths, hashes, headers, numbering, and syntax results.

## Non-negotiable safety rules

- Never optimize, repair, reformat, or rewrite solution logic while organizing.
- Do not rename variables, functions, classes, or used macros.
- Never delete, merge, or silently overwrite a source.
- Preserve unrelated files and pre-existing user changes.
- Existing syntax failures are not authorization to fix code.
- Never represent a descriptive filename as an official problem title.
- If confidence is insufficient, keep the source pending or label it
  descriptively only when requested.

## Final verification checklist

Before reporting completion, confirm:

- Total source count after processing equals the count before processing.
- Every source exists at exactly one destination.
- No destination was overwritten.
- Every verified Codeforces source starts with its canonical URL and exact title.
- Unverified descriptive sources do not contain invented Codeforces links.
- Solution bodies match their pre-edit hashes except explicitly requested
  macro removals.
- Every topic folder has one-based contiguous serials.
- No unexpected syntax failure was introduced.
- README counts and locations match the filesystem.

Use a final report in this form:

```text
Scanned: N files
Organized: X files
Left pending: Y files

Greedy: ...
Math: ...
...

Unverified descriptive files: N
```

