# Write your MySQL query statement below
UPDATE Salary
SET sex = 
CASE sex 
    When 'm' THEN 'f'
    ELSE 'm'
END
