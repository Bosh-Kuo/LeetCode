# Write your MySQL query statement below
SELECT
ROUND(COUNT(A1.player_id)/(SELECT COUNT(DISTINCT player_id) FROM Activity), 2) as fraction
FROM Activity as A1
WHERE
    (A1.player_id, DATE_SUB(A1.event_date, INTERVAL 1 DAY)) IN (
        SELECT A2.player_id, MIN(A2.event_date)
        FROM Activity as A2
        GROUP BY A2.player_id
    );