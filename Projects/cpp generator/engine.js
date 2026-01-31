// engine.js - The Robust Version
const Engine = {
    storedLiterals: [],
    storedHeaders: [],

    // 1. SAFETY: Hide all Headers (#include, #define) so they are NEVER touched
    maskHeaders: (code) => {
        Engine.storedHeaders = [];
        return code.replace(/^\s*#.*/gm, (match) => {
            Engine.storedHeaders.push(match);
            return `__SAFE_HEADER_${Engine.storedHeaders.length - 1}__`;
        });
    },

    // 2. SAFETY: Hide all Strings ("...") and Chars ('c')
    maskLiterals: (code) => {
        Engine.storedLiterals = [];
        return code.replace(/(["'])(?:(?=(\\?))\2.)*?\1/g, (match) => {
            Engine.storedLiterals.push(match);
            return `__SAFE_LITERAL_${Engine.storedLiterals.length - 1}__`;
        });
    },

    // Restore functions
    unmaskHeaders: (code) => {
        return code.replace(/__SAFE_HEADER_(\d+)__/g, (_, i) => Engine.storedHeaders[i]);
    },
    unmaskLiterals: (code) => {
        return code.replace(/__SAFE_LITERAL_(\d+)__/g, (_, i) => Engine.storedLiterals[i]);
    },

    stripComments: (code) => {
        return code
            .replace(/\/\*[\s\S]*?\*\/|\/\/.*/g, '')
            .replace(/^\s*[\r\n]/gm, '')
            .trim();
    },

    // 3. CONSISTENT Variable Mapping
    applyVariableMapping: (code) => {
        // Define the mapping options
        const options = {
            "n": ["limit", "sz", "count"],
            "ans": ["res", "out", "ret"],
            "cnt": ["track", "f", "counter"],
            "temp": ["tmp", "aux", "val"],
            "arr": ["vec", "list", "v"],
            "i": ["idx", "k", "it"],
            "j": ["pos", "col", "jt"]
        };

        // DECISION PHASE: Pick one choice per variable for the WHOLE file
        const activeMapping = {};
        for (let key in options) {
            const choices = options[key];
            activeMapping[key] = choices[Math.floor(Math.random() * choices.length)];
        }

        let newCode = code;
        for (let [oldName, newName] of Object.entries(activeMapping)) {
            // Use word boundary \b to ensure we only replace exact variables
            // Negative lookbehind (?<!__) ensures we don't break our SAFE masks
            const regex = new RegExp(`(?<!__)\\b${oldName}\\b(?!__)`, 'g');
            newCode = newCode.replace(regex, `§§${newName}§§`);
        }
        return newCode;
    },

    // 4. Safe Logic Swaps (Only on body code)
    swapLogic: (code) => {
        let newCode = code;
        // i++ -> ++i
        newCode = newCode.replace(/(\b\w+)\+\+(?!\+)/g, '§§++$1§§'); 
        // if(x==true) -> if(x)
        newCode = newCode.replace(/if\s*\((.*?)\s*==\s*true\)/g, 'if(§§$1§§)');
        return newCode;
    },

    // 5. Macro Injection
    injectMacros: (code) => {
        // Define safe templates that don't conflict
        const templates = [
            {
                head: `#include <bits/stdc++.h>\nusing namespace std;\n\n#define ll long long\n#define pb push_back\n\n`,
                longSub: "ll"
            },
            {
                head: `#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\ntypedef long long i64;\n#define pb push_back\n#define ALL(x) x.begin(), x.end()\n\n`,
                longSub: "i64"
            }
        ];

        const selected = templates[Math.floor(Math.random() * templates.length)];
        
        // Remove old headers manually if they exist in the body
        let body = code.replace(/#include\s+<.*?>/g, '').replace(/using namespace std;/g, '');
        
        // Apply consistent long long swap
        body = body.replace(/\blong long\b/g, `§§${selected.longSub}§§`);
        
        return selected.head + body.trim();
    },

    calculateDiff: (s1, s2) => {
        const cleanS2 = s2.replace(/§§/g, '').replace(/__SAFE_.*?__/g, '');
        const len1 = s1.length, len2 = cleanS2.length;
        if (len1 === 0) return 0;
        const matrix = Array.from({ length: len1 + 1 }, () => new Array(len2 + 1).fill(0));
        
        for (let i = 0; i <= len1; i++) matrix[i][0] = i;
        for (let j = 0; j <= len2; j++) matrix[0][j] = j;

        for (let i = 1; i <= len1; i++) {
            for (let j = 1; j <= len2; j++) {
                const cost = s1[i - 1] === cleanS2[j - 1] ? 0 : 1;
                matrix[i][j] = Math.min(matrix[i-1][j]+1, matrix[i][j-1]+1, matrix[i-1][j-1]+cost);
            }
        }
        return Math.floor((matrix[len1][len2] / Math.max(len1, len2)) * 100);
    }
};