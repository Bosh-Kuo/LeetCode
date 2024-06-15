# Write your MySQL query statement below
SELECT employee_id
FROM Employees as E
WHERE E.employee_id not in (SELECT employee_id FROM Salaries)
UNION
SELECT employee_id
FROM Salaries as S
WHERE S.employee_id not in (SELECT employee_id FROM Employees)
ORDER BY employee_id