# Write your MySQL query statement below
SELECT MAX(salary) as SecondHighestSalary
FROM Employee
WHERE salary not in (SELECT MAX(salary) FROM Employee)