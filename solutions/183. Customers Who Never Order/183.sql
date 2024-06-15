# Write your MySQL query statement below
SELECT name as 'Customers'
FROM Customers as C 
WHERE C.id not in (SELECT customerId From Orders)