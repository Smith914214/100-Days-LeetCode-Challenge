# Write your MySQL query statement below
SELECT name
FROM employee e
JOIN (
    SELECT managerId
    FROM employee
    WHERE managerId IS NOT NULL
    GROUP BY managerId
    HAVING COUNT(managerId)>=5 
) m
    ON e.id=m.managerId