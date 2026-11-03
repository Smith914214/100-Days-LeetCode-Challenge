# Write your MySQL query statement below

SELECT Class
FROM courses
GROUP BY class
Having COUNT(class) >= 5