# Write your MySQL query statement below
SELECT D.name as Department, E.name as Employee, salary as Salary
FROM Employee as E, Department as D
WHERE E.departmentId = D.id AND 
    3 >
    (SELECT COUNT(DISTINCT E2.salary)
     FROM Employee as E2 
     WHERE E.salary < E2.salary AND E.departmentId = E2.departmentId)
