# Write your MySQL query statement below
SELECT id, 'Root' as type
FROM Tree
WHERE p_id is NULL
UNION
SELECT id, 'Inner' as type
FROM Tree as T1
WHERE T1.p_id is Not NULL AND T1.id in (SELECT p_id FROM Tree as T2 WHERE T2.p_id is Not NULL)
UNION
SELECT id, 'Leaf' as type
FROM Tree as T1
WHERE T1.p_id is Not NULL AND T1.id not in (SELECT p_id FROM Tree as T2 WHERE T2.p_id is Not NULL)
