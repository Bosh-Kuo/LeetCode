# Write your MySQL query statement below
SELECT employee_id, salary as 'bonus'
FROM Employees
WHERE employee_id % 2 <> 0 AND name not like 'M%'
UNION
SELECT employee_id, 0 as 'bonus'
FROM Employees
WHERE employee_id % 2 = 0 OR name like 'M%'
ORDER BY employee_id
