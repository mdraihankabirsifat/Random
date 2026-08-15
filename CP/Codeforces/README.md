# Codeforces Solution Organization Guide

This directory stores confirmed Codeforces solutions grouped by their primary
algorithm or technique. Future Codex runs should read this file first and
follow the workflow below without requiring the original prompt again.

## Work completed so far

The initial pass inventoried all 306 source files in `../batch_1/` and
`../batch_2/` (268 C++ files and 38 C files).

- Confirmed 268 solutions against official Codeforces problem records.
- Preserved all 38 unresolved, incomplete, or non-Codeforces files. The 37
  files from `batch_1/` now live in `Misc/`; `A_curr/307_.cpp`
  remains in its incoming folder.
- Added the canonical Codeforces URL as the first line of every confirmed file.
- Added the exact official title and a concise two-line revision description.
- Classified each confirmed solution by the primary technique used in that file.
- Renamed files independently inside each topic folder, starting from `1`.
- Preserved both `.cpp` and `.c` extensions.
- Removed 750 unused macro definitions from 70 confirmed files while retaining
  macros referenced directly or transitively by other retained macros.
- Verified normalized solution bodies against pre-change hashes; no solution
  logic was changed.
- Recorded a pre-change syntax baseline for all 306 files. Two files already
  failed before organization: `../batch_1/208_Sum_of_Round_Number.c` (now
  `Math/28_Sum_of_Round_Numbers.c`) and `Misc/149_new.c`. The final
  syntax sweep produced exactly these same two failures. Do not silently repair
  them during organization.

Historical counts immediately after this pass:

| Topic | Files |
| --- | ---: |
| Binary_Search | 1 |
| Bit_Manipulation | 8 |
| Brute_Force | 11 |
| Constructive_Algorithms | 29 |
| Data_Structures | 5 |
| Dynamic_Programming | 5 |
| Game_Theory | 13 |
| Geometry | 8 |
| Graph | 1 |
| Greedy | 61 |
| Hashing | 9 |
| Implementation | 14 |
| Math | 44 |
| Number_Theory | 14 |
| Prefix_Sum | 6 |
| Simulation | 3 |
| Sorting | 11 |
| String | 23 |
| Two_Pointers | 2 |
| **Confirmed total** | **268** |

The confirmed set contains 235 C++ files and 33 C files. These counts are a
historical record, not a permanent expectation; always rescan because new
solutions may have been added.

## Incoming and unresolved solutions

`Misc/` stores unresolved or non-Codeforces files moved from `../batch_1/`.
`A_curr/` remains an incoming area for new work. Scan both locations when
organizing future solutions. A file that cannot be confidently matched to an
official Codeforces problem must remain pending without an invented title,
description, link, or classification.

Files intentionally left pending by the initial pass:

- `Misc/100_g.cpp` - Generic filename; implementation could not be matched confidently to an official Codeforces problem.
- `Misc/112_Income_tax.c` - Standalone income-tax calculator with prompts; no Codeforces match found.
- `Misc/120_Josephus_Problem_I.cpp` - Matches CSES Josephus Problem I, not a Codeforces problem.
- `Misc/149_new.c` - Contains raw binary strings rather than C source code.
- `Misc/159_num.c` - Standalone digit-index program with prompts; no Codeforces match found.
- `Misc/166_Pallindrom.cpp` - Matches LeetCode Palindrome Number rather than Codeforces.
- `Misc/167_pallindro_string.cpp` - Generic palindrome checker with insufficient identifying information.
- `Misc/168_Pascals_Triangle.cpp` - Empty file with no identifying implementation.
- `Misc/182_Retaliation.cpp` - Implementation does not match Codeforces 2117D Retaliation; no unique official Codeforces match was found.
- `Misc/19_b.cpp` - Generic filename and anagram check; no confident official problem match.
- `Misc/200_string_pattern_detector.cpp` - Empty file with no identifying implementation.
- `Misc/203_Subarray_divisibility.cpp` - Matches CSES Subarray Divisibility rather than Codeforces.
- `Misc/204_subarray_sum.cpp` - Matches CSES Subarray Sums II rather than Codeforces.
- `Misc/215_test.cpp` - Empty test template; it does not represent Codeforces 25E Test.
- `Misc/223_Trapping_rain_water.cpp` - Empty file; title points to a non-Codeforces problem.
- `Misc/225_Triadiic_Fibonacci.c` - Incomplete standalone Fibonacci exercise; no Codeforces match found.
- `Misc/229_Tripple.cpp` - Empty file and ambiguous title.
- `Misc/230_tripple_four.c` - Standalone consecutive-triples exercise; no Codeforces match found.
- `Misc/242_below_average.cpp` - Generic filename and implementation do not match the similarly named Codeforces problem.
- `Misc/245_Absolute_Binary_Tree.cpp` - No official Codeforces problem match found for the title and implementation.
- `Misc/246_1_Being_the_best_faculty.cpp` - No official Codeforces problem match found.
- `Misc/247_2_Being_the_best_faculty.cpp` - No official Codeforces problem match found.
- `Misc/248_Reverse_Prefix_Sum.cpp` - No official Codeforces problem match found.
- `Misc/249_arko.cpp` - Generic filename; no official Codeforces problem match found.
- `Misc/250_cfgrouoping.cpp` - Ambiguous filename and no official Codeforces problem match found.
- `Misc/34_bracket.cpp` - Generic balanced-parentheses checker with multiple test cases; no unique official Codeforces match.
- `Misc/36_Breed_counting.cpp` - Empty file named after the USACO problem Breed Counting.
- `Misc/37_breed_counting_2.cpp` - Matches the USACO problem Breed Counting, not a Codeforces problem.
- `Misc/41_c.cpp` - Generic filename; implementation does not match Codeforces 1368A C+= and no unique match was found.
- `Misc/43_Cake_Assignment_new.cpp` - Empty file; filename is ambiguous and does not identify a distinct solution.
- `Misc/48_Capital_baazi.cpp` - Standalone text-uppercase exercise; no confident official Codeforces match.
- `Misc/49_chemical.cpp` - Incomplete/custom set-counting program; no confident official Codeforces match.
- `Misc/56_contest.cpp` - Implementation does not match Codeforces 501A Contest; no unique official match found.
- `Misc/58_Counting_bits.cpp` - LeetCode-style Solution::countBits implementation, not a Codeforces problem.
- `Misc/62_d.cpp` - Generic filename and prime-divisibility code; no confident official Codeforces match.
- `Misc/82_efficient_freq.cpp` - Empty file with no identifiable official Codeforces title.
- `Misc/306_c.cpp` - Generic filename; implementation does not match Codeforces 1368A C+= and its apparent recent contest problem is not in the public problemset.
- `A_curr/307_.cpp` - Incomplete template with no solution logic; cannot identify a public Codeforces problem.

## Required problem header

Every confirmed `.cpp` or `.c` solution must begin with its canonical
problem URL followed immediately by a short revision block:

```cpp
// https://codeforces.com/problemset/problem/4/A
/*
Problem: Watermelon

Determine whether a watermelon of weight w can be split into two
positive parts that both have even weight.
*/
```

Header rules:

- Use the exact official Codeforces title, including capitalization.
- Write a concise two- or three-line paraphrase; never copy the full statement.
- Put the canonical URL on the absolute first line.
- Do not add a second header when a valid one already exists.
- If the problem cannot be verified, leave it pending in `Misc/` or its
  incoming folder.

## Topic classification

Assign every confirmed solution to exactly one primary-topic folder based on
the technique actually used in that source file. Reuse these established names:

```text
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
String/
Two_Pointers/
```

Do not create aliases such as `DP/`, `DynamicProgramming/`, or
`Bit_manipulation/`. Add a new category only when a real solution clearly
requires a primary technique not represented above.

## Filename convention

Each topic folder has an independent contiguous sequence:

```text
Bit_Manipulation/
├── 1_Bitwise_Reversion.cpp
├── 2_Boneca_Ambalabu.cpp
└── 3_Boneca_Ambalabu.cpp
```

Use:

```text
<serial>_<Exact_Codeforces_Title_With_Underscores>.<cpp-or-c>
```

Filename rules:

- Restart numbering at `1` in each topic folder.
- Keep serials contiguous with no duplicates.
- Replace title spaces with underscores and preserve official capitalization.
- Omit a question mark because Windows filenames cannot contain `?`; sanitize
  any other Windows-forbidden punctuation without changing the title in the
  in-file header.
- Preserve the solution language extension.
- Keep separate files even when they solve the same problem.
- During a bulk migration, use the original numeric order to assign new serials.
- When adding one solution later, append it to the selected folder's sequence.

## Workflow for future Codex runs

1. Read this README and any repository instructions.
2. Inventory every `.cpp` and `.c` file in `Misc/` and incoming folders.
3. Inspect existing topic folders for new, misplaced, or conflicting files.
4. Record the starting source count and a compile/syntax baseline.
5. Identify each problem from its filename and implementation. Confirm the
   exact title and URL using official Codeforces records/pages; never rely on
   an ambiguous filename alone.
6. Finish a complete classification and collision-free rename plan before
   creating folders or moving files.
7. Add the canonical header without altering the solution body.
8. Remove unused macros only when explicitly requested. Preserve dependency
   chains when one retained macro refers to another.
9. Move each confirmed file into one primary-topic folder and normalize serials.
10. Update the historical summary and pending-file list in this README.
11. Run all final verification checks and report topic counts plus uncertainties.

## Non-negotiable safety rules

- Never optimize, repair, reformat, or rewrite solution logic during organization.
- Do not rename variables, functions, classes, or used macros.
- Never delete, merge, or overwrite a solution.
- Preserve unrelated files and pre-existing user changes.
- A compile failure that existed in the baseline is not authorization to fix it.
- If identification is uncertain, leave the file in its batch folder and explain why.

## Final verification checklist

Before reporting completion, confirm:

- Total source count after processing equals the count before processing.
- Every confirmed source exists at exactly one destination.
- No destination was overwritten.
- Every confirmed source starts with its canonical Codeforces URL.
- The next block contains the exact official title and a concise description.
- Solution bodies match their pre-edit contents except explicitly requested
  unused-macro removals.
- Macro cleanup leaves no undefined retained dependency or unused definition.
- Every topic folder uses one-based contiguous serials.
- `Misc/` and incoming folders contain only unresolved or newly added files.
- Post-change syntax results introduce no failures beyond the recorded baseline.

Use a final report in this form:

```text
Scanned: N files
Organized: X files
Left pending: Y files

Greedy: ...
Math: ...
...

Uncertain classifications:
- filename.cpp -> reason
```
