/*
===============================================================================
ORACLE ADVANCED SQL LAB TEST CHEATSHEET
HR Schema: JOIN + GROUP BY + SUBQUERY + EXISTS + CASE + SET OPERATIONS + WITH

Prepared from:
- Sukarna Barua, A Brief Introduction to Oracle SQL/PL-SQL
  Chapters 4-7 and 11 (printed pages 36-58 and 82-89)
- CSE 215 SQL lectures on joins, aggregation, subqueries, and set operations
- July 2025 CSE 216 Online-2: A1+A2, B1+B2, and C1+C2

IMPORTANT:
- Oracle SQL syntax is used throughout.
- Examples assume the standard Oracle HR schema.
- Do not run this entire file at once. Copy only the required query block.
- Read the question carefully: row condition -> WHERE; group condition -> HAVING.
- Give every table a short alias in multi-table queries.
===============================================================================
*/


/*=============================================================================
0. HR SCHEMA MAP - MOST USED PATHS
=============================================================================*/

-- Employee -> department
-- EMPLOYEES.DEPARTMENT_ID = DEPARTMENTS.DEPARTMENT_ID

-- Employee -> job
-- EMPLOYEES.JOB_ID = JOBS.JOB_ID

-- Department -> location -> country -> region
-- DEPARTMENTS.LOCATION_ID = LOCATIONS.LOCATION_ID
-- LOCATIONS.COUNTRY_ID = COUNTRIES.COUNTRY_ID
-- COUNTRIES.REGION_ID = REGIONS.REGION_ID

-- Employee -> manager: both are rows of EMPLOYEES
-- EMPLOYEES.MANAGER_ID = manager.EMPLOYEE_ID

-- Employee -> previous job records
-- EMPLOYEES.EMPLOYEE_ID = JOB_HISTORY.EMPLOYEE_ID

-- Common full-name expression
SELECT E.FIRST_NAME || ' ' || E.LAST_NAME AS FULL_NAME
FROM EMPLOYEES E;


/*=============================================================================
1. JOIN TEMPLATES
=============================================================================*/

-- Inner join: only matching rows.
SELECT E.EMPLOYEE_ID,
       E.FIRST_NAME,
       D.DEPARTMENT_NAME
FROM EMPLOYEES E
JOIN DEPARTMENTS D
  ON D.DEPARTMENT_ID = E.DEPARTMENT_ID;

-- USING is shorter when both columns have the same name.
-- Do not write E.DEPARTMENT_ID in SELECT after USING; use DEPARTMENT_ID.
SELECT E.EMPLOYEE_ID,
       DEPARTMENT_ID,
       D.DEPARTMENT_NAME
FROM EMPLOYEES E
JOIN DEPARTMENTS D
USING (DEPARTMENT_ID);

-- Employee + department + location + country.
SELECT E.EMPLOYEE_ID,
       D.DEPARTMENT_NAME,
       L.CITY,
       C.COUNTRY_NAME
FROM EMPLOYEES E
JOIN DEPARTMENTS D
  ON D.DEPARTMENT_ID = E.DEPARTMENT_ID
JOIN LOCATIONS L
  ON L.LOCATION_ID = D.LOCATION_ID
JOIN COUNTRIES C
  ON C.COUNTRY_ID = L.COUNTRY_ID;

-- Self join: employee and manager.
-- Inner join excludes the top employee whose MANAGER_ID is NULL.
SELECT E.EMPLOYEE_ID,
       E.FIRST_NAME || ' ' || E.LAST_NAME AS EMPLOYEE_NAME,
       M.FIRST_NAME || ' ' || M.LAST_NAME AS MANAGER_NAME
FROM EMPLOYEES E
JOIN EMPLOYEES M
  ON M.EMPLOYEE_ID = E.MANAGER_ID;

-- Left join keeps employees even when they have no manager.
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME AS EMPLOYEE,
       M.LAST_NAME AS MANAGER
FROM EMPLOYEES E
LEFT JOIN EMPLOYEES M
  ON M.EMPLOYEE_ID = E.MANAGER_ID;

-- Keep all departments, including departments with zero employees.
-- COUNT(E.EMPLOYEE_ID) is required; COUNT(*) would return 1 for an empty dept.
SELECT D.DEPARTMENT_ID,
       D.DEPARTMENT_NAME,
       COUNT(E.EMPLOYEE_ID) AS EMP_COUNT
FROM DEPARTMENTS D
LEFT JOIN EMPLOYEES E
  ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
GROUP BY D.DEPARTMENT_ID, D.DEPARTMENT_NAME;

-- Non-equi join example: match salary to a salary range.
SELECT E.LAST_NAME,
       E.SALARY,
       G.GRADE_LEVEL
FROM EMPLOYEES E
JOIN JOB_GRADES G
  ON E.SALARY BETWEEN G.LOWEST_SAL AND G.HIGHEST_SAL;


/*=============================================================================
2. JOIN + GROUP BY + HAVING
=============================================================================*/

-- Department statistics with department name.
SELECT D.DEPARTMENT_ID,
       D.DEPARTMENT_NAME,
       COUNT(*) AS EMP_COUNT,
       ROUND(AVG(E.SALARY), 2) AS AVG_SALARY,
       MAX(E.SALARY) AS MAX_SALARY
FROM DEPARTMENTS D
JOIN EMPLOYEES E
  ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
GROUP BY D.DEPARTMENT_ID, D.DEPARTMENT_NAME
HAVING COUNT(*) >= 3
   AND AVG(E.SALARY) > 5000;

-- WHERE filters individual rows before grouping.
-- HAVING filters complete groups after aggregation.
SELECT E.DEPARTMENT_ID,
       COUNT(*) AS HIGH_EARNER_COUNT
FROM EMPLOYEES E
WHERE E.SALARY > 5000
GROUP BY E.DEPARTMENT_ID
HAVING COUNT(*) >= 3;

-- All selected non-aggregate columns must appear in GROUP BY.
-- Correct: both ID and name are grouped.
SELECT D.DEPARTMENT_ID,
       D.DEPARTMENT_NAME,
       COUNT(*) AS EMP_COUNT
FROM DEPARTMENTS D
JOIN EMPLOYEES E
  ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
GROUP BY D.DEPARTMENT_ID, D.DEPARTMENT_NAME;


/*=============================================================================
3. SUBQUERY OUTPUT TYPES AND WHERE OPERATORS
=============================================================================*/

-- Scalar subquery: must return exactly one value; use =, >, <, >=, <=, <>.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY >
      (SELECT AVG(X.SALARY)
       FROM EMPLOYEES X);

-- Multi-row, one-column subquery: use IN, ANY, or ALL.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.DEPARTMENT_ID
FROM EMPLOYEES E
WHERE E.DEPARTMENT_ID IN
      (SELECT D.DEPARTMENT_ID
       FROM DEPARTMENTS D
       WHERE D.LOCATION_ID IN (1700, 1800));

-- IN means equal to at least one returned value.
-- = ANY has the same basic meaning as IN.

-- Multi-column comparison.
SELECT E.EMPLOYEE_ID, E.JOB_ID, E.SALARY
FROM EMPLOYEES E
WHERE (E.JOB_ID, E.SALARY) IN
      (SELECT X.JOB_ID, MAX(X.SALARY)
       FROM EMPLOYEES X
       GROUP BY X.JOB_ID);

-- Subquery in SELECT: it must return at most one value for each outer row.
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME,
       (SELECT D.DEPARTMENT_NAME
        FROM DEPARTMENTS D
        WHERE D.DEPARTMENT_ID = E.DEPARTMENT_ID) AS DEPARTMENT_NAME
FROM EMPLOYEES E;

-- Subquery in FROM: creates a temporary result table.
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME,
       E.SALARY,
       S.AVG_SALARY
FROM EMPLOYEES E
JOIN (SELECT DEPARTMENT_ID,
             AVG(SALARY) AS AVG_SALARY
      FROM EMPLOYEES
      GROUP BY DEPARTMENT_ID) S
  ON S.DEPARTMENT_ID = E.DEPARTMENT_ID
WHERE E.SALARY > S.AVG_SALARY;


/*=============================================================================
4. CORRELATED SUBQUERIES
=============================================================================*/

-- Correlated subquery: uses the current row of the outer query.
-- Employees earning above their own department average.
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME,
       E.SALARY,
       E.DEPARTMENT_ID
FROM EMPLOYEES E
WHERE E.SALARY >
      (SELECT AVG(X.SALARY)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID);

-- Employees earning more than at least three other employees.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
WHERE (SELECT COUNT(*)
       FROM EMPLOYEES X
       WHERE X.SALARY < E.SALARY) >= 3;

-- Highest-paid employee(s) in each department.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.DEPARTMENT_ID, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY =
      (SELECT MAX(X.SALARY)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID);

-- Department size as a correlated scalar value.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.DEPARTMENT_ID
FROM EMPLOYEES E
WHERE (SELECT COUNT(*)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID) > 5;


/*=============================================================================
5. EXISTS AND NOT EXISTS
=============================================================================*/

-- EXISTS checks whether at least one matching row exists.
-- Departments having at least one employee.
SELECT D.DEPARTMENT_ID, D.DEPARTMENT_NAME
FROM DEPARTMENTS D
WHERE EXISTS
      (SELECT 1
       FROM EMPLOYEES E
       WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID);

-- Employees who really have a manager, explicitly using EXISTS.
SELECT E.EMPLOYEE_ID, E.LAST_NAME
FROM EMPLOYEES E
WHERE EXISTS
      (SELECT 1
       FROM EMPLOYEES M
       WHERE M.EMPLOYEE_ID = E.MANAGER_ID);

-- Employees with at least one JOB_HISTORY record.
SELECT E.EMPLOYEE_ID, E.LAST_NAME
FROM EMPLOYEES E
WHERE EXISTS
      (SELECT 1
       FROM JOB_HISTORY JH
       WHERE JH.EMPLOYEE_ID = E.EMPLOYEE_ID);

-- Employees with no JOB_HISTORY record.
SELECT E.EMPLOYEE_ID, E.LAST_NAME
FROM EMPLOYEES E
WHERE NOT EXISTS
      (SELECT 1
       FROM JOB_HISTORY JH
       WHERE JH.EMPLOYEE_ID = E.EMPLOYEE_ID);

-- Department-level existence check.
-- Departments containing at least one employee with job history.
SELECT D.DEPARTMENT_ID, D.DEPARTMENT_NAME
FROM DEPARTMENTS D
WHERE EXISTS
      (SELECT 1
       FROM EMPLOYEES E
       JOIN JOB_HISTORY JH
         ON JH.EMPLOYEE_ID = E.EMPLOYEE_ID
       WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID);

-- NULL trap:
-- NOT IN can return no rows if its subquery contains NULL.
-- Prefer correlated NOT EXISTS for "no related row" questions.
SELECT E.EMPLOYEE_ID, E.LAST_NAME
FROM EMPLOYEES E
WHERE NOT EXISTS
      (SELECT 1
       FROM JOB_HISTORY JH
       WHERE JH.EMPLOYEE_ID = E.EMPLOYEE_ID);


/*=============================================================================
6. ANY AND ALL
=============================================================================*/

-- Greater than at least one value returned by the subquery.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY > ANY
      (SELECT X.SALARY
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = 50);

-- Greater than every value returned by the subquery.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY > ALL
      (SELECT X.SALARY
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = 50);

-- Memory shortcuts for a non-empty subquery without problematic NULL values:
-- > ANY(values)  means > MIN(values)
-- > ALL(values)  means > MAX(values)
-- < ANY(values)  means < MAX(values)
-- < ALL(values)  means < MIN(values)
-- = ANY(values)  means IN(values)

-- Salary greater than the highest salary of at least one OTHER department.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY > ANY
      (SELECT MAX(X.SALARY)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID <> E.DEPARTMENT_ID
       GROUP BY X.DEPARTMENT_ID);


/*=============================================================================
7. "EVERY", "ALL MEMBERS", AND UNIVERSAL CONDITIONS
=============================================================================*/

-- Every employee in the department earns more than 5000.
-- Inner join means an empty department is not included.
SELECT D.DEPARTMENT_ID,
       D.DEPARTMENT_NAME,
       COUNT(*) AS EMP_COUNT
FROM DEPARTMENTS D
JOIN EMPLOYEES E
  ON E.DEPARTMENT_ID = D.DEPARTMENT_ID
GROUP BY D.DEPARTMENT_ID, D.DEPARTMENT_NAME
HAVING MIN(E.SALARY) > 5000;

-- General "every row satisfies condition" pattern.
-- Count of all rows must equal count of rows satisfying the condition.
SELECT E.DEPARTMENT_ID
FROM EMPLOYEES E
GROUP BY E.DEPARTMENT_ID
HAVING COUNT(*) = SUM(CASE WHEN E.SALARY > 5000 THEN 1 ELSE 0 END);

-- Same logic using double NOT EXISTS:
-- choose departments for which no violating employee exists.
SELECT D.DEPARTMENT_ID, D.DEPARTMENT_NAME
FROM DEPARTMENTS D
WHERE EXISTS
      (SELECT 1
       FROM EMPLOYEES E
       WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID)
  AND NOT EXISTS
      (SELECT 1
       FROM EMPLOYEES E
       WHERE E.DEPARTMENT_ID = D.DEPARTMENT_ID
         AND E.SALARY <= 5000);


/*=============================================================================
8. CASE AND CONDITIONAL AGGREGATION
=============================================================================*/

-- Searched CASE: first true WHEN wins.
SELECT E.EMPLOYEE_ID,
       E.SALARY,
       CASE
           WHEN E.SALARY > 15000 THEN 'Elite'
           WHEN E.SALARY > 10000 THEN 'High'
           ELSE 'Regular'
       END AS SALARY_LEVEL
FROM EMPLOYEES E;

-- Compare department average with company average.
SELECT E.DEPARTMENT_ID,
       ROUND(AVG(E.SALARY), 2) AS AVG_SALARY,
       CASE
           WHEN AVG(E.SALARY) > (SELECT AVG(X.SALARY) FROM EMPLOYEES X)
               THEN 'Above'
           ELSE 'Below or Equal'
       END AS SALARY_LEVEL
FROM EMPLOYEES E
GROUP BY E.DEPARTMENT_ID;

-- Conditional aggregation: count multiple categories in one query.
SELECT E.DEPARTMENT_ID,
       SUM(CASE WHEN E.SALARY > 10000 THEN 1 ELSE 0 END) AS HIGH_COUNT,
       SUM(CASE WHEN E.SALARY <= 10000 THEN 1 ELSE 0 END) AS OTHER_COUNT
FROM EMPLOYEES E
GROUP BY E.DEPARTMENT_ID;

-- Count with CASE. COUNT ignores NULL.
SELECT E.DEPARTMENT_ID,
       COUNT(CASE WHEN E.SALARY > 10000 THEN 1 END) AS HIGH_COUNT
FROM EMPLOYEES E
GROUP BY E.DEPARTMENT_ID;


/*=============================================================================
9. AND, OR, AND EXACTLY ONE CONDITION (XOR)
=============================================================================*/

-- OR: include a row when A, B, or both are true.
SELECT E.EMPLOYEE_ID, E.DEPARTMENT_ID, E.JOB_ID, E.SALARY
FROM EMPLOYEES E
JOIN JOBS J
  ON J.JOB_ID = E.JOB_ID
WHERE (SELECT COUNT(*)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID) > 5
   OR J.MIN_SALARY > 10000;

-- AND: both conditions must be true.
SELECT E.EMPLOYEE_ID, E.DEPARTMENT_ID, E.JOB_ID, E.SALARY
FROM EMPLOYEES E
JOIN JOBS J
  ON J.JOB_ID = E.JOB_ID
WHERE (SELECT COUNT(*)
       FROM EMPLOYEES X
       WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID) > 5
  AND J.MIN_SALARY > 10000;

-- XOR: exactly one is true; both true and both false are excluded.
-- Convert each Boolean condition to 1 or 0, then require total = 1.
SELECT E.EMPLOYEE_ID,
       E.FIRST_NAME || ' ' || E.LAST_NAME AS FULL_NAME,
       E.DEPARTMENT_ID,
       E.JOB_ID,
       E.SALARY
FROM EMPLOYEES E
JOIN JOBS J
  ON J.JOB_ID = E.JOB_ID
WHERE CASE
          WHEN (SELECT COUNT(*)
                FROM EMPLOYEES X
                WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID) > 5
          THEN 1 ELSE 0
      END
    + CASE
          WHEN J.MIN_SALARY > 10000
          THEN 1 ELSE 0
      END = 1;


/*=============================================================================
10. SET OPERATIONS
=============================================================================*/

-- Both SELECT statements must return the same number of compatible columns.
-- UNION: combine and remove duplicates.
SELECT E.EMPLOYEE_ID, E.JOB_ID
FROM EMPLOYEES E
UNION
SELECT JH.EMPLOYEE_ID, JH.JOB_ID
FROM JOB_HISTORY JH;

-- UNION ALL: combine and keep duplicates; usually faster.
SELECT E.EMPLOYEE_ID, E.JOB_ID
FROM EMPLOYEES E
UNION ALL
SELECT JH.EMPLOYEE_ID, JH.JOB_ID
FROM JOB_HISTORY JH;

-- INTERSECT: rows present in both results.
SELECT E.EMPLOYEE_ID, E.JOB_ID
FROM EMPLOYEES E
INTERSECT
SELECT JH.EMPLOYEE_ID, JH.JOB_ID
FROM JOB_HISTORY JH;

-- MINUS: rows in the first result but not the second result.
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
MINUS
SELECT JH.EMPLOYEE_ID
FROM JOB_HISTORY JH;

-- OR can often be expressed using UNION.
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.DEPARTMENT_ID = 50
UNION
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.SALARY > 10000;

-- AND can often be expressed using INTERSECT.
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.DEPARTMENT_ID = 50
INTERSECT
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.SALARY > 10000;

-- A but not B can often be expressed using MINUS.
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.DEPARTMENT_ID = 50
MINUS
SELECT E.EMPLOYEE_ID
FROM EMPLOYEES E
WHERE E.SALARY > 10000;

-- ORDER BY is written once at the end of the complete set expression.
SELECT E.EMPLOYEE_ID, E.JOB_ID
FROM EMPLOYEES E
UNION
SELECT JH.EMPLOYEE_ID, JH.JOB_ID
FROM JOB_HISTORY JH
ORDER BY 1, 2;


/*=============================================================================
11. WITH CLAUSE (CTE) - REUSABLE STATISTICS
=============================================================================*/

-- Department statistics used like a temporary table.
WITH DEPT_STATS AS
(
    SELECT E.DEPARTMENT_ID,
           COUNT(*) AS EMP_COUNT,
           AVG(E.SALARY) AS AVG_SALARY,
           MIN(E.SALARY) AS MIN_SALARY,
           MAX(E.SALARY) AS MAX_SALARY,
           AVG(MONTHS_BETWEEN(SYSDATE, E.HIRE_DATE) / 12) AS AVG_YEARS
    FROM EMPLOYEES E
    GROUP BY E.DEPARTMENT_ID
)
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME,
       E.SALARY,
       S.EMP_COUNT,
       ROUND(S.AVG_SALARY, 2) AS DEPT_AVG
FROM EMPLOYEES E
JOIN DEPT_STATS S
  ON S.DEPARTMENT_ID = E.DEPARTMENT_ID
WHERE E.SALARY > S.AVG_SALARY
  AND S.EMP_COUNT > 5;

-- Multiple CTEs: department, job, and company statistics.
WITH DEPT_STATS AS
(
    SELECT DEPARTMENT_ID,
           COUNT(*) AS EMP_COUNT,
           AVG(SALARY) AS AVG_SALARY,
           MAX(SALARY) AS MAX_SALARY
    FROM EMPLOYEES
    GROUP BY DEPARTMENT_ID
),
JOB_STATS AS
(
    SELECT JOB_ID,
           COUNT(*) AS EMP_COUNT,
           AVG(SALARY) AS AVG_SALARY,
           MAX(SALARY) AS MAX_SALARY
    FROM EMPLOYEES
    GROUP BY JOB_ID
),
COMPANY_STATS AS
(
    SELECT AVG(SALARY) AS AVG_SALARY
    FROM EMPLOYEES
)
SELECT E.EMPLOYEE_ID,
       E.LAST_NAME,
       E.SALARY,
       DS.AVG_SALARY AS DEPT_AVG,
       JS.AVG_SALARY AS JOB_AVG,
       CS.AVG_SALARY AS COMPANY_AVG
FROM EMPLOYEES E
JOIN DEPT_STATS DS
  ON DS.DEPARTMENT_ID = E.DEPARTMENT_ID
JOIN JOB_STATS JS
  ON JS.JOB_ID = E.JOB_ID
CROSS JOIN COMPANY_STATS CS;


/*=============================================================================
12. TOP-N AND RANKING PATTERNS
=============================================================================*/

-- Top 3 rows after sorting. Oracle 12c+.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.SALARY
FROM EMPLOYEES E
ORDER BY E.SALARY DESC
FETCH FIRST 3 ROWS ONLY;

-- Top 3 DISTINCT salary levels, including salary ties.
SELECT EMPLOYEE_ID, LAST_NAME, SALARY
FROM
(
    SELECT E.EMPLOYEE_ID,
           E.LAST_NAME,
           E.SALARY,
           DENSE_RANK() OVER (ORDER BY E.SALARY DESC) AS SALARY_RANK
    FROM EMPLOYEES E
)
WHERE SALARY_RANK <= 3
ORDER BY SALARY DESC;

-- Highest-paid employee(s) for every job.
SELECT E.EMPLOYEE_ID, E.LAST_NAME, E.JOB_ID, E.SALARY
FROM EMPLOYEES E
WHERE E.SALARY =
      (SELECT MAX(X.SALARY)
       FROM EMPLOYEES X
       WHERE X.JOB_ID = E.JOB_ID);

/*=============================================================================
13. EXTRA ORACLE OBJECTS: VIEW, SEQUENCE, AND INDEX
=============================================================================*/

-- Simple view.
CREATE OR REPLACE VIEW HIGH_SALARY_EMPLOYEES AS
SELECT EMPLOYEE_ID, FIRST_NAME, LAST_NAME, SALARY, DEPARTMENT_ID
FROM EMPLOYEES
WHERE SALARY > 10000;

-- Read-only view.
CREATE OR REPLACE VIEW DEPT_SALARY_SUMMARY AS
SELECT DEPARTMENT_ID,
       COUNT(*) AS EMP_COUNT,
       AVG(SALARY) AS AVG_SALARY
FROM EMPLOYEES
GROUP BY DEPARTMENT_ID
WITH READ ONLY;

-- Sequence for generating numeric IDs.
CREATE SEQUENCE TEST_EMP_SEQ
START WITH 1000
INCREMENT BY 1
NOCACHE
NOCYCLE;

-- NEXTVAL generates the next number; CURRVAL returns the current session value.
SELECT TEST_EMP_SEQ.NEXTVAL FROM DUAL;
SELECT TEST_EMP_SEQ.CURRVAL FROM DUAL;

-- Index. Do not create another index on a primary-key/unique column unnecessarily.
CREATE INDEX IDX_EMP_DEPT
ON EMPLOYEES(DEPARTMENT_ID);

-- Remove objects when explicitly required.
DROP VIEW HIGH_SALARY_EMPLOYEES;
DROP SEQUENCE TEST_EMP_SEQ;
DROP INDEX IDX_EMP_DEPT;


/*=============================================================================
14. DML USING SUBQUERIES
=============================================================================*/

-- Insert rows produced by a query.
INSERT INTO EMPLOYEE_BACKUP
       (EMPLOYEE_ID, FIRST_NAME, LAST_NAME, SALARY, DEPARTMENT_ID)
SELECT E.EMPLOYEE_ID,
       E.FIRST_NAME,
       E.LAST_NAME,
       E.SALARY,
       E.DEPARTMENT_ID
FROM EMPLOYEES E
WHERE E.SALARY > (SELECT AVG(X.SALARY) FROM EMPLOYEES X);

-- Update rows selected by a subquery.
UPDATE EMPLOYEES E
SET SALARY = E.SALARY * 1.10
WHERE E.DEPARTMENT_ID IN
      (SELECT X.DEPARTMENT_ID
       FROM EMPLOYEES X
       GROUP BY X.DEPARTMENT_ID
       HAVING AVG(X.SALARY) < 6000);

-- Correlated update: assign each row its department average.
-- Run only on a practice copy, not on the original HR table.
UPDATE EMPLOYEE_COPY E
SET SALARY =
    (SELECT AVG(X.SALARY)
     FROM EMPLOYEE_COPY X
     WHERE X.DEPARTMENT_ID = E.DEPARTMENT_ID)
WHERE E.DEPARTMENT_ID IS NOT NULL;

-- Delete employees having no job-history record from a practice table.
DELETE FROM EMPLOYEE_COPY E
WHERE NOT EXISTS
      (SELECT 1
       FROM JOB_HISTORY JH
       WHERE JH.EMPLOYEE_ID = E.EMPLOYEE_ID);

-- Transaction control.
COMMIT;
ROLLBACK;


/*=============================================================================
15. LEETCODE MYSQL -> ORACLE QUICK CONVERSION
=============================================================================*/

-- MySQL LIMIT 1 OFFSET 1
-- Oracle 12c+: OFFSET 1 ROW FETCH NEXT 1 ROW ONLY
SELECT DISTINCT E.SALARY
FROM EMPLOYEES E
ORDER BY E.SALARY DESC
OFFSET 1 ROW FETCH NEXT 1 ROW ONLY;

-- MySQL IFNULL(value, replacement) -> Oracle NVL(value, replacement)
SELECT NVL(E.COMMISSION_PCT, 0) AS COMMISSION
FROM EMPLOYEES E;

-- MySQL CONCAT(a, b, c) -> Oracle a || b || c
SELECT E.FIRST_NAME || ' ' || E.LAST_NAME AS FULL_NAME
FROM EMPLOYEES E;

-- MySQL YEAR(date_col) -> Oracle EXTRACT(YEAR FROM date_col)
SELECT EXTRACT(YEAR FROM E.HIRE_DATE) AS HIRE_YEAR
FROM EMPLOYEES E;

-- MySQL DATEDIFF(date1, date2) -> Oracle date1 - date2, in days.
SELECT TRUNC(SYSDATE - E.HIRE_DATE) AS DAYS_WORKED
FROM EMPLOYEES E;

-- MySQL boolean IF(condition, a, b) -> Oracle CASE.
SELECT E.SALARY,
       CASE WHEN E.SALARY > 10000 THEN 'High' ELSE 'Regular' END AS CATEGORY
FROM EMPLOYEES E;


/*=============================================================================
16. FAST QUESTION-TO-SQL DECISION GUIDE
=============================================================================*/

-- "Show department/job/location name"       -> JOIN the required table.
-- "His/her manager"                         -> self JOIN EMPLOYEES.
-- "Above department average"                -> correlated AVG subquery.
-- "Department has more than N employees"    -> COUNT(*) correlated or HAVING.
-- "No history / no related row"             -> NOT EXISTS.
-- "Has a manager/history/related row"        -> EXISTS.
-- "At least one returned value"              -> ANY or EXISTS.
-- "Greater than everybody"                   -> > ALL or > MAX.
-- "Every employee satisfies..."              -> HAVING MIN(...) or NOT EXISTS violation.
-- "Exactly one of A/B"                       -> CASE(A)+CASE(B)=1.
-- "Combine two result sets"                  -> UNION / UNION ALL.
-- "Common to both result sets"               -> INTERSECT.
-- "First result excluding second"            -> MINUS.
-- "Reuse calculated statistics"              -> WITH clause / FROM subquery.
-- "Output a label"                           -> CASE in SELECT.
-- "Filter individual rows"                   -> WHERE.
-- "Filter aggregate groups"                  -> HAVING.


/*=============================================================================
17. FINAL ERROR CHECKLIST
=============================================================================*/

-- 1. ORA-00979: selected non-aggregate column is missing from GROUP BY.
-- 2. ORA-01427: scalar subquery returned multiple rows; use IN/ANY/ALL or fix it.
-- 3. Missing join condition causes a Cartesian product and duplicate-looking rows.
-- 4. = NULL is wrong; use IS NULL or IS NOT NULL.
-- 5. NOT IN is dangerous when the subquery can return NULL; prefer NOT EXISTS.
-- 6. COUNT(column) ignores NULL; COUNT(*) counts rows.
-- 7. LEFT JOIN + condition on right table in WHERE may become an inner join.
-- 8. UNION branches need the same number of compatible columns.
-- 9. ORDER BY goes at the end of a set-operation query.
-- 10. CASE returns one value; it does not filter rows unless used in a condition.
-- 11. A correlated subquery must connect inner alias to outer alias.
-- 12. Use DISTINCT only when duplicate removal is logically required.
-- 13. Use MONTHS_BETWEEN(SYSDATE, HIRE_DATE) / 12 for years in Oracle.
-- 14. Verify > versus >= and "more than N" versus "at least N".
-- 15. Before UPDATE or DELETE, run the same WHERE clause with SELECT first.