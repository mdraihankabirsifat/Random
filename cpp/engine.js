// engine.js
const Engine = {
    stripComments: (code) => {
        return code
            .replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '')
            .replace(/^\s*[\r\n]/gm, '') 
            .trim();
    },

    // 1. Meaningful Variable Mapping (Common CP Patterns)
    applyVariableMapping: (code) => {
        const mapping = {
            "n": ["num_elements", "sz", "limit", "total_count"],
            "ans": ["result", "final_val", "output", "res"],
            "cnt": ["freq", "occurrence", "counter"],
            "temp": ["val", "buffer", "aux"],
            "arr": ["vec", "data_list", "elements"],
            "i": ["idx", "pos", "k"],
            "j": ["ptr", "col"]
        };
        
        let newCode = code;
        for (let [oldName, choices] of Object.entries(mapping)) {
            // Pick one meaningful name per execution
            const newName = choices[Math.floor(Math.random() * choices.length)];
            const regex = new RegExp(`\\b${oldName}\\b`, 'g');
            newCode = newCode.replace(regex, newName);
        }
        return newCode;
    },

    // 2. Macro implementation in Main Code
    // This replaces standard code patterns with the macros defined at the top
    implementMacros: (code) => {
        let newCode = code;

        // Replace standard for-loop with a macro pattern
        // Matches: for(int i=0; i<n; i++) -> FOR(i, 0, n)
        const forLoopRegex = /for\s*\(\s*(?:int|ll|lli|i64)\s+(\w+)\s*=\s*(\d+|[a-zA-Z_]\w*)\s*;\s*\1\s*<\s*([^;]+)\s*;\s*\1\s*\+\+\s*\)/g;
        newCode = newCode.replace(forLoopRegex, 'FOR($1, $2, $3)');

        // Replace push_back with pb
        newCode = newCode.replace(/\.push_back\(/g, '.pb(');

        // Replace long long with a consistent macro
        newCode = newCode.replace(/\blong long\b/g, 'll');

        return newCode;
    },

    // 3. Relevant Macros Header
    injectMacros: (code) => {
        const macros = [
            `#include <bits/stdc++.h>\nusing namespace std;\n\n#define ll long long\n#define pb push_back\n#define FOR(i, a, b) for (int i = (a); i < (b); ++i)\n#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);\n\n`,
            `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\ntypedef long long ll;\n#define pb push_back\n#define FOR(idx, start, end) for (ll idx = start; idx < end; idx++)\n#define ALL(x) x.begin(), x.end()\n\n`
        ];
        
        const header = macros[Math.floor(Math.random() * macros.length)];
        return header + code;
    },

    calculateDiff: (s1, s2) => {
        const len1 = s1.length, len2 = s2.length;
        const matrix = Array.from({ length: len1 + 1 }, () => new Array(len2 + 1).fill(0));
        for (let i = 0; i <= len1; i++) matrix[i][0] = i;
        for (let j = 0; j <= len2; j++) matrix[0][j] = j;

        for (let i = 1; i <= len1; i++) {
            for (let j = 1; j <= len2; j++) {
                const cost = s1[i - 1] === s2[j - 1] ? 0 : 1;
                matrix[i][j] = Math.min(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
            }
        }
        return Math.floor((matrix[len1][len2] / Math.max(len1, len2)) * 100);
    }
};